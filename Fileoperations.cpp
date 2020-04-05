#include"headers.h"

//int tot_file;
int curr_x;

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
  
	vector<string>::iterator ptr; 
    struct termios old, news;
	curr_x=0;
	tcgetattr(fileno(stdin), &old);
	news = old;
	news.c_lflag &= ~ICANON;
	news.c_lflag &= ~ECHO;

	if (tcsetattr(fileno(stdin),TCSAFLUSH,&news) != 0)
	{
		fprintf(stderr, "Could not set attributes\n");
	}
	else
	{
		char  ch;
		gotoxy(0,0);
		while(1)
		{
			ch=cin.get();
			if(ch=='w')		//up arrow
			{
				curr_x--;
				if(curr_x<0)
				{
					curr_x=0;
				}
				gotoxy(curr_x,0);
				// for (ptr = dir_ent.begin(); ptr < dir_ent.end(); ptr++)
				// {
				// 	cout<<*ptr<<"\n";
				// }
			}
			else if(ch=='d') //down arrow
			{
				curr_x++;
				if(curr_x>tot_file)
				{
					curr_x=tot_file;
				}
				gotoxy(curr_x,0);
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