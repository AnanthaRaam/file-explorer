#include"headers.h"

void CreateFolder()
{
    char c;
    gotoxy(tot_file+1,1);
	string t;
	string temp=dir_ent[curr_x-1];
	temp=root;
	cout<<"do you want to create a directory[y/n]\n";
	cin>>c;
	if(c=='y')
	{
		cout<<"enter the name of the directory to be created\n";
		cin>>t;
		t=temp.substr(0,temp.find_last_of("//"))+"/"+t;
		if(mkdir(t.c_str(),0777)==-1)
		{
			cerr<<"error : "<<strerror(errno)<<endl;
		}
		else
		{
            ExploreDirectory(temp.substr(0,temp.find_last_of("//")).c_str());
			curr_x=1;
			gotoxy(curr_x,1);
			getchar();
		}	
    }  
	else
	{
		ExploreDirectory(temp.substr(0,temp.find_last_of("//")).c_str());
		curr_x=1;
		gotoxy(curr_x,1);
	}
}

void CreateFile()
{
    gotoxy(tot_file+1,1);
	string temp;
	temp=root;
	char c;
	string fname;
	cout<<"do you want to create a file[y/n]\n";
	cin>>c;
	if(c=='y')
	{
		cout<<"enter the file name to be created(with extension) : ";
		cin>>fname;
		fname=temp.substr(0,temp.find_last_of("//"))+"/"+fname;
		std::ofstream file { fname };
		cout<<"file created successfully\n";
		ExploreDirectory(temp.substr(0,temp.find_last_of("//")).c_str());
    	curr_x=1;
		gotoxy(curr_x,1);
		getchar();
	}
	else
	{
		ExploreDirectory(temp.substr(0,temp.find_last_of("//")).c_str());
		curr_x=1;
		gotoxy(curr_x,1);
    }
}