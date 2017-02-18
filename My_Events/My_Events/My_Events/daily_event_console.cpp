#include "daily_event_console.h"

Daily_Event_Console::Daily_Event_Console() : MAX_CHOICES(6) {

}

Daily_Event_Console::~Daily_Event_Console() {

}

void Daily_Event_Console::init_program() {

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
			change_event(MODIFY);
		case 3:
			change_event(REMOVE);
			break;
		case 4:
			view_all_events_console();
			break;
		case 5:
			//save and exit
			e_man.save_to_file();
			break;
		case 6:
			//save and continue
			e_man.save_to_file();
			init_program();
			break;
		default:
			std::cout << "Wrong value was entered.." << std::endl;
		}
	}
}

void Daily_Event_Console::create_event() {
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

	date = get_console_date_input();

	e_man.create_event(name.c_str(), desc.c_str(), date.c_str(), e_man.get_event_book().size());

	prompt_another_event();
}

void Daily_Event_Console::prompt_another_event() {
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

void Daily_Event_Console::change_event(CHANGE_TYPE change) {
	string date_of_event;
	std::vector<Event> matches;
	DATE_INPUT_STATE dis;
	int event_index;

	std::cout << "Do you know the date of the event?" << std::endl;
	std::cout << "1. Yes" << std::endl;
	std::cout << "2. No" << std::endl;
	std::cin >> choice;

	system("cls");

	switch (choice) {
	case 1:

		std::cin.clear();
		std::cin.sync();
		std::cin.ignore();
		
		date_of_event = get_console_date_input();

		//Fill matches with events that much the search query
		dis = e_man.user_date_search(date_of_event, matches);

		if (dis == DATE_OK) {

			//Show the user the Events in matches and retreive their input for which event to modify
			//We also pass date_of_event to tell the user what their search parameters were
			event_index = select_event_to_modify(date_of_event, matches);

			switch (change) {
			case MODIFY:
				do_modification(event_index);
			case REMOVE:
				do_remove(event_index);
			}
			
			//Save change to file
			e_man.save_to_file();
		}
		else if (dis == DATE_NOT_FOUND) {
			std::cout << "Date not found" << std::endl;
		}

	case 2:
		break;
	}

	init_program();
}

int Daily_Event_Console::select_event_to_modify(string date_of_event, std::vector<Event> matches) {
	int event_index;

	std::cout << "--**Select the correct event from the events below**--" << std::endl;
	std::cout << "Found " << matches.size() << " events with a date of " << date_of_event << std::endl;
	for (int i = 0; i < matches.size(); i++) {
		std::cout << matches.at(i).get_id() << " " << matches[i].getName() << std::endl;
		std::cout << std::endl;
	}
	std::cin >> event_index;

	return event_index;
}

ATTRIBUTE Daily_Event_Console::get_attr_to_mod() {
	int attr_to_mod;

	std::cout << "What part of the event do you want to modify?" << std::endl;
	std::cout << "0. Name" << std::endl;
	std::cout << "1. Description" << std::endl;
	std::cout << "2. Date" << std::endl;
	std::cin >> attr_to_mod;
	ATTRIBUTE ATTR = (ATTRIBUTE)attr_to_mod;

	return ATTR;
}

void Daily_Event_Console::do_modification(int event_index) {

	string _mod;

	ATTRIBUTE ATTR = get_attr_to_mod();
	std::cout << "Enter the new " << ATTR << ": ";

	std::cin.clear();
	std::cin.sync();
	std::cin.ignore();

	std::getline(std::cin, _mod);

	e_man.modify_event(ATTR, _mod.c_str(), event_index);
}

void Daily_Event_Console::do_remove(int event_index) {
	e_man.remove_event(event_index);
}

void Daily_Event_Console::view_all_events_console() {

	system("cls");

	std::vector<Event> e_book = e_man.get_event_book();

	std::cout << e_book.size() << std::endl;

	for (int i = 0; i < e_book.size(); i++) {

		std::cout << "Event name:        " << e_book.at(i).getName() << std::endl;
		std::cout << "Event description: " << e_book.at(i).getDescription() << std::endl;
		std::cout << "Event date:        " << e_book.at(i).getDate() << std::endl;
		std::cout << std::endl;

	}

	system("PAUSE");

	init_program();
}

std::string Daily_Event_Console::get_console_date_input() {

	std::string date;

	bool date_valid = false;

	do {

		std::cout << "Enter date: ";
		std::getline(std::cin, date);
		std::cout << std::endl;

		if (valid_date(date)) {

			system("cls");

			date_valid = true;

		}
		else {
			//If the user input for date is invalid, clear the console, show the user the correct
			//format for dates
			system("cls");
			print_date_format_error();
			date_valid = false;
		}

	} while (!date_valid);

	return date;
}

void Daily_Event_Console::print_date_format_error() {
	system("cls");
	std::cout << "Date format should be mm/dd/yyyy, please re-enter the date." << std::endl;
}