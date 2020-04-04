#include"headers.h"
int xcor=1,ycor=70;
#define esc 27
#define pos() printf("%c[%d;%dH", esc, xcor, ycor)
#define posx(x,y) printf("%c[%d;%dH", esc, x, y)
void FileOptions()
{
    char ch;
    xcor=1;
    ycor=70;
    pos();
    int lastline;
    struct termios old, news;
	tcgetattr(fileno(stdin), &old);
	news = old;
	news.c_lflag &= ~ICANON;
	news.c_lflag &= ~ECHO;

	if (tcsetattr(fileno(stdin),TCSAFLUSH,&new) != 0)
	{
		fprintf(stderr, "Could not set attributes\n");
	}
    else
    {
        while(1)
        {
            lastline=rowsize+1;
            posx(lastline,1);
            cout<<"Welcome to File operations mode\n";
            pos();
            ch=cin.get()
            
        }
    }
    
}