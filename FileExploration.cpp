#include"headers.h"

void ExploreFileUpwards()
{
    struct stat stats;
	string t = dir_ent[curr_x-1];
	stat(t.c_str(),&stats);
    if(S_ISDIR(stats.st_mode))
	{
    	ExploreDirectory(t.c_str());
	}
	else
	{
		if (stat(t.c_str(), &stats) == 0)
    	{
        	PrintFileProperties(stats);
    	}
    	else
    	{
        	printf("Unable to get file properties.\n");
        	printf("Please check whether '%s' file exists.\n",t.c_str());
    	}
		cout<<"\npress any key to continue...";
		getchar();
		clrscr();
    }
	curr_x=1;
	gotoxy(curr_x,1);
	struct stat info;
	for(int i=0;i<tot_file;i++)
	{
		string t = dir_ent[i];
		stat(t.c_str(),&info);
        if(S_ISDIR(info.st_mode))
		{
           	cout<<GREEN<<t<<RESET<<endl;
		}
		else
		{
			cout<<RED<<t<<RESET<<endl;
		}
		
	}
	curr_x=1;
	gotoxy(curr_x,1);
}

void ExploreFileDownwards()
{
    clrscr();
	string str=root;
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