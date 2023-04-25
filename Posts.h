#include<iostream>
#include<fstream>
#include"helper.h"
#include"Comments.h"
#include"Activity.h"
#include"Date.h";

using namespace std;

class Posts
{
private:
	char* postID;
	char* userid;
	Date date;
	char* text;
	char* likedBy;
	static const int maxLikes = 10;
	int totalLikes = 0;
	Comments comment;

protected:
	char* activity;

public:
	Posts()
	{
		postID = nullptr;
		userid = nullptr;
		text = nullptr;
		activity = nullptr;
		likedBy = nullptr;
	}

	~Posts()
	{
		delete[] postID;
		delete[] userid;
		delete[] text;
		delete[] activity;
		delete[] likedBy;
		postID = nullptr;
		userid = nullptr;
		text = nullptr;
		activity = nullptr;
		likedBy = nullptr;
	}

	void sharePost(char* sender, char* receiver)
	{
		ofstream fw;
		fw.open("Shared Files.txt", ios::app);
		fw << sender << " " << receiver << " " << postID << "\n";
		cout << "\nPost has been sent to " << receiver;
	}

	void addComment(char* feedBack, char* userid)
	{
		cout << "\n" << userid << " commented on " << postID;
		comment.addComment(postID, userid, text);
	}

	char* getPostId()
	{
		return postID;
	}

	char* getuserId()
	{
		return userid;
	}

	void displayPost()
	{
		bool check = date.checkDate(15, 11, 2017);
		if (check == true)
			displayData();
	}

	void displayComment()
	{
		comment.searchComment(postID);
	}

	void readData(ifstream& fr)
	{
		postID = new char;
		userid = new char;
		fr >> postID;
		fr >> userid;
		date.readData(fr);
		text = bufferToChar(fr, '-', text);
		activity = bufferToChar(fr, '-', activity);
		likedBy = bufferToChar(fr, '-', likedBy);
		if (likedBy[0] != '\0')
			totalLikes = 1;
		for (int i = 0; i < maxLikes; i++)
		{
			if (likedBy[i] == ',')
				totalLikes++;
		}
	}

	bool checkActivity()
	{
		Activity::classifyActivity();
		if (Activity::getType() == 3)
		{
			cout << "\Job Postings: ";
			bool check = date.checkDate(15, 11, 2017);
			if (check == true)
				displayData();
		}
		return check;
	}

	void searchWord(char key)
	{
		if (postID[0] == 'c')
		{
			int i = 0;
			bool check = false;
			while (title[i] != '\0')
			{
				if (title[i] == 'key')
				{
					check = true;
					break;
				}
				i++;
			}
		}
		if (check == true)
		{
			cout << "\n" << title;
		}
	}

	void searchActivity(char key)
	{
		int i = 0;
		bool check = false;
		while (activity[i] != '\0')
		{
			if (activity[i] == 'key')
			{
				check = true;
				break;
			}
			i++;
		}
		if (check == true)
		{
			cout << "\n" << activity;
		}
	}

	void displayJobPosts()
	{
		if (Activity::getType() == 3)
		{
			cout << "\Job Postings: ";
			bool check = date.checkDate(15, 11, 2017);
			if (check == true)
				cout << "\nText: " << text;

		}
	}

	void addLike(char* id)
	{
		bool check = checkLikes();
		if (check == true)
		{
			likedBy = stringConcatenate(likedBy, id);
			totalLikes++;
		}
		else
			cout << "\nThe post has reached likes limit!";
	}

	bool checkLikes()
	{
		if (totalLikes <= maxLikes)
		{
			return true;
		}
		else
			return false;
	}

	void displayLikes()
	{
		cout << "\nThe " << postID << " is liked by: ";
		int length = stringLength(likedBy);
		for (int i = 0; i < length && likedBy[i] != '\0'; i++)
		{
			if (likedBy[i] == 'u' || likedBy[i] == 'c' || likedBy[i] == 'p')
			{
				cout << " ";
			}
			cout << likedBy[i];
		}
	}

	void displayData()
	{
		cout << "\nPost ID: " << postID;
		cout << "\nShared By: " << userid;
		date.displayData();
		cout << "\nText: " << text;
		cout << "\nActivity: " << activity;
		cout << "\nLikedBy:";
		int length = stringLength(likedBy);
		for (int i = 0; i < length && likedBy[i] != '\0'; i++)
		{
			if (likedBy[i] == 'u' || likedBy[i] == 'c' || likedBy[i] == 'p')
			{
				cout << " ";
			}
			cout << likedBy[i];
		}
		cout << "\nTotal Likes: " << totalLikes;
	}
};