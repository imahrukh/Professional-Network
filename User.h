#include<fstream>
#include<iostream>
#include"Profile.h"
#include"ProfessionalProfile.h"
#include"helper.h"

using namespace std;

class User: public Profile
{
private:
	char* firstName;
	char* lastName;
	char** connections;
	ProfessionalProfile info;
	static const int maxConnections = 50;
	int connectionsCount ;

public:
	User()
	{
		firstName = nullptr;
		lastName = nullptr;
		for (int i = 0; i < maxConnections; i++)
		{
			connections[i] = nullptr;
		}
		connections = nullptr;
		connectionsCount = 0;
	}

	~User()
	{
		delete[] firstName;
		delete[]lastName;
		for (int i = 0; i < connectionsCount; i++)
		{
			delete[]connections[i];
		}
		delete[]connections;
		
		firstName = nullptr;
		lastName = nullptr;
		connections = nullptr;
	}

	char** getSkills()
	{
		return(info.getSkills());
	}

	char* getconnection()
	{
		int i = 0;
		if (i < connectionsCount)
			return connections[i++];
		else
			return nullptr;
	}

	char* getId()
	{
		return Profile::id;
	}

	void readData(ifstream& fr)
	{
		id = new char;
		firstName = new char;
		lastName = new char;
		fr >> id;
		fr >> firstName;
		fr >> lastName;
		connections = bufferTo2dchar(fr, '-', ',', connections, connectionsCount);
		info.readData(fr);
	}

	void displayConnections()
	{
		cout << "\n Connections of "<<id<<" : ";
		for (int i = 0; i < connectionsCount; i++)
		{
			cout << connections[i] << " ";
		}
		info.displayData();
	}

	void searchWord(char key)
	{
		int i = 0;
		bool check = false;
		while (firstName[i] != '\0'|| lastName[i]!='\0')
		{
			if (firstName[i] == word || lastName[i] == word)
			{
				check = true;
				break;
			}
			i++;
		}
		if (check == true)
		{
			cout <<"\n" << firstName << " " << lastName;
		}

	}

	void displayData()
	{
		cout << "\n Id: " << id;
		cout << "\n First Name: " << firstName;
		cout << "\n Last Name: " << lastName;
		cout << "\n Connections: ";
		for (int i = 0; i < connectionsCount; i++)
		{
			cout << connections[i] << " ";
		}
		info.displayData();
	}

};
