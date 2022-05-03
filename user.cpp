#include <iostream>
#include "user.h"
#include "userfile.h"

User::User()
{
	username = nullptr;
	password = nullptr;
}

void User::setUsername(char* username)
{
	this->username = username;
}

void User::setPassword(char* password)
{
	this->password = password;
}

void User::Login()
{
	char username[20] = "";
	char password[20] = "";
	bool checkSignIn = false;

	do {
		if (!checkSignIn)
		{
			std::cout << "\nUsername or Password not found! Try again!\n";
		}
		std::cout << "Enter Username: ";
		std::cin >> username;

		std::cout << "Enter Password: ";
		std::cin >> password;

		if (checkLogin(username, password))
		{
			checkSignIn = true;
		}
		else 
		{
			checkSignIn = false;
		}
	} while (!checkLogin);
	setUsername(username);
	setPassword(password);
}

void User::Register()
{
	char username[20] = "";
	char password[20] = "";
	int countUse;
	int countPass;
	bool checkPass = false;
	bool checkName = false;

	//check if over 20 char
	std::cout << "Username and Password can only be from 8 to 20 characters.\n";
	do {
		if (checkName && countUse >= 8 && countUse <= 20)
		{
			std::cout << "\nUsername already in use!\n";
		}

		std::cout << "Enter Username: ";
		std::cin >> username;

		countUse = countUsername(username);

		if (countUse >= 8 && countUse <= 20)
		{

			if (checkUsername(username))
			{
				checkName = true;
			}
			else
			{
				checkName = false;
			}
		}
		else
		{
			std::cout << "\nName not between 8 and 20 characters!\n";
			checkName = true;
		}
	} while (checkName);


	setUsername(username);


	do{
		if (checkPass)
		{
			std::cout << "\nPassword not between 8 and 20 characters!\n";
		}
		std::cout << "Enter Password: ";
		std::cin >> password;

		countPass = countPassword(password);
		if (countPass >= 8 && countPass <= 20)
		{
			setPassword(password);
			checkPass = false;
		}
		else
		{
			checkPass = true;
		}

	} while (checkPass);

	setUser(this->username, this->password);

	std::cout << "Welcome " << this->username << "! You have ";
}

char* User::getUsername()
{
	return username;
}

char* User::getPassword()
{
	return password;
}