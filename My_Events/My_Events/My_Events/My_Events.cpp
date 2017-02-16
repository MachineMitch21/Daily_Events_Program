// My_Events.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "daily_event_console.h"

void introduction();

int main()
{
	introduction();

    return 0;
}

void introduction() {
	//std::cout << e_man.get_event_book().at(0).getName() << std::endl;

	Daily_Event_Console dec;
	std::cout << "Hello, I will help you with your daily events!" << std::endl;
	dec.init_program();
}

