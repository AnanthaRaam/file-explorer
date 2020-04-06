#include"headers.h"
using namespace std;

int curr_x=1;
vector<string> dir_ent;

void clrscr()
{
	printf("\e[1;1H\e[2J");
}
void gotoxy (int x, int y)
{
    printf("%c[%d;%df",0x1B,x,y);      
}

void FileOptions()
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
			if(ch=='w')		//up arrow
			{
				curr_x--;
				if(curr_x<1)
				{
					curr_x=1;
				}
				gotoxy(curr_x,1);
			}
			else if(ch=='s') //down arrow
			{
				curr_x++;
				if(curr_x>tot_file)
				{
					curr_x=tot_file;
				}
				gotoxy(curr_x,1);
			}
			else if(int(ch)==10)	//enter key
			{
				string temp=dir_ent[curr_x-1];;
				ExploreDirectory(temp.c_str());
				curr_x=1;
				gotoxy(curr_x,1);
			}
			else if(ch==0x7f)
			{
				clrscr();
				//cout<<"backspace entered\n";
				//struct stat info;
				string str=dir_ent[curr_x-1];
				
				str=str.substr(0,str.find_last_of("//"));
				str=str.substr(0,str.find_last_of("//"));
				if(str.empty())
				{
					ExploreDirectory("/");
				}
				else
				{
					ExploreDirectory(str.c_str());
				}
				curr_x=1;
				gotoxy(curr_x,1);
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