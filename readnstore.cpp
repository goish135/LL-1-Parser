#include<iostream>
#include<fstream>
#include<cstring>
#include<string.h>
#include<vector>
using namespace std;

struct CFG {
	string rule;
	string nt; 
	vector<string> t; 
};

int main()
{
	printf("Input file name:(xxx.txt) or exit the program(exit):");
	string filename;
	while(cin>>filename)
	{
	    if(filename=="exit") 
			break;	
		fstream fp;
		fp.open(filename.c_str(),ios::in); 
		if(!fp) 
		{ 
			cout<<"Fail to open: "<<filename<<endl;	 
		}
		
		char line[1000];
		char *pch_1,*pch_2;
		char backup[1000];
		int count = 0;
		CFG gmr[1000];
		while(fp.getline(line,sizeof(line),'\n'))
		{
			
			strcpy(backup,line); 
			char *ppch,*pchh;
			ppch = strchr(backup,'>');
			int r = ppch-backup+1;
			pchh = strchr(backup,'|');
			int rr  = pchh - backup + 1;
			string rhs,lhs;
			string str(backup); 
			
			if(r>0)
			{
				
				gmr[count].rule = str.substr(0,1);
				gmr[count].nt = str.substr(2,r-4);
				char cc[1000]; 
				string ss = str.substr(r+1);
				strcpy(cc,ss.c_str());
				char *ptr;
				char *de = " ";
				ptr = strtok(cc,de);
				while(ptr!=NULL)
				{
					
					gmr[count].t.push_back(ptr);
					ptr = strtok(NULL,de);
				}
			}
			else
			{
			
				gmr[count].rule = str.substr(0,1);
				gmr[count].nt = gmr[count-1].nt;	
				string s2 = str.substr(rr+1);
				char s22[1000];
				strcpy(s22,s2.c_str());
				char *de = " ";
				char *ptr;
				ptr = strtok(s22,de);
				while(ptr!=NULL)
				{
					gmr[count].t.push_back(ptr);
					ptr = strtok(NULL,de);
				}
				
			}
			count++;
	    }
	
		fp.close();
		
		for(int i = 0;i<count;i++)
		{
			
			cout<<gmr[i].rule<<" "<<gmr[i].nt<<" ->";
			for(int j=0;j<gmr[i].t.size();j++)
			{
			
				cout<<" "<<gmr[i].t[j];
			}
			cout<<'\n';
		} 
		
		system("pause");
		
		printf("Input file name:(xxx.txt) or exit the program(exit):");
		
	}
	
	return 0; 
}
