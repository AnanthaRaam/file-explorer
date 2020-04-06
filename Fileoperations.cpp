#include"headers.h"

//int tot_file;
int curr_x=1;

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
				//cout<<curr_x;
				if(curr_x<1)
				{
					curr_x=1;
				}
				gotoxy(curr_x,1);
				//cout<<"w";
			}
			else if(ch=='s') //down arrow
			{
				curr_x++;
				if(curr_x>tot_file)
				{
					curr_x=tot_file;
				}
				gotoxy(curr_x,1);
				//cout<<"s";
			}
			else if(int(ch)==10)
			{
				//cout<<curr_x;
				//getchar();
				string temp=dir_ent[curr_x-1];;
				// cout<<temp<<endl;
				// clrscr();
				// temp=temp.substr(1,temp.length());
				// cout<<temp<<endl;
				ExploreDirectory(temp.c_str());
				curr_x=1;
				gotoxy(curr_x,1);
				//cout<<"enter\n";
			}
			else if(ch=='q')	//quit filemanager
			{
				clrscr();
				break;
				// cout<<"q";
			}
			
		}
	}
	clrscr();
	tcsetattr(fileno(stdin), TCSANOW, &old);
}