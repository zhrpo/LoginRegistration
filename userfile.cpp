#include <iostream>
#include <fstream>
#include "userfile.h"
#include <string>

std::fstream UserFile;

void setUser(char* username, char* password)
{
	char userPass[41] = " ";
	createUserPass(userPass, username, password);

	UserFile.close();

	UserFile.open("users.txt", std::ios::app);
	if (UserFile.is_open())
	{
		UserFile << username << std::endl;
		UserFile << userPass << std::endl;
	}
	UserFile.close();
}

bool checkUsername(char* username)
{
	bool checkUser = false;

	UserFile.open("users.txt");
	size_t pos;
	std::string line;
	while (UserFile.good())
	{
		getline(UserFile, line); // get line from file
		pos = line.find(username); // search
		if (pos != std::string::npos) // string::npos is returned if string is not found
		{
			checkUser = true;
		}
	}

	UserFile.close();
	return checkUser;

}

bool checkLogin(char* username, char* password)
{
	bool checkUser = false;
	char userPass[41] = " ";
	createUserPass(userPass, username, password);

	UserFile.open("users.txt");
	size_t pos;
	std::string line;
	while (UserFile.good())
	{
		getline(UserFile, line); // get line from file
		pos = line.find(userPass); // search
		if (pos != std::string::npos) // string::npos is returned if string is not found
		{
			checkUser = true;
		}
	}
	UserFile.close();
	return checkUser;
}

void createUserPass(char* userPass, char* username, char* password)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 20; i++)
	{
		if (username[i] != 0)
		{
			userPass[i] = username[i];
		}
		else
		{
			break;
		}
	}
	for (i = i; i < (i + 20); i++)
	{
		if (password[j] != 0)
		{
			userPass[i] = password[j];
			j++;
		}
		else
		{
			break;
		}

	}
}

int countUsername(char* username)
{
	int i = 0;
	int counter = 0;
	for (i = 0; i < 20; i++)
	{
		if (username[i] != 0)
		{
			counter++;
		}
		else
		{
			break;
		}
	}

	return counter;
}

int countPassword(char* password)
{
	int i = 0;
	int counter = 0;
	for (i = 0; i < 20; i++)
	{
		if (password[i] != 0)
		{
			counter++;
		}
		else
		{
			break;
		}
	}

	return counter;
}