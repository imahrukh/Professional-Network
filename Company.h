#include<iostream>
#include<fstream>
#include"helper.h"
#include"Profile.h"

using namespace std;

class Company : public Profile
{
private:
	char* name;
	char* location;

public:
	Company()
	{
		name = nullptr;
		location = nullptr;
	}

	~Company()
	{
		delete[] name;
		name = nullptr;
		delete[] location;
		location = nullptr;
	}

	void getid()
	{
		char* id = new char;
		id = Profile::getID();
		return id;
	}

	void readData(ifstream& fr)
	{
		Profile::readData(fr);
		name = new char;
		fr >> name;
		location = bufferToChar(fr, '_', location);
	}

	void displayData()
	{
		Profile::displayData();
		cout << "\nName: " << name;
		cout << "\nLocation: " << location;
	}
};
