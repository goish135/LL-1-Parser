#include<iostream>
#include<fstream>
#include<cstring>
#include<string.h>
#include<vector>
#include<stdlib.h>
using namespace std;

struct CFG {
	string rule;
	string nt; 
	vector<string> t; 
};

vector<string> check;

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
				string r1 = str.substr(0,r-1);
				char *po;
				char *del =" ";
				char aa[1000];
				strcpy(aa,r1.c_str());
				po = strtok(aa,del);
				int n = 0;
				while(po!=NULL)
				{
					if(n==0) {
						gmr[count].rule = po;
						n++;
					}
					else
					{
						gmr[count].nt = po;
					}
					po = strtok(NULL,del);
				}
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
				string r2 = str.substr(0,rr-1);
				char *poo;
				char *dell =" ";
				char dd[1000];
				strcpy(dd,r2.c_str());
				poo = strtok(dd,dell);
				int nn = 0;
				while(poo!=NULL)
				{
					if(nn==0) {
						gmr[count].rule = poo;
						nn++;
					}
					poo = strtok(NULL,dell);
				}
				
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
	    
		for(int i=0;i<count;i++) 
		{
			for(int j=0;j<gmr[i].t.size();j++)
			{
				if(gmr[i].t[j]=="lamda")
				{
					check.push_back(gmr[i].nt);
				}	
			}	
		}
		
		for(int j=0;j<count;j++)
		{
			int flag = 0;
			int k;
			for(k=0;k<gmr[j].t.size();k++)
			{
					flag = 0;
					for(int z=0;z<check.size();z++)
					{
						if(gmr[j].t[k]==check[z])
						{
							flag = 1;
							break;
						}
					}
					if(flag==0) break;
			}
			if(flag==1) gmr[j].t.push_back("lamda");	
		}
		fp.close();
		
		int total_len = filename.length();
		string chs = filename.substr(0,total_len-4)+"++.txt";
		
		fp.open(chs.c_str(), ios::out);

		int total = 1;
		for(int i=0;i<count-1;i++)
		{
				if(gmr[i].nt!=gmr[i+1].nt)
					total++;
		}
		
		fp<<total<<endl;
		int ccount=0;
		int non_count=0;
		
		for(int i = 0;i<count;i++)
		{
			
			int same = 1;
			if(i==0)  fp<<gmr[i].nt;
			else 
			{
				if(gmr[i-1].nt!=gmr[i].nt)
				{
					fp<<"\n";
					fp<<gmr[i].nt;
				
				}
			}	
			fp<<" /";
			for(int j=0;j<gmr[i].t.size();j++)
			{
				fp<<" "<<gmr[i].t[j];
			}
			
		} 
		fp<<"\n\n";
		fp.close();
		
		freopen("CON","w",stdout);
		printf("finished!\n");
	
		printf("\nInput file name:(xxx.txt) or exit the program(exit):");
		
	}
	
	return 0; 
}
