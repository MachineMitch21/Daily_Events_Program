#pragma once

#include "Event_Manager.h"
#include "File_Utils.h"
#include "Input_Validation.h"
#include "Event_Seach.h"
#include <string>

#define MAX_CHOICES 6

using std::string;

class Daily_Event_Console {

public:
	void introduction();
	void init_program();
	void create_event();
	void modify_event();

	//User selects event to modify from search results stored in (matches) and the id of that event is returned
	int select_event_to_modify(string date_of_event, std::vector<Event> matches);

	//User selects the attribute that needs to be modified and it is returned
	ATTRIBUTE get_attr_to_mod();

	//User performs the actual modification
	void do_modification(int event_index);

	void remove_event();
	void prompt_another_event();
	void view_all_events_console();
	void print_date_format_error();


private:
	Event_Manager e_man;
	File_Utils<Event> f_utils;
	int choice = 0;
	int pass;


};



