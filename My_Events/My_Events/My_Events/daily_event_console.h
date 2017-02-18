#pragma once

#include "Event_Manager.h"
#include "File_Utils.h"
#include "Input_Validation.h"
#include "Event_Seach.h"
#include <string>

using std::string;

enum CHANGE_TYPE {
	MODIFY, 
	REMOVE
};

class Daily_Event_Console {

public:
	Daily_Event_Console();
	~Daily_Event_Console();

	void init_program();
	void create_event();
	void change_event(CHANGE_TYPE change);

	//Reusable console input method with date error checking that iterates everytime a user enters
	//invalid date data and returns a valid date retreived from the user
	//NOTE: A VALID DATE DOES NOT MEAN AN EVENT EXISTS WITH THAT DATE, JUST SIMPLY THAT THE DATE IS FORMATTED CORRECTLY
	std::string get_console_date_input();

	//User selects event to modify from search results stored in (matches) and the id of that event is returned
	int select_event_to_modify(string date_of_event, std::vector<Event> matches);

	//User selects the attribute that needs to be modified and it is returned
	ATTRIBUTE get_attr_to_mod();

	//User performs the actual modification
	void do_modification(int event_index);

	void do_remove(int event_index);
	void prompt_another_event();
	void view_all_events_console();
	void print_date_format_error();


private:
	Event_Manager e_man;
	File_Utils<Event> f_utils;
	int choice = 0;
	int pass;
	const int MAX_CHOICES;

};



