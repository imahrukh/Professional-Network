#include<iostream>
#include<fstream>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date()
	{
		day = 0;
		month = 0;
		year = 0;
	}

	~Date()
	{
		day = 0;
		month = 0;
		year = 0;
	}

	void readData(ifstream& fr)
	{
		fr >> day;
		fr >> month;
		fr >> year;
	}

	void displayData()
	{
		cout << "\nDate: " << day << "/" << month << "/" << year;
	}

	bool checkDate(int d, int m, int y)
	{
		bool flag = false;
		if (y == year &&m ==month && d-1==day ||d==day)
		{
			flag = true;
		}
		return flag;
	}
};