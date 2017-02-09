#pragma once
#include <vector>
#include "Event_Manager.h"
#include "Input_Validation.h"

std::vector<Event> events_with_date(Event_Manager& e_man, const char* date){
	std::cout << "Date entered for search query " << date << std::endl;
	std::vector<Event> matches;
	std::vector<Event> e_book = e_man.get_event_book();

	if (!valid_date(date)) {
		throw INVALID_DATE;
	}
	else {
		for (int i = 0; i < e_book.size(); i++) {
			std::cout << "Event " << i << " date: " << e_book.at(i).getDate() << std::endl;
			if (strcmp(e_book.at(i).getDate(), date) == 0) {
				matches.push_back(e_book.at(i));
			}
		}
	}

	return matches;
}