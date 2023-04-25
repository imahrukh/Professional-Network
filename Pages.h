#include<iostream>
#include<fstream>
#include"helper.h"
#include"Profile.h"

using namespace std;

class Pages : public Profile
{
private:
	char* title;

public:
	Pages()
	{
		title = nullptr;
	} 

	~Pages()
	{
		delete[] title;
		title = nullptr;
	}

	void readData(ifstream& fr)
	{
		Profile::readData(fr);
		title = bufferToChar(fr, '-', title);
	}

	void displayData()
	{
		Profile::displayData();
		cout << "\nDescription: " << title;
	}	
};