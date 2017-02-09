// My_Events.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Event_Manager.h"
#include "File_Utils.h"
#include "Input_Validation.h"
#include "Event_Seach.h"
#include <string>

#define MAX_CHOICES 6

using std::string;

void introduction();
void init_program();
void create_event();
void modify_event();
void remove_event();
void save_to_file();
void prompt_another_event();
void view_all_events();
void print_date_format_error();

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
	std::cout << "2. Modify Event." << std::endl;
	std::cout << "3. Remove Event." << std::endl;
	std::cout << "4. View Events." << std::endl;
	std::cout << "5. Save & Exit" << std::endl;
	std::cout << "6. Save & Continue" << std::endl;
	std::cin >> choice;

	if (choice > MAX_CHOICES || choice < 1) {
		system("cls");
		std::cout << "Input must be between 1 and " << MAX_CHOICES << std::endl;
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
			modify_event();
		case 3:
			remove_event();
			break;
		case 4:
			view_all_events();
			break;
		case 5:
			//save and exit
			save_to_file();
			break;
		case 6:
			//save and continue
			save_to_file();
			init_program();
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
	std::getline(std::cin, desc);
	std::cout << std::endl;

	//This is a goto that is setup for if a user enters invalid date data
	DATE:

	std::cout << "Enter date: ";
	std::getline(std::cin, date);
	std::cout << std::endl;

	if (valid_date(date)) {
		
		e_man.create_event(name.c_str(), desc.c_str(), date.c_str());

		system("cls");

		prompt_another_event();

	}
	else {
		//If the user input for date is invalid, clear the console, show the user the correct
		//format for dates and goto DATE directly above where date input is gathered
		print_date_format_error();
		goto DATE;
	}
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

void modify_event() {
	int attr_to_mod;
	string date_of_event;
	string _mod;
	int event_index;

	std::cout << "Do you know the date of the event you want to modify?" << std::endl;
	std::cout << "1. Yes" << std::endl;
	std::cout << "2. No" << std::endl;
	std::cin >> choice;

	switch (choice) {
	case 1:
		
		MODIFICATION:

		std::cout << "Enter the date of the event: ";
		std::getline(std::cin, date_of_event);
		
		try {
			std::vector<Event> matches = events_with_date(e_man, date_of_event.c_str());

			std::cout << "--**Select the Event you want to modify**--" << std::endl;
			std::cout << matches.size() << std::endl;
			for (int i = 0; i < matches.size(); i++) {
				std::cout << i << " " << matches[i].getName() << std::endl;
				std::cout << std::endl;
			}

			std::cin >> event_index;

			std::cout << "What part of the event do you want to modify?" << std::endl;
			std::cout << "0. Name" << std::endl;
			std::cout << "1. Date" << std::endl;
			std::cout << "2. Description" << std::endl;
			std::cin >> attr_to_mod;
			ATTRIBUTE ATTR = (ATTRIBUTE)attr_to_mod;
			std::cout << std::endl;

			//Still need to overload ostream to print text equivalent of ATTRIBUTE
			std::cout << "Enter the new " << (ATTRIBUTE)attr_to_mod;
			std::getline(std::cin, _mod);

			e_man.modify_event(ATTR, _mod.c_str(), event_index);

			//Save the changes to disk
			save_to_file();
		}
		catch (VALIDATION_EXCEPTION v) {
			//if a validation error is thrown within events_with_date, go back to entering the date
			print_date_format_error();
			goto MODIFICATION;
		}
	}
}

void remove_event() {

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

	init_program();
}

void save_to_file() {
	for (int i = 0; i < e_man.get_event_book().size(); i++) {
		if (i == 0) {
			f_utils.write_bin(EVENT_FILE_DIR, e_man.get_event_book().at(i), OVERWRITE);
		}
		else {
			f_utils.write_bin(EVENT_FILE_DIR, e_man.get_event_book().at(i), APPEND);
		}
	}
}

void print_date_format_error() {
	system("cls");
	std::cout << "Date format should be mm/dd/yyyy, please re-enter the date." << std::endl;
}