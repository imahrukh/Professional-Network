#include<iostream>
#include "Posts.h"
#include"helper.h"
 
using namespace std;

class Activity : public Posts
{
private:
	int type;

public:
	Activity()
	{
		type = 0;
	}

	~Activity()
	{
		type = 0;
	}

	friend bool search(char* , char*);

	void checkActivity()
	{
		cout << "\nThe type of activity is distinguished based on these values.\n";
		cout << "\t1- Sharing an article, blog, or news related to the industry.\n";
		cout << "\t2- Asking for advice or feedback related to work or career.\n";
		cout << "\t3- Offering or seeking job opportunities.\n";
		cout << "\t4- Promoting a product or service related to the industry.\n";
	}

	void classifyActivity()
	{
		if (activity != nullptr)
		{
			char key1[10] = "article\0";
			char key2[10] = "advice\0";
			char key3[10] = "job\0";
			char key4[10] = "product\0";

			if(search(activity,key1)==true)
			{
				type = 1;
			}
			else if (search(activity,key2) == 0)
			{
				type = 2;
			}
			else if (search(activity, key3) == 0)
			{
				type = 3;
			}
			else if (search(activity,key3) == 0)
			{
				type = 4;
			}
			else
			{
				type = 0;
			}
		}
	}

};
bool search(char* activity, char* word)
{
	int length = stringLength(activity);
	int wordLength = stringLength(word);
	
	for (int i = 0; i <= length - wordLength; i++) 
	{
		bool found = true;
		for (int j = 0; j < wordLength; j++)
		{
			if (activity[i + j] != word[j])
			{
				found = false;
				break;
			}
		}
		if (found)
			return true;
	}
	return false;
}
