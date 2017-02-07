#pragma once
#include <string>

bool valid_date(std::string date) {
        //Are the first two characters in the string:date are digits?
	if (isdigit(date.at(0)) && isdigit(date.at(1))) {
		if (date.at(2) == '/') {
			if (isdigit(date.at(3)) && isdigit(date.at(4))) {
				if (date.at(5) == '/') {
					for (int i = 6; i < date.size(); i++) {
						if (!isdigit(date.at(i))) {
							return false;
						}
					}

					return true;
				}
				else {
					return false;
				}
			}
			else if (date.at(4) == '/') {
				for (int i = 5; i < date.size(); i++) {
					if (!isdigit(date.at(i))) {
						return false;
					}
				}

				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	//The first two characters in date were not digits, is the second character a 
	//forward slash, indicating the end of the month section of the date?
	else if (date.at(1) == '/') {
		if (isdigit(date.at(2)) && isdigit(date.at(3))) {
			if (date.at(4) == '/') {
				for (int i = 5; i < date.size(); i++) {
					if (!isdigit(date.at(i))) {
						return false;
					}
				}

				return true;
			}
			else {
				return false;
			}
		}
		else if (date.at(3) == '/') {
			for (int i = 4; i < date.size(); i++) {
				if (!isdigit(date.at(i))) {
					return false;
				}
			}
			
			return true;
		}
		else {
			return false;
		}
	}
	//The first two characters were not valid for the date format of mm/dd/yyyy
	//return false because validation failed
	else {
		return false;
	}
}
