#include "my_timer.h" 
#include <iostream>

using namespace std;

class Timer{
public:
	Time target;
	Time clock;
	MsgPrinter pprinter;

	Timer::Timer(Time target, MsgPrinter pointer)
	{
		this->target = target;
		this->pprinter = pointer;
		this->clock = 0;
	}
	inline void Timer::tick(void)
	{
		clock += 1;
		if (clock == target || clock > target)
		{
			pprinter->print();
		}
	}
	inline void Timer::tick(unsigned int number)
	{
		clock += number;
		if (clock == target || clock > target)
		{
			pprinter->print();
		}
	}
	inline void Timer::tick(std::string s) throw (const char*)
	{
		if (s == "M" || s == "m" || s == "Min" || s == "min" || s == "Minute" || s == "minute")
		{
			clock += clock.get_ONE_MINUE();
			cout << "add m: " << clock << endl;
		}
		else if (s == "H" || s == "h" || s == "Hour" || s == "hour")
		{
			clock += clock.get_ONE_MINUE()*clock.get_ONE_MINUE();
			cout << "add h: " << clock << endl;
		}
		else
		{
			cout << "Invalid string" << endl;
		}
		if (clock == target || clock > target)
		{
			pprinter->print();
		}
	}
	inline void Timer::tick(std::string s, unsigned int number) throw (const char*)
	{
		if (s == "M" || s == "m" || s == "Min" || s == "min" || s == "Minute" || s == "minute")
		{
			clock += number * clock.get_ONE_MINUE();
		}
		else if (s == "H" || s == "h" || s == "Hour" || s == "hour")
		{
			clock += number * clock.get_ONE_MINUE()*clock.get_ONE_MINUE();
		}
		else
		{
			cout << "Invalid string" << endl;
		}
		if (clock == target || clock > target)
		{
			pprinter->print();
		}
	}
	void run_timer_1() {//defin an timer 
		Time time(1, 30); 
		MsgPrinter msgP("Hello World! ")
		int counter = 0;
		Timer timer(time, &msgP);
		while (counter<50)
		{
			cuot << i + 1 << endl;
			timer.tick("MIN", 2);
			counter++;
		}
	}
	void run_timer_2() {//timer 7 sec
		Time time(7);
		MsgPrinter msgP("Seven Seconds");
		Timer timer(time, &msgP);
		int counter = 0;
		while (counter < 10)
		{
			Sleep(1000);
			cuot << i + 1 << endl;
			timer.tick();
			counter++;
		}
	}

	void run_timer_3() {
		MsgPrinter *printers[3];
		printers[0] = new MsgPrinter{ "This is the message" };
		printers[1] = new MsgPrinterSurrounding{ "Surrounded","---Start---","----End----" };
		MsgPrinterMultipleSorrounding * msgMS = new MsgPrinterMultipleSorrounding("Really Surrounded", ">>>>>>>", "<<<<<<<");
		msgMS->set_times(3);
		printers[2] = msgMS;
		Timer timer1(10, printers[0]);
		Timer timer2(15, printers[1]);
		Timer timer3(20, printers[1]);
		Timer timer4(25, printers[2]);
		Timer timer5(30, printers[2]);
		int i;
		for (i = 0; i < 40; i++) {
			cout << i + 1 << endl;
			timer1.tick();
			timer2.tick();
			timer3.tick();
			timer4.tick();
			timer5.tick();
		}
		for (i = 0; i < 3; i++) {
			delete(printers[i]);
			printers[i] = NULL;
		}
	}
	void run_timer_4() {//using list
		MsgPrinter *printers[3];
		printers[0] = new MsgPrinter{ "This is the message" };
		printers[1] = new MsgPrinterSurrounding{ "Surrounded","---Start---","----End----" };
		MsgPrinterMultipleSorrounding * msgMS = new MsgPrinterMultipleSorrounding("Really Surrounded", ">>>>>>>", "<<<<<<<");
		msgMS->set_times(3);
		printers[2] = msgMS;

		std::list<Timer> timers_list{ Timer(10, printers[0]),
			Timer(15, printers[1]),Timer(20, printers[1]),Timer(25, printers[2]),Timer(30, printers[2]) };;
		std::list<Timer>::iterator ptr;
		for (i = 0; i < 80; i++) {
			cout << i + 1 << endl;
			for (ptr = timers_list.begin(); ptr != timers_list.end(); ptr++) {//ran on the list
				ptr->tick();
			}
		}
		for (i = 0; i < 3; i++) {
			delete(printers[i]);
			printers[i] = NULL;
		}

	}
		


	

};