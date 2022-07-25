/*
* Exercise 2 - Military Clock
* Create a class called MilitaryClock that stores and displays the military time.

* Your class should contain the following constructors and methods:
* MilitaryClock();
* MilitaryClock(short NewHours, short NewMinutes);
* void SetTime(short NewHours, short NewMinutes);
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

	FMilitaryClock(short NewHours, short NewMinutes)
	{
		SetTime(NewHours, NewMinutes);
	}

	void SetTime(short NewHours, short NewMinutes)
	{
		if (NewHours < 10)
		{
			HoursText = "0" + std::to_string(NewHours);
		}
		else
		{
			HoursText = std::to_string(NewHours);
		}

		if (NewMinutes < 10)
		{
			MinutesText = "0" + std::to_string(NewMinutes);
		}
		else
		{
			MinutesText = std::to_string(NewMinutes);
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