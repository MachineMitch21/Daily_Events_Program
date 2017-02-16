#pragma once
#include <string>
#define DATE_MIN_LENGTH 8

enum DATE_INPUT_STATE {
	DATE_OK,
	INVALID_DATE,
	DATE_NOT_FOUND
};

bool valid_date(std::string date);
