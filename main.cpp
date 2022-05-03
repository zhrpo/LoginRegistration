#include <iostream>
#include <fstream>
#include "userfile.h"
#include "user.h"


int main()
{
	char closeProg = 'y';
	User newUser;
	int choice;
	bool error = false;
	
	do {
		do {
			std::cout << "1.Log in\n2.Register" << std::endl;
			std::cin >> choice;

			switch (choice)
			{
			case 1:
				std::cout << "\nLOG IN:\n";
				newUser.Login();
				std::cout << "\nSuccessfully Logged in!\n\n";
				break;
			case 2:
				std::cout << "\nREGISTER:\n";
				newUser.Register();
				std::cout << "Successfully Registered!\n\n";
				break;
			default:
				std::cout << "Invalid choice!\n";
				error = true;
				break;
			}

		} while (error);

		std::cout << "Would you like to close the program? y/n : ";
		std::cin >> closeProg;
		
	} while (closeProg != 'y' && closeProg != 'Y');

	return 0;
}