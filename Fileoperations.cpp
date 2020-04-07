#include"headers.h"
using namespace std;

int curr_x=1;
vector<string> dir_ent;



void FileOptions()
{ 
    struct termios old, news;
	tcgetattr(fileno(stdin), &old);
	news = old;
	news.c_lflag &= ~ICANON;
	news.c_lflag &= ~ECHO;
	char  ch;
	if (tcsetattr(fileno(stdin),TCSAFLUSH,&news) != 0)
	{
		fprintf(stderr, "Could not set attributes\n");
	}
	else
	{
		
		gotoxy(1,1);
		while(1)
		{
			
			ch=getchar();
			if(ch=='w')		//navigating upwards
			{
				curr_x--;
				if(curr_x<1)
				{
					curr_x=1;
				}
				gotoxy(curr_x,1);
			}
			else if(ch=='s') //navigating downwards
			{
				curr_x++;
				if(curr_x>tot_file)
				{
					curr_x=tot_file;
				}
				gotoxy(curr_x,1);
			}
			else if(int(ch)==10)	//exploring the file upwards
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
        				printFileProperties(stats);
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
			else if(ch==0x7f) 	//exploring the file backwards
			{
				clrscr();
				//cout<<"backspace entered\n";
				//struct stat info;
				string str=dir_ent[curr_x-1];
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
			else if(ch=='>')	//rename a file
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
			else if(ch=='d')	//file deletion
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
			else if(ch=='c')		//create a folder
			{
				char c;
				gotoxy(tot_file+1,1);
				string t;
				string temp=dir_ent[curr_x-1];
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
						//cout<<"directory created succesfully\n";
						//cout<<"press any key to continue\n";
						//getchar();
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
			else if(ch=='f')	//creating file
			{
				gotoxy(tot_file+1,1);
				string temp=dir_ent[curr_x-1];
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
			else if(ch=='q')	//quit filemanager
			{
				clrscr();
				break;
			}
			
		}
	}
	clrscr();
	tcsetattr(fileno(stdin), TCSANOW, &old);
}