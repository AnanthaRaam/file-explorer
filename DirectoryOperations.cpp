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
	root=string(dir_name)+"/";
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
					//root=path;
					dir_ent.push_back(string(path));
					count++;	
			}
			entry = readdir(dir);
		}
	}
	closedir(dir);
	return count;
}

void PrintFileProperties(struct stat stats)
{
	clrscr();
    struct tm dt;
    cout<<CYAN<<"File access: "<<RESET;
    if (stats.st_mode & R_OK)
        cout<<CYAN<<"read "<<RESET;
    if (stats.st_mode & W_OK)
        cout<<CYAN<<"write "<<RESET;
    if (stats.st_mode & X_OK)
        cout<<CYAN"execute"<<RESET;
    cout<<CYAN<<"\nFile size: "<<stats.st_size<<"kb"<<RESET;
    dt = *(gmtime(&stats.st_ctime));
    cout<<CYAN<<"\nCreated on: "<<dt.tm_mday<<"-"<<dt.tm_mon<<"-"<<dt.tm_year + 1900<< 
                                             " "<<dt.tm_hour<<":"<<dt.tm_min<<":"<<dt.tm_sec<<RESET;
    dt = *(gmtime(&stats.st_mtime));
    cout<<CYAN<<"\nModified on: "<<dt.tm_mday<<"-"<<dt.tm_mon<<"-"<<dt.tm_year + 1900<<
                                              " "<<dt.tm_hour<<":"<<dt.tm_min<<":"<<dt.tm_sec<<RESET;
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