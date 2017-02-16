#pragma once
#include <vector>
#include "Event_Manager.h"
#include "Input_Validation.h"

//Throws an INVALID_DATE exception that must be caught for proper error handling
std::vector<Event> events_with_date(Event_Manager e_man, const char* date){
	std::vector<Event> matches;
	std::vector<Event> e_book = e_man.get_event_book();

	if (!valid_date(date)) {
		throw INVALID_DATE;
	}
	else {
		for (int i = 0; i < e_book.size(); i++) {
			if (strcmp(e_book.at(i).getDate(), date) == 0) {
				matches.push_back(e_book.at(i));
			}
		}
	}

	return matches;
}