#pragma once
#include <string>

bool valid_date(std::string date) {

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
	else {
		return false;
	}
}