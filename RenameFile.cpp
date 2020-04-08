#include"headers.h"

void RenameFileOrFolder()
{
    string oldname=dir_ent[curr_x-1];
	gotoxy(tot_file+1,1);
	char f;
	cout<<"do you want to rename this file[y/n]?\n";
	cin>>f;
	if(f=='y')
	{	
        string newname;
		cout<<"\noldname is:"<<oldname;
		cout<<"\nenter new name of the file (with .extension): ";
		cin>>newname;
		newname=oldname.substr(0,oldname.find_last_of("//"))+"/"+newname;
		getchar();
		rename(oldname.c_str(),newname.c_str());
		ExploreDirectory(newname.substr(0,newname.find_last_of("//")).c_str());
		curr_x=1;
		gotoxy(curr_x,1);
	}
	else
	{
		ExploreDirectory(oldname.substr(0,oldname.find_last_of("//")).c_str());
		curr_x=1;
		gotoxy(curr_x,1);
	}
}