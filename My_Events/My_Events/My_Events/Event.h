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
	Event(const char* name, const char* desc, const char* date, int id);
	Event();
	~Event();

	const char* getDescription();
	const char* getDate();
	const char* getName();
	int get_id();

	void set_description(const char* desc);
	void set_date(const char* date);
	void set_name(const char* name);
	void set_id(int id);

	void mod_attr(ATTRIBUTE ATTR, const char* _mod);

private:
	char e_name[120];
	char e_desc[255];
	char e_date[32];
	int event_id;
};

