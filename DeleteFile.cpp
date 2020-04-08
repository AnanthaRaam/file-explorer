#include"headers.h"

void DeleteFileOrFolder()
{
    string t=dir_ent[curr_x-1];
	string temp=t.substr(0,t.find_last_of("//"));
	char c;
	gotoxy(tot_file+1,1);
	cout<<"do you want to delete the selected file/folder[y/n]\n";
	cin>>c;
	if(c=='y')
	{
		if(!remove(t.c_str()))
		{
			cout<<"file deleted successfully\n";
			getchar();
		}
		else
		{
			cout<<"operation unsuccessful\n";
		}
		ExploreDirectory(temp.c_str());
		curr_x=1;
		gotoxy(curr_x,1);
	}
    
    else
	{
		ExploreDirectory(t.substr(0,t.find_last_of("//")).c_str());
		curr_x=1;
		gotoxy(curr_x,1);
	}				
}