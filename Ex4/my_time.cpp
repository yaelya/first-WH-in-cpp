#include "my_time.h" 
#include <iostream>

using namespace std;
void print(const Time & time) {
	std::cout << "the hours:" << time.hours << "the minutes:" << time.minutes << "the seconds:" << time.seconds << endl;
}

class Time{
	public:
		static const int MY_HOURS = 24;
		static const int MY_SECONDE = 60;
		char Time::DAYS = '.';
		char Time::HSM = ':';

		int hours;
		int minutes;
		int seconds;

		Time::Time(int hours,int minutes,int seconds)
		{
			if (hours < 0 || hours>MY_HOURS || minutes < 0 || minutes>MY_SECONDE || seconds < 0 || seconds>MY_SECONDE)
				throw std::invalid_argument("Invalid syntax: the arguments is invalid.");
			else if (seconds == NULL)
				seconds = 0;
			else
			{
				this->hours = hours;
				this->minutes = minutes;
				this->seconds = seconds;
			}	
		}
		Time::Time(int totalSeconds)
		{
			if (totalSeconds < 0)
			{
				throw std::invalid_argument("Invalid syntax: the arguments is negative.");
			}
			seconds = totalSeconds % MY_SECONDE;
			minutes = totalSeconds / MY_SECONDE;
			hours = minutes / MY_SECONDE;
			if (minutes = MY_SECONDE)
			{
				minutes = 0;
				hours++;
			}
		}
		std::string get_as_str(bool is_using_days) const {
			std::ostringstream oss;
			if (!is_using_days)
			{
				oss << setw(2) << setbase('0') << hours << DAYS;
			}
			else
			{
				oss << hours/ MY_HOURS << HSM << setw(2) << setfill('0') << hours% MY_HOURS << HSM;

			}
			oss << setw(2) << setfill('0') << minutes << HSM << setw(2) << setfill('0') << seconds << endl;
			std::string var = oss.str();
			return var;

		}
	
		int Time::get_seconds()
		{
			return seconds + (hours * MY_SECONDE * MY_SECONDE) + (minutes * MY_SECONDE);
		}
		Time::Time operator+(Time & time) {
			Time totalTime;
			int Nseconds = time.seconds + seconds;
			int Nminutes = time.minutes + minutes;
			int Nhours = time.hours + hours;
			if (Nseconds > MY_SECONDE) {
				Nseconds = Nseconds - MY_SECONDE;
				Nminutes++;
			}
			if (Nminutes > MY_SECONDE) {
				Nminutes = Nminutes - MY_SECONDE;
				Nhours++;
			}
			Time totalTime= new Time(Nseconds, Nminutes, Nhours);
		}
		Time::Time operator+(unsigned long t) {
			seconds += t;
			if (seconds > MY_SECONDE) {
				seconds = seconds - MY_SECONDE;
				minutes++;
			}
			if (minutes > MY_SECONDE) {
				minutes = minutes - MY_SECONDE;
				hours++;
			}
			return Time(hours, minutes, seconds);
		}
		bool operator==(Time & time){
			int Nseconds = seconds - time.seconds;
			int Nminutes = minutes - time.minutes;
			int Nhours = hours - time.hours;
			if (Nseconds == 0 && Nminutes==0 && Nhours==0) {
				return true;
			}
			else {
				return false;
			}
		}
		bool operator!=(Time & time){
			int Nseconds = seconds - time.seconds;
			int Nminutes = minutes - time.minutes;
			int Nhours = hours - time.hours;
			if (Nseconds == 0 && Nminutes == 0 && Nhours == 0) {
				return false;
			}
			else {
				return true;
			}
		}		
		bool operator<(Time & time) {
			if (hours > time.hours)
				return true;
			if (seconds > time.seconds)
				return true;
			if (minutes > time.minutes)
				return true;
			return false;
		}
		bool operator<=(Time & time) {
			if (hours >= time.hours)
				return true;
				if (seconds >= time.seconds)
					return true;
			if (minutes >= time.minutes)
				return true;
			return false;
		}
		bool operator>(Time & time) {
			if (hours < time.hours)
				return true;
			if (seconds < time.seconds)
					return true;
			if (minutes < time.minutes)
				return true;
			return false;
		}
		bool operator>=(Time & time) {
			if (hours <= time.hours)
				return true;
				if (seconds <= time.seconds)
					return true;
			if (minutes <= time.minutes)
				return true;
			return false;
		}
		std::ostream& operator<<(ostream & stream, Time& time) {
				stream << time.get_as_str(true);
				return stream;
		}

		void getsChars(char days, char hsm) {
			if (isdigit(new_day) || isdigit(new_hms))
				throw "not valid: digit inserted instead of characters";
			DAYS = days;
			HSM = hsm;
		}
		void time_reset(Time & reset_time) {
				reset_time->hours = 0;
				reset_time->minutes = 0;
				reset_time->seconds = 0;
		}
};