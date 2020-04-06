#include"headers.h"

vector<string> dir_ent;
int tot_file;
int directorylist(const char *dir_name=NULL)
{
    int count = 0;
	dir_ent.clear();
	DIR *dir=NULL;
	//cout<<dir_name;
	struct dirent *entry=NULL;
	dir_ent.resize(0);
	dir = opendir(dir_name);
	if(!dir)
	{
		cout<<"directory not found\n"<<dir_name<<endl;
	//	printf(stderr,"cant open  the directory\n");
		return 0;
	}
	else
	{
		entry = readdir(dir);
		while(entry != NULL)
		{
			if (entry->d_name[0]!='.')
			{
				//string path=string(dir_name)+"/"+string(entry->d_name);
				// string path=string(entry->d_name);
				string path=string(dir_name)+"/"+string(entry->d_name);
				dir_ent.push_back(string(path));
				count++;
			}
			entry = readdir(dir);
		}
	}
	closedir(dir);
	return count;
}

// int is_regular_file(const char *path)
// {
//     struct stat path_stat;
//     stat(path, &path_stat);
//     return S_ISREG(path_stat.st_mode);
// }

void ExploreDirectory(const char *dir_name=NULL)
{
    clrscr();
	struct stat info;
	tot_file=directorylist(dir_name);
    for(int i=0;i<tot_file;i++)
	{
		 string t = dir_ent[i];
		//strcpy(t, dir_ent[i].c_str());
		stat(t.c_str(),&info);
        if(S_ISDIR(info.st_mode)){
               std::cout << GREEN <<t<< RESET << std::endl;
			    //explore((char*)path.c_str());
		}
		else{
			std::cout<<RED<<t<<RESET<<std::endl;
		}
		// if (dir_ent[i].find(".") != std::string::npos)
		// {
    	// 	std::cout << RED <<t<< RESET << std::endl;
		// }
		// else
		// {
		// 	std::cout<<GREEN<<t<<RESET<<std::endl;
		// }
		
	}

}