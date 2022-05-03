#ifndef USER_H
#define USER_H
#include <string>

class User
{
private:
	char* username;
	char* password;
public:
	User();
	void setUsername(char* username);
	void setPassword(char* password);
	void Login();
	void Register();
	char* getUsername();
	char* getPassword();
};


#endif // !USER_H