#include"headers.h"
using namespace std;

//vector<string> dir_ent;
int tot_file;
int directorylist(const char *dir_name=NULL)
{
    int count = 0;
	dir_ent.clear();
	DIR *dir=NULL;
	struct dirent *entry=NULL;
	string path;
	dir_ent.resize(0);
	dir = opendir(dir_name);
	if(!dir)
	{
		cout<<"directory not found\n"<<dir_name<<endl;
		return 0;
	}
	else
	{
		entry = readdir(dir);
		while(entry != NULL)
		{
			if (entry->d_name[0]!='.')
			{
					if(string(dir_name).compare("/")!=0)
						 path=string(dir_name)+"/"+string(entry->d_name);
					else
						 path="/"+string(entry->d_name);
					dir_ent.push_back(string(path));
					count++;	
			}
			entry = readdir(dir);
		}
	}
	closedir(dir);
	return count;
}

void ExploreDirectory(const char *dir_name=NULL)
{
    clrscr();
	struct stat info;
	tot_file=directorylist(dir_name);
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

}