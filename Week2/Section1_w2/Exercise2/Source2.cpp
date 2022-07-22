/*
* Exercise 2 - Military Clock
* Create a class called MilitaryClock that stores and displays the military time.

* Your class should contain the following constructors and methods:
* MilitaryClock();
* MilitaryClock(short hours, short minutes);
* void SetTime(short hours, short minutes);
* void DisplayTime();
*/

#include <iostream>
#include <string>

class FMilitaryClock
{
public:
	std::string Time;
	std::string HoursText;
	std::string MinutesText;
	
	FMilitaryClock()
	{
		Time = "0000";
	}

	FMilitaryClock(short hours, short minutes)
	{
		SetTime(hours, minutes);
	}

	void SetTime(short hours, short minutes)
	{
		if (hours < 10)
		{
			HoursText = "0" + std::to_string(hours);
		}
		else
		{
			HoursText = std::to_string(hours);
		}

		if (minutes < 10)
		{
			MinutesText = "0" + std::to_string(minutes);
		}
		else
		{
			MinutesText = std::to_string(minutes);
		}

		Time = HoursText + MinutesText;
	}

	void DisplayTime()
	{
		std::cout << "Time: " << Time << std::endl;
	}
};

int main()
{
	FMilitaryClock clock;
	clock.DisplayTime();
	clock = FMilitaryClock(7, 0);
	clock.DisplayTime();
	clock.SetTime(12, 15);
	clock.DisplayTime();
}