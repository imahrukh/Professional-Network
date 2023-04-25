#include<iostream>
#include<fstream>
#include"helper.h"
#include"Profile.h"

using namespace std;

class Comments
{
private:
	char* commentID;
	char* postID;
	Profile user;
	char* text;

public:
	Comments()
	{
		commentID = nullptr;
		postID = nullptr;
		user = nullptr;
		text = nullptr;
	}

	Comments(char* postid, char* userid, char* text) :postID(postid), user(userid), text(text)
	{

	}

	void searchComment(char* postId)
	{
		if (postID == postId)
			cout << "\nComment: " << text;
	}

	~Comments()
	{
		delete[] commentID;
		delete[]postID;
		delete[] text;
		user = nullptr;
		commentID = nullptr;
		postID = nullptr;
		text = nullptr;
	}

	void addComment(char* postID, char* userid, char* text)
	{
		this->postID = postID;
		user.setId(userid);
		this->text = text;
		cout << "\nComment uplaoded!";
	}

	void searchComment(char* postId)
	{
		int result = stringCompare(postId, postID);
		/*int i = 0;
		int result = 0;
		while (postId[i] != '\0' && postID[i] != '\0')
		{
			if (postId[i] == postID[i])
				result = 0;
			else
			{
				result = 1;
				break;
			}
			i++;
		}	*/
		if (result == 0)
			cout << "\nComment: " << text;
	}

	void readData(ifstream& fr)
	{
		commentID = new char;
		postID = new char;
		fr >> commentID;
		fr >> postID;
		user.readData(fr);
		text = bufferToChar(fr, '-', text);	
	}

	void displayData()
	{
		cout << "\nComment Id: " << commentID;
		cout << "\nPost Id: "<<postID;
		cout << "\nuser Id: " << user.getID();
		cout << "\nText: "<<text;
	}
};