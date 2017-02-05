#include "Event_Manager.h"

Event_Manager::Event_Manager()
{
	File_Utils<Event> f_utils;

	if (!f_utils.file_exists(EVENT_FILE_DIR)) {
		f_utils.create_file(EVENT_FILE_DIR);
	}
	
	bool valid_position = true;
	int read_start = 0;
	int file_length = f_utils.get_file_length(EVENT_FILE_DIR);

	if (file_length > 0) {
		while (valid_position) {
			Event e;
			valid_position = f_utils.read_bin(EVENT_FILE_DIR, e, read_start);

			if (valid_position) {
				e_book.push_back(e);
			}
			
			read_start += sizeof(Event);
		}
	}
	
}

void Event_Manager::create_event(const char* name, const char* desc, const char* date) {
	std::cout << "Creating event " << std::endl;

	e_book.push_back(Event(name, desc, date));
}

void Event_Manager::modify_event(const char* name, const char* _mod) {

}

Event Event_Manager::get_event(int e_index) {
	return e_book.at(e_index);
}

std::vector<Event>& Event_Manager::get_event_book() {
	return e_book;
}

Event_Manager::~Event_Manager()
{
}
