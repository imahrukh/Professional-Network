#include<iostream>
#include<fstream>
#include"helper.h"
using namespace std;

class ProfessionalProfile
{
private:
	char* university;
	char* degree;
	char* experience;
	char** skills;
	int countSkills;

public:
    ProfessionalProfile()
    {
        countSkills = 0;
        university = nullptr;
        degree = nullptr;
        experience = nullptr;
        skills = nullptr;
    }

    char** getSkills()
    {
        return skills;
    } 

    ~ProfessionalProfile()
    {
        delete[] university;
        university = nullptr;
        delete[] degree;
        degree = nullptr;
        delete[] experience;
        experience = nullptr;
        for (int i = 0; i < countSkills; i++)
        {
            delete[] skills[i];
        }
        delete[] skills;
        skills = nullptr;     
    }

    void readData(ifstream& fr)
    {
        degree = new char;
        university = new char;
        experience = new char;
        fr >> degree;
        fr >> university;
        skills = bufferTo2dchar(fr, '_', ',', skills, countSkills);
        fr >> experience;
    }

    void displayData()
    {
        cout << "\nDegree: " << degree;
        cout << "\nUniversity: " << university;
        cout << "\nSkills: ";

        for (int i = 0; i < countSkills; i++)
        {
            cout << skills[i] << ", ";
        }

        cout << "\nExperience: " << experience;
    }
};