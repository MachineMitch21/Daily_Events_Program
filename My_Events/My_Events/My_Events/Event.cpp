#include "Event.h"



Event::Event(const char* name, const char* desc, const char* date)
{
	strcpy(e_name, name);
	strcpy(e_desc, desc);
	strcpy(e_date, date);
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

void Event::set_description(const char* desc) {
	strcpy(e_desc, desc);
}

void Event::set_date(const char* date) {
	strcpy(e_date, date);
}

void Event::set_name(const char* name) {
	strcpy(e_name, name);
}

Event::~Event()
{
}
