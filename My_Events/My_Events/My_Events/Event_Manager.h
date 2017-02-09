#pragma once
#include "Event.h"
#include "File_Utils.h"
#include <vector>

class Event_Manager
{
public:
	Event_Manager();
	~Event_Manager();

	void create_event(const char* name, const char* desc, const char* date);
	void modify_event(ATTRIBUTE ATTR, const char* _mod, int event_index);
	Event get_event(int e_index);
	std::vector<Event> get_event_book();

private:
	std::vector<Event> e_book;
};

