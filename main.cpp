#include"headers.h"
using namespace std;
char *root;
int main(int argc,char *argv[])
{
    string s;
    char *dir_name=NULL;
    if(argc==1)
    {
        s = getcwd(NULL,0);
        dir_name = new char[s.length()+1];
        strcpy(dir_name,s.c_str());
        root=dir_name;
        ExploreDirectory(dir_name);
    }
    else if(argc==2)
    {
        ExploreDirectory(argv[1]);
    }
    else
    {
        cout<<"Invalid Input\n";
    }
    FileOptions();
    return 0;
}