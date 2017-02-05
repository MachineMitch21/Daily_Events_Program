#pragma once
#include <fstream>
#include <iostream>
#define EVENT_FILE_DIR "User_Files\\events.bin"

enum WRITE_MODE {
	APPEND,
	OVERWRITE
};

template<class T>
class File_Utils {

private:
	std::fstream file;

public:
	bool write_bin(const char* file_name, T t, WRITE_MODE write_mode);
	bool read_bin(const char* file_name, T& t, double read_start);
	int get_file_length(const char* file_name);
	bool create_file(const char* file_name);
	bool file_exists(const char* file_name);
};

template<class T>
bool File_Utils<T>::write_bin(const char* file_name, T t, WRITE_MODE write_mode) {

	switch (write_mode) {
	case APPEND:
		file.open(file_name, std::ios::out | std::ios::binary | std::ios::app);
		break;
	case OVERWRITE:
		file.open(file_name, std::ios::out | std::ios::binary | std::ios::trunc);
		break;
	}

	if (file.is_open()) {
		std::cout << "Opening file: " << file_name << std::endl;
		file.write((char*)&t, sizeof(T));
		//Print out the data in the buffer
		file.flush();
		file.close();
		std::cout << "File has been closed" << std::endl;
		return true;
	}
	else {
		std::cout << "Trouble opening a file for writing: " << file_name << std::endl;
		return false;
	}
}

template<class T>
bool File_Utils<T>::read_bin(const char* file_name, T& t, double read_start) {

	if (read_start >= get_file_length(file_name)) {
		return false;
	}
	else {
		file.open(file_name, std::ios::in | std::ios::binary);

		if (file.is_open()) {
			file.seekg(read_start);
			file.read((char*)&t, sizeof(T));
			//Also print buffer data
			file.flush();
			file.close();
			return true;
		}
		else {
			std::cout << "Trouble opening a file for reading: " << file_name << std::endl;
			return false;
		}
	}

}

template <class T>
int File_Utils<T>::get_file_length(const char* file_name) {
	int length = 0;
	std::ifstream file(file_name, std::ios::binary | std::ios::in);
	if (file.is_open()) {

		file.seekg(0, file.end);
		length = file.tellg();
		file.seekg(0, file.beg);

		file.close();

	}

	return length;
}

template <class T>
bool File_Utils<T>::create_file(const char* file_name) {

	std::ofstream file(file_name);

	if (!file_exists(file_name)) {
		if (file.is_open()) {
			std::cout << "--File created or already exists--" << std::endl;
			file.close();
			return true;
		}
		else {
			std::cout << "--Trouble creating file--" << std::endl;
			return false;
		}
	}
	else {
		std::cout << "--File exists--" << std::endl;
		return false;
	}
}

template<class T>
bool File_Utils<T>::file_exists(const char* file_name) {

	bool exists = false;
	std::ifstream file(file_name);
	if (file) {
		exists = true;
	}

	return exists;
}
