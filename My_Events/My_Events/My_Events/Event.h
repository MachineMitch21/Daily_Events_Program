#pragma once
#include <string.h>

class Event
{
public:
	Event(const char* name, const char* desc, const char* date);
	Event();
	~Event();

	const char* getDescription();
	const char* getDate();
	const char* getName();

	void set_description(const char* desc);
	void set_date(const char* date);
	void set_name(const char* name);

private:
	char e_name[120];
	char e_desc[255];
	char e_date[32];
};

