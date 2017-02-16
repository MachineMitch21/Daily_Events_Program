#pragma once
#include "Event.h"
#include "File_Utils.h"
#include "Event_Seach.h"
#include <string>
#include <vector>

class Event_Manager
{
public:
	Event_Manager();
	~Event_Manager();

	void create_event(const char* name, const char* desc, const char* date, int id);
	void modify_event(ATTRIBUTE ATTR, const char* _mod, int event_index);
	Event get_event(int e_index);
	std::vector<Event> get_event_book();

	//User searches for the event to modify and if the search fails for any reason, returns false
	DATE_INPUT_STATE user_date_search(std::string& date_of_event, std::vector<Event>& matches);

	void save_to_file();

private:
	std::vector<Event> e_book;
};

