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
	int event_id = 0;

	if (file_length > 0) {
		while (valid_position) {
			Event e;
			valid_position = f_utils.read_bin(EVENT_FILE_DIR, e, read_start);

			if (valid_position) {
				e.set_id(event_id);
				e_book.push_back(e);
			}
			
			event_id++;
			read_start += sizeof(Event);
		}
	}
	
}

void Event_Manager::create_event(const char* name, const char* desc, const char* date, int id) {
	std::cout << "Creating event " << std::endl;

	e_book.push_back(Event(name, desc, date, id));
}

void Event_Manager::modify_event(ATTRIBUTE ATTR, const char* _mod, int event_index) {
	
	e_book.at(event_index).mod_attr(ATTR, _mod);
}

Event Event_Manager::get_event(int e_index) {
	return e_book.at(e_index);
}

std::vector<Event> Event_Manager::get_event_book() {
	return e_book;
}

DATE_INPUT_STATE Event_Manager::user_date_search(std::string& date_of_event, std::vector<Event>& matches) {
	try {
		matches = events_with_date(this, date_of_event.c_str());

		if (matches.size() > 0) {

		}
		else {
			return DATE_NOT_FOUND;
		}

		return DATE_OK;
	}
	catch (DATE_INPUT_STATE v) {
		return INVALID_DATE;
	}
}

void Event_Manager::save_to_file() {

	File_Utils<Event> f_utils;

	for (int i = 0; i < e_book.size(); i++) {
		if (i == 0) {
			f_utils.write_bin(EVENT_FILE_DIR, e_book.at(i), OVERWRITE);
		}
		else {
			f_utils.write_bin(EVENT_FILE_DIR, e_book.at(i), APPEND);
		}
	}
}

Event_Manager::~Event_Manager()
{
}
