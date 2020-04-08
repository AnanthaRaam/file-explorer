#include"headers.h"
using namespace std;

int curr_x=1;
vector<string> dir_ent;
string root;


void FileExplorerOptions()
{ 
    struct termios old, news;
	tcgetattr(fileno(stdin), &old);
	news = old;
	news.c_lflag &= ~ICANON;
	news.c_lflag &= ~ECHO;
	char  ch;
	if (tcsetattr(fileno(stdin),TCSAFLUSH,&news) != 0)
	{
		fprintf(stderr, "Could not set attributes\n");
	}
	else
	{
		
		gotoxy(1,1);
		while(1)
		{
			
			ch=getchar();
			if(ch=='w')		//navigating upwards
			{
				NavigateContentUpwards();
			}
			else if(ch=='s') //navigating downwards
			{
				NavigateContentDownwards();
			}
			else if(int(ch)==10)	//exploring the file upwards
			{
				ExploreFileUpwards();
			}
			else if(ch==0x7f) 	//exploring the file backwards
			{
				ExploreFileDownwards();
			}
			else if(ch=='>')	//rename a file
			{
				RenameFileOrFolder();
			}
			else if(ch=='d')	//file deletion
			{
				DeleteFileOrFolder();
			}
			else if(ch=='c')		//create a folder
			{
				CreateFolder();
			}
			else if(ch=='f')	//creating file
			{
				CreateFile();
			}
			else if(ch=='q')	//quit filemanager
			{
				clrscr();
				break;
			}
			
		}
	}
	clrscr();
	tcsetattr(fileno(stdin), TCSANOW, &old);
}