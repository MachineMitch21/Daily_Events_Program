#include "Event.h"

Event::Event(const char* name, const char* desc, const char* date, int id)
{
	set_name(name);
	set_description(desc);
	set_date(date);
	set_id(id);
}

Event::Event() {
}

const char* Event::getDescription() {
	return e_desc;
}

const char* Event::getDate() {
	return e_date;
}

const char* Event::getName() {
	return e_name;
}

int Event::get_id() {
	return event_id;
}

void Event::set_description(const char* desc) {
	strcpy(e_desc, desc);
}

void Event::set_date(const char* date) {
	strcpy(e_date, date);
}

void Event::set_name(const char* name) {
	strcpy(e_name, name);
}

void Event::set_id(int id) {
	event_id = id;
}

void Event::mod_attr(ATTRIBUTE ATTR, const char* _mod) {

	switch (ATTR) {
	case NAME:
		set_name(_mod);
		break;
	case DESCRIPTION:
		set_description(_mod);
		break;
	case DATE:
		set_date(_mod);
		break;
	}
}

std::ostream& operator<<(std::ostream& out, const ATTRIBUTE& ATTR) {

	switch (ATTR) {
	case NAME:
		out << "Name";
		break;
	case DESCRIPTION:
		out << "Description";
		break;
	case DATE:
		out << "Date";
		break;
	}

	return out;
}

Event::~Event()
{
}
