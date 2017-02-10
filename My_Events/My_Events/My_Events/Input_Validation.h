#pragma once
#include <string>
#define DATE_MIN_LENGTH 8

enum DATE_INPUT_STATE {
	DATE_OK,
	INVALID_DATE,
	DATE_NOT_FOUND
};

bool valid_date(std::string date) {
	//If the length of the date passed in is less than DATE_MIN_LENGTH characters in length, go ahead and return false.
	//Otherwise, out of range errors will be thrown by string class
	if (date.length() < DATE_MIN_LENGTH) {
		return false;
	}
        //Are the first two characters in the string:date are digits?
	else if (isdigit(date.at(0)) && isdigit(date.at(1))) {
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
