#include"headers.h"

void clrscr()
{
    cout << "\x1B[2J\x1B[H";
}

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,x,y);
}