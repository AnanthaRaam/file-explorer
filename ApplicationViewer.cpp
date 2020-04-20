#include"headers.h"

void ApplicationViewer()
{
    string t=dir_ent[curr_x-1];
	string temp=t.substr(0,t.find_last_of("//"));
	gotoxy(tot_file+1,1);
	cout<<"do u want to open the default application for selected file[y/n]\n";
	char c;
	cin>>c;
	if(c=='y')
	{
		string cmd= "xdg-open "+ dir_ent[curr_x-1];
		system(cmd.c_str());
        clrscr();
	}
    clrscr();
	ExploreDirectory(t.substr(0,t.find_last_of("//")).c_str());
	curr_x=1;
	gotoxy(curr_x,1);
}