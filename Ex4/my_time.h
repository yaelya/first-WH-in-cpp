#include <string>
#include <iomanip>
#include <stdexcept>
#include <bitset> 
void print(const Time time);
class Time
{
	public:
		static const int MY_HOURS;
		static const int MY_SECONDE;


		Time(int hours, int minutes, int seconds);
		Time(int totalSeconds);
		std::string get_as_str(bool) const;
		int get_seconds();

		Time operator+(Time & time);
		Time operator+(unsigned long);
		bool operator==(Time & time);
		bool operator!=(Time & time);
		bool operator<(Time & time);
		bool operator<=(Time & time);
		bool operator>(Time & time);
		bool operator>=(Time & time);

		std::ostream& operator<<(ostream & stream, Time& time);
		void getsChars(char, char);
		void time_reset(Time & reset_time);

};