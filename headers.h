#include<iostream>
#include<string>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<termios.h>
#include<stdio.h>
#include<vector>
#include<stdlib.h>
#define RESET   "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
using namespace std;
extern vector< string > dir_ent;
extern char *root;
extern int curr_x,csize;
extern int tot_file;
void ExploreDirectory(const char *dir_name);
void FileOptions();
void clrscr();
void gotoxy(int,int);
//int is_regular_file(const char*);