#pragma once
#include <string>
#include <iomanip>
#include <stdexcept>
#include <bitset> 

class MsgPrinter {
	const string MsgPrinter::MESSAGE;
public:
	MsgPrinter(string);
	void print();
	void::~print()
};
//---------------------------------------------
class MsgPrinterSurrounding: public MsgPrinter{
public:
	MsgPrinterSurrounding::MsgPrinterSurrounding(const string);
	MsgPrinterSurrounding::MsgPrinterSurrounding(const string , char* , char* );
	void print_before();
	void print_after();
	void print();
	~MsgPrinterSurrounding();//destructor
	MsgPrinterSurrounding::MsgPrinterSurrounding(const MsgPrinterSurrounding &m);// Copy constructor 
	MsgPrinterSurrounding& operator = (const MsgPrinterSurrounding &t)//Copy Assignment operator
};
//---------------------------------------------
class MsgPrinterMultipleSorrounding : public MsgPrinterSurrounding {
public:
	MsgPrinterMultipleSorrounding::MsgPrinterMultipleSorrounding(const string );
	MsgPrinterSurrounding::MsgPrinterSurrounding(const string , char* , char* );//constructor
	void set_times(unsigned char);
	int get_times() const {};
	void print_before();
	void print_after();
	~MsgPrinterMultipleSorrounding();//destructor

};