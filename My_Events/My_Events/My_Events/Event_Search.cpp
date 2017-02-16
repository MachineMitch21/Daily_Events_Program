#include "Event_Seach.h"

std::vector<Event> events_with_date(std::vector<Event> e_book, const char* date) {
	std::vector<Event> matches;

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