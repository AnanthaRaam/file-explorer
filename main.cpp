#include"headers.h"
char *root;
using namespace std;
int main(int argc,char *argv[])
{
    string s;
    char *dir_name=NULL;
    if(argc==1)
    {
        s = ".";
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
    return 0;
}