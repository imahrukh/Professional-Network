#include<fstream>
#include<iostream>

using namespace std;

class Profile
{
protected:
	char* id;

public:
	Profile()
	{
		id = new char;
		id = nullptr;
	}

	Profile(char* _id) :id(_id)
	{

	}

	~Profile()
	{
		delete[] id;
		id = nullptr;
	}

	void setId(char* id)
	{
		this->id = id;
	}

	void readData(ifstream &fr)
	{
		fr >> id;
	}

	void displayData()
	{
		cout << "ID: " << id;
	}

	char* getID()
	{
		return id;
	}

};
