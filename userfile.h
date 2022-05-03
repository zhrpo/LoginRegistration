#ifndef USERFILE_H
#define USERFILE_H

#include <fstream>

void setUser(char* username, char* password);
bool checkUsername(char* username);
bool checkLogin(char* username, char* password);
int countUsername(char* username);
int countPassword(char* password);
void createUserPass(char* userPass, char* username, char* password);

#endif // !USERFILE_H