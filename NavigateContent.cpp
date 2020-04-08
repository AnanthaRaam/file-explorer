#include"headers.h"

void NavigateContentUpwards()
{
    curr_x--;
    if(curr_x<1)
	{
        curr_x=1;
	}
	gotoxy(curr_x,1);
}

void NavigateContentDownwards()
{
    curr_x++;
	if(curr_x>tot_file)
	{
	    curr_x=tot_file;
    }	
	gotoxy(curr_x,1);
}