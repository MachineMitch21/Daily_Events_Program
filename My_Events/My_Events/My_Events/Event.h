#pragma once
#include <string.h>

enum ATTRIBUTE {
	NAME,
	DESCRIPTION,
	DATE
};

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

	void mod_attr(ATTRIBUTE ATTR, const char* _mod);

private:
	char e_name[120];
	char e_desc[255];
	char e_date[32];
};

