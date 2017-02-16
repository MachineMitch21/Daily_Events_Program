#pragma once
#include <vector>
#include "Input_Validation.h"
#include "Event.h"

//Throws an INVALID_DATE exception that must be caught for proper error handling
std::vector<Event> events_with_date(std::vector<Event> e_book, const char* date);
