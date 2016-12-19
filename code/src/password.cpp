
#include <iostream>
#include <tr1/functional>
#include <string.h>
#include <fstream>
#include <sstream>;
#include <stdlib.h>
#include "password.h"

// create a file "username_password.txt" from main function at server end.... in the mydropbox folder

int hash_val(char *s, int size){
	std::string str(s,size);
	std::tr1::hash<std::string> str_hash;
	int val =  (int) str_hash(str);
	return val;
}

//returns false if user doesn't exist, else returns true
bool check_user(std::string username){
	std::ifstream readfile("username_password.txt");
	readfile.seekg(0,std::ios::beg);
	std::string line;
	while (getline(readfile, line))
	{
    std::istringstream iss(line);
    std::string a; int b;
    if (!(iss >> a >> b)) { break; } 
	if (a==username) {readfile.close();return true;}
	}
	readfile.close();
	return false;
}

int set_user(std::string username, std::string password){
	if (!check_user(username)) 
	{
	char * cstr = new char [password.length()+1];
	strcpy (cstr, password.c_str());
	std::ofstream myfile;
	myfile.open("username_password.txt",std::ios_base::app);
	myfile << username<< " "<<hash_val(cstr,password.length()+1)<<"\n";
	myfile.close();
	return 0;
	}
	return 1;
}

// may/maynot be implemented
void change_password(std::string username, std::string new_pwd){}

// returns 1 if password match, -1 if wrong password, 0 if user unregistered
int check_password(std::string username, std::string password){
char * cstr = new char [password.length()+1];
strcpy (cstr, password.c_str());
std::ifstream readfile("username_password.txt");
readfile.seekg(0,std::ios::beg);
std::string line;
while (getline(readfile, line))
{
    std::istringstream iss(line);
    std::string a; int b;
    if (!(iss >> a >> b)) { break; } 
	if (a==username) {if (b==hash_val(cstr,password.length()+1)) {readfile.close();return 1;} else {readfile.close();return -1;}}
}
readfile.close();
return 0;
} 


// test case
/*int main(){
set_user("Kunika","Hi");
set_user("Deepali","Hello");
set_user("Ramneek","HiBye");
std::cout<< check_password("Kunika","Hi")<<std::endl;
std::cout<< check_password("Ramneek","HiBye")<<std::endl;
std::cout<< check_password("Deepali","Hello")<<std::endl;
std::cout<< check_password("Deepali","Hi")<<std::endl;
std::cout<< check_password("Dipali","Hello")<<std::endl;
std::cout<< check_user("Dipali")<<std::endl;
}*/


