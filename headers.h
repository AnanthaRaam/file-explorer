/* required headers */
#include<fstream>
#include<iostream>
#include<string>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<termios.h>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<stdlib.h>
#include<sys/wait.h>
using namespace std;

/* setting color properties */
#define RESET   "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define CYAN  "\x1B[36m"

/*  GLOBAL VARIABLES */

/* to store contents in a directory */
extern vector <string> dir_ent;
extern string root;

/* current position of cursor */ 
extern int curr_x;

/* total files in a directory */
extern int tot_file;



/* GLOBAL METHODS */

/* printing files from a directory */
void ExploreDirectory(const char *dir_name);

/* getting user input to do specific task */
void FileExplorerOptions();

/* printing file properties */
void PrintFileProperties(struct stat stats);

/* exploring file upwards */
void ExploreFileUpwards();
void ExploreFileDownwards();

/* navigating the file contents*/
void NavigateContentUpwards();
void NavigateContentDownwards();

/* rename the file or folder*/
void RenameFileOrFolder();

/* delete file or folder */
void DeleteFileOrFolder();

/* create folder */
void CreateFolder();

/* create file */
void CreateFile();

/* application viewer */
void ApplicationViewer();

/* extrautility functions */
void clrscr();
void gotoxy(int,int);
