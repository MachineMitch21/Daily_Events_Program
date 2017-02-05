// My_Events.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Event_Manager.h"
#include "File_Utils.h"
#include <string>

using std::string;

void introduction();
void init_program();
void create_event();
void remove_event();
void save_and_quit();
void save_and_continue();
void prompt_another_event();
void view_all_events();

Event_Manager e_man;
File_Utils<Event> f_utils;
int choice = 0;
int pass;

int main()
{
	introduction();

    return 0;
}

void introduction() {
	//std::cout << e_man.get_event_book().at(0).getName() << std::endl;

	std::cout << "Hello, I will help you with your daily events!" << std::endl;
	std::cout << "This is to test github i guess" << std::endl;
	std::cout << "I am also testing Github." << std::endl;
	std::cout << "And here we go again" << std::endl;
	std::cout << "And yet again.." << std::endl;
	init_program();
}

void init_program() {

	if (pass >= 1) {
		system("cls");
	}
	else {
		pass++;
	}

	std::cout << "What would you like to do?" << std::endl;
	std::cout << "1. Create Event." << std::endl;
	std::cout << "2. Remove Event." << std::endl;
	std::cout << "3. View Events." << std::endl;
	std::cout << "4. Save & Exit" << std::endl;
	std::cout << "5. Save & Continue" << std::endl;
	std::cin >> choice;

	if (choice > 5 || choice < 1) {
		system("cls");
		std::cout << "Input must be 1, 2, 3, 4 or 5" << std::endl;
		std::cout << std::endl;
		init_program();
	}
	else {
		system("cls");

		switch (choice) {
		case 1:
			create_event();
			break;
		case 2:
			remove_event();
			break;
		case 3:
			view_all_events();
			break;
		case 4:
			save_and_quit();
			break;
		case 5:
			save_and_continue();
			break;
		default:
			std::cout << "Wrong value was entered.." << std::endl;
		}
	}
}

void create_event() {
	system("cls");
	string name;
	string desc;
	string date;

	std::cout << "Event Name: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << std::endl;

	std::cout << "Enter description: ";
	std::cin.ignore();
	std::getline(std::cin, desc);
	std::cout << std::endl;

	std::cout << "Enter date: ";
	std::cin.ignore();
	std::getline(std::cin, date);
	std::cout << std::endl;

	e_man.create_event(name.c_str(), desc.c_str(), date.c_str());

	system("cls");

	prompt_another_event();
}

void prompt_another_event() {
	std::cout << "--Create another event?--" << std::endl;
	std::cout << "1. Yes" << std::endl;
	std::cout << "2. No" << std::endl;
	std::cin >> choice;

	switch (choice) {
	case 1:
		create_event();
		break;
	case 2:
		init_program();
		break;
	default:
		system("cls");
		std::cout << "Input must be 1 or 2" << std::endl;
		prompt_another_event();
	}
}

void remove_event() {

}

void save_and_quit() {
	std::cout << "EventBook size is: " << e_man.get_event_book().size() << std::endl;
	for (int i = 0; i < e_man.get_event_book().size(); i++) {
		if (i == 0) {
			f_utils.write_bin(EVENT_FILE_DIR, e_man.get_event_book().at(i), OVERWRITE);
		}
		else {
			f_utils.write_bin(EVENT_FILE_DIR, e_man.get_event_book().at(i), APPEND);
		}

	}
}

void save_and_continue() {

}

void view_all_events() {

	system("cls");

	std::vector<Event> e_book = e_man.get_event_book();

	std::cout << e_book.size() << std::endl;

	for (int i = 0; i < e_book.size(); i++) {

		std::cout << "Event name:        " << e_book.at(i).getName() << std::endl;
		std::cout << "Event description: " << e_book.at(i).getDescription() << std::endl;
		std::cout << "Event date:        " << e_book.at(i).getDate() << std::endl;

	}

	system("PAUSE");
}
