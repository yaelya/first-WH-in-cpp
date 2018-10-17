#pragma once

#include <string>
#include <iomanip>
#include <stdexcept>
#include <bitset> 
#include "my_time.h" 
#include "msg_printer.h"
#include <Windows.h>
class Timer {
public:
	Timer(Time , MsgPrinter );
	inline void tick(void);
	inline void tick(unsigned int);
	inline void tick(std::string) throw (const char*);
	inline void tick(std::string, unsigned int) throw (const char*);
	void run_timer_1();
	void run_timer_2();
	void run_timer_3();
	void run_timer_4();

};