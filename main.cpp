#include<iostream>
#include<fstream>
#include"User.h"
#include"Company.h"
#include"Pages.h"
#include"Comments.h"
#include"Posts.h"
#include"helper.h"

using namespace std;

int randomGenerator(int);
void mainmenu();

int main()
{
	ifstream fru("Professional Network Users.txt");
	if (!fru.is_open())
	{
		cout << "File not opened!\n";
		return 1;
	}
	int totalUsers ;
	fru >> totalUsers;
	User* user = new User[totalUsers];
	for (int i = 0; i < totalUsers; i++)
	{
		user[i].readData(fru);
		user[i].displayData();
	}
	fru.close();

	ifstream frpg;
	frpg.open("Professional Network Pages.txt");
	if (!frpg.is_open())
	{
		cerr << "File not opened!";
		return 1;
	}
	int totalPages;
	frpg >> totalPages;
	Pages* page = new Pages[totalPages];
	for (int i = 0; i < totalPages; i++)
	{
		page[i].readData(frpg);
		page[i].displayData();
	}
	frpg.close();

	ifstream frco;
	frco.open("Professional Network Companies.txt");
	if (!frco.is_open())
	{
		cerr << "File not opened!";
		return 1;
	}
	int totalCompanies;
	frco >> totalCompanies;
	Company* company = new Company[totalCompanies];
	for (int i = 0; i < totalCompanies; i++)
	{
		company[i].readData(frco);
		company[i].displayData();
	}
	frco.close();

	ifstream frc;
	frc.open("Professional Network Comments.txt");
	if (!frc.is_open())
	{
		cerr << "File not opened!";
		return 1;
	}
	int totalComments;
	frc >> totalComments;
	Comments* comment = new Comments[totalComments];
	for (int i = 0; i < totalComments; i++)
	{
		comment[i].readData(frc);
		comment[i].displayData();
	}
	frc.close();

	ifstream frp;
	frp.open("Professional Network Posts.txt");
	if (!frp.is_open())
	{
		cerr << "File not opened!";
		return 1;
	}
	int totalPosts;
	frp >> totalPosts;
	Posts* post = new Posts[totalPosts];
	for (int i = 0; i < totalPosts; i++)
	{
		post[i].readData(frp);
		post[i].displayData();
	}
	frp.close();
	
	while (1)
	{
		mainmenu();
		int choice;
		while (!(cin >> choice))
		{
			cin.clear();
			cin.ignore();
		}
		while (choice < 1 || choice >12)
		{
			cout << "\nInvalid! Enter value from 1 -12";
			while (!(cin >> choice))
			{
				cin.clear();
				cin.ignore();
			}
		}
		system("cls");

		if (choice == 1)
		{
			int index = randomGenerator(totalUsers);
			User& currentUser = user[index];
			cout << "\nCurrent user succesfully set.";
		}

		else if (choice == 2)
		{
			int index = randomGenerator(totalUsers);
			User& currentUser = user[index];
			for (int i = 0; i < totalPosts; i++)
			{
				if (stringCompare(currentUser.getconnection(), post[i].getuserId()) == 0)
				{
					post[i].displayPost();
				}
			}
			if (currentUser.getSkills != nullptr)
			{
				for (int i = 0; i < totalPosts; i++)
				{
					post[i].checkActivity();
				}
			}
		}

		else if (choice == 4)
		{
			int index = randomGenerator(totalPosts);
			Posts& currentPost = post[index];
			currentPost.displayLikes();
		}

		else if (choice == 3)
		{
			int index = randomGenerator(totalPosts);
			Posts& currentPost = post[index];
			char buffer[5] = "c5\0";
			currentPost.addLike(buffer);
			currentPost.displayLikes();
		}

		else if (choice == 5)
		{
			int index = randomGenerator(totalPosts);
			Posts& currentPost = post[index];
			char buffer[20] = "Good work!\0";
			int len = stringLength(buffer);
			char* text = new char[len];
			text = stringCopy(text, buffer);
			int ind = randomGenerator(totalUsers);
			User& currentUser = user[ind];
			char* id = new char;
			id =currentUser.getId();
			currentPost.addComment(text, id);
		}

		else if (choice == 6)
		{

			int index = randomGenerator(totalPosts);
			Posts& currentPost = post[index];
			currentPost.displayData();
			currentPost.displayComment();
			for (int i = 0; i < totalComments; i++)
			{
				comment[i].searchComment(currentPost.getPostId());
			}

		}

		else if (choice == 7)
		{
			int index = randomGenerator(totalPosts);
			Posts& currentPost = post[index];
			int si = randomGenerator(totalUsers);
			User& senderId = user[si];
			char* sender =	senderId.getID();
			int ri = randomGenerator(totalUsers);
			User& receiverId = user[ri];
			char* receiver = receiverId.getID();
			currentPost.sharePost(sender, receiver);
		}

		else if (choice == 8)
		{
			int index = randomGenerator(totalUsers);
			User& currentUser = user[index];
			currentUser.displayData();
		}

		else if (choice == 9)
		{
			int index = randomGenerator(totalUsers);
			User& currentUser = user[index];
			currentUser.displayConnections();
		}

		else if (choice == 10)
		{
			for (int j = 0; j < totalPosts; i++)
			{
				for (int i = 0; i < totalCompanies; i++)
				{
					if (stringCompare(company[i].getid(), post[j].userid) == 0)
					{
						bool check = post[j].checkActivity();
						if (check == true)
							company[i].displayData();
					}

				}
			}
		}

		else if (choice == 11)
		{
			char key = 'a';
			cout << "\nSearch results: ";
			cout << "\nName of users : ";
			for (int i = 0; i < totalUsers; i++)
			{
				user[i].searchWord(key);
			}
			cout << "\nPost titles: ";
			for (int i = 0; i < totalPosts; i++)
			{
				post[i].searchWord(key);
			}
			cout << "\nActivity description:";
			for (int i = 0; i < totalPosts; i++)
			{
				post[i].searchActivity(key);
			}
		}

		else if (choice == 12)
		{
			cout << "\nExiting!";
			exit(0);
		}
	}

	for (int i = 0; i < totalUsers; i++)
	{
		delete[]user[i];
	}
	delete[] user;
	user = nullptr;

	for (int i = 0; i < totalPosts; i++)
	{
		delete[].post[i]
	}
	delete[] post;
	post = nullptr;

	for (int i = 0; i < totalCompanies; i++)
	{
		delete[]company[i];
	}
	delete[] company;
	company = nullptr;

	for (int i = 0; i < totalpages; i++)
	{
		delete[]page[i];
	}
	delete[] page;
	page = nullptr;

	for (int i = 0; i < totalComments; i++)
	{
		delete[]comment[i];
	}
	delete[] comment;
	comment[] = nullptr;
	return 0;
	system("pause");

}

int randomGenerator(int max)
{
	srand(time(0));
	int index = rand() % max;
	return index;
}

void mainmenu()
{
	cout << "__________________________________________________________________\n";
	cout << "\t\t\tSelect an option to proceed.\n";
	cout << "\t  1- Set Current User.\n";
	cout << "\t  2- View home of current user.\n";
	cout << "\t  3- Like a post.\n";
	cout << "\t  4- View list of people who liked a post.\n";
	cout << "\t  5- Comment on a post.\n";
	cout << "\t  6- View post.\n";
	cout << "\t  7- Share post.\n";
	cout << "\t  8- View user's profile.\n";
	cout << "\t  9- View connections.\n";
	cout << "\t  10- View job postings.\n";
	cout << "\t  11- Search.\n";
	cout << "\t  12-Exit.\n";
	cout << "________________________________________________________________\n";
}

