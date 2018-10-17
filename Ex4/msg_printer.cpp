#include "msg_printer.h" 
#include <iostream>
using namespace std;
//------------------------------------------------------class MsgPrinter
class MsgPrinter {
private:
	static const string MESSAGE;
public:
	MsgPrinter::MsgPrinter(string massage)//constructor
	{
		this->MESSAGE = massage;
	}
	virtual void print()
	{
		cout << "Message: " << MESSAGE <<endl;
	}
	void::~print()
	{
		cout << "End of MsgPrinter: " << MESSAGE << endl;
	}
};
//------------------------------------------------------class MsgPrinterSurrounding
class MsgPrinterSurrounding: public MsgPrinter{
public:
	char* before;
	char* after;
	MsgPrinterSurrounding::MsgPrinterSurrounding(const string massage)//constructor
	{
		super(massage);
		this->after = 0;
		this->before = 0;
	}
	MsgPrinterSurrounding::MsgPrinterSurrounding(const string massage,char* before_msg,char* after_msg)//constructor
	{
		super(massage);
		int length1 = strlen(before_msg);
		int length2 = strlen(after_msg);
		char* str1 = new char[length1];
		strcpy(str1, before_msg);
		char* str2 = new char[length2];
		strcpy(str2, after_msg);
	}
	virtual void print_before()
	{
		std::cout << "Message before: " << before << endl;
	}
	void print_after()
	{
		std::cout << "Message after: " << after << endl;
	}
	virtual void print() {
		print_before();
		print();
		print_after();
	}
	~MsgPrinterSurrounding()//destructor 
	{
		delete[] before;
		delete[] after;
		std::cout << "End of MsgPrinterSorrounding: "<< MESSAGE <<endl;
	}
	MsgPrinterSurrounding::MsgPrinterSurrounding(const MsgPrinterSurrounding &m)// Copy constructor 
	{
		after = m.after;
		before = m.before;
	}
	MsgPrinterSurrounding & operator = (const MsgPrinterSurrounding &t)//Copy Assignment operator
	{
		before = t.before;
		after = t.after;
		return *this;
	}
};
//------------------------------------------------------class MsgPrinterMultipleSorrounding
class MsgPrinterMultipleSorrounding : public MsgPrinterSurrounding {
public:
	unsigned char times;
	MsgPrinterMultipleSorrounding::MsgPrinterMultipleSorrounding(const string massage)//constructor
	{
		super(massage);
	}
	MsgPrinterSurrounding::MsgPrinterSurrounding(const string massage, char* before_msg, char* after_msg)//constructor
	{
		super(massage,before_msg,after_msg);
		this->times = 2;
	}
	void set_times(unsigned char times) {
		this->times = times;
	}
	int get_times() const {
		return times;
	}
	void print_before() {
		for (int i = 0; i < times; i++)
		{
			print_before();
		}
	}
	void print_after(){
		for (int i = 0; i < times; i++)
		{
			print_after();
		}
	}
	~MsgPrinterMultipleSorrounding()//destructor 
	{
		std::cout << "End of MsgPrinterMultipleSorrounding:” : " << MESSAGE << endl;
	}
};