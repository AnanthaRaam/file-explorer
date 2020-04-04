#include"headers.h"

vector<string> dir_ent;
int tot_file;

int directorylist(const char *path)
{
    int count = 0;
	dir_ent.clear();
	DIR *d;
	struct dirent *dir;
	d = opendir(path);
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if (!((string(dir->d_name) == "..") && (strcmp(path, root) == 0)))
			{
                dir_ent.push_back(string(dir->d_name));
				count++;
			}
		}
		closedir(d);
	}
	else
	{
		cout<<"no diectory found\n";
	}
	return count;
}

void ExploreDirectory(const char *dir_name)
{
    DIR *dir;
    dir=opendir(dir_name);
    struct dirent *entry;
    printf("\033[H\033[J");
	printf("%c[%d;%dH", 27, 1, 1);
    tot_file=directorylist(dir_name);
    if(!dir)
    {
        cout<<"directory not found\n";
        return;
    }
    for(int i=0;i<tot_file;i++)
	{
		char *t = new char[dir_ent[i].length() + 1];
		strcpy(t, dir_ent[i].c_str());
		cout<<t<<"\n";
	}
    //printf("%c[%d;%dH", 27, 1, 80);
    closedir(dir);
}