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

struct chage_input{
	string ntt;
	vector<string> tt; 
};

vector<string> check;
//struct dl{ // save derive lamda 's nonterminal 
	//vector<string> sett;
//};

//dl abc[1000];

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
		int len = filename.length();
		printf("len:%d\n",len);
		if(!fp) 
		{ 
			cout<<"Fail to open: "<<filename<<endl;	 
		}
		
		char line[1000];
		char *pch_1,*pch_2;
		char backup[1000];
		int count = 0;
		CFG gmr[1000];
		chage_input gmrr[1000];
		
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
	    
		for(int i=0;i<count;i++) // run every rule
		{
			cout<<gmr[i].rule<<" "<<gmr[i].nt;
			for(int j=0;j<gmr[i].t.size();j++)
			{
				cout<<" "<<gmr[i].t[j];
				if(gmr[i].t[j]=="lamda")
				{
					cout<<"\n derive lamda: "<<gmr[i].nt<<endl;
					check.push_back(gmr[i].nt);
				}	
			}
			cout<<endl;	
		}
		
		for(int i=0;i<check.size();i++)
		{
			cout<<check[i]<<"op"<<endl;
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
			if(flag==1&&k==gmr[j].t.size()) gmr[j].t.push_back("lamda");	
		}
		
		fp.close();
		string chs = filename.substr(0,5)+"++.txt";
		
		fp.open(chs.c_str(), ios::out);//¶}±ÒÀÉ®×

		int total = 1;
		for(int i=0;i<count-1;i++)
		{
			//if(i==0) total++;
			//else
			//{
				if(gmr[i].nt!=gmr[i+1].nt)
					total++;
			//}
		}
		
		fp<<total<<endl;
		int ccount=0;
		int non_count=0;
		
		for(int i = 0;i<count;i++)
		{
			
			//cout<<gmr[i].rule<<" "<<gmr[i].nt<<" ->";
			//fp<<gmr[i].rule<<" "<<gmr[i].nt<< " ->";
			int same = 1;
			if(i==0)  fp<<gmr[i].nt;
			else 
			{
				if(gmr[i-1].nt!=gmr[i].nt)
				{
					fp<<gmr[i].nt;
					same = 0;
				}
			}
			
			
			//for(int k=0;k<=non_count;k++)
			//{
				//gmrr[non_count++].ntt=gmr[i].nt;
				
			//fp<<"test"<<gmrr[i].ntt<<'\n';
			//if(i==0)
			//{
				//gmrr[non_count++].ntt=gmr[i].nt;	
			//} 
			
			//else if(i!=0&&gmr[i].nt!=gmr[i-1].nt)
			//{
			//	gmrr[non_count++].ntt=gmr[i].nt;
			//}
			//if(same==0) fp<<'\n';
			fp<<" /";
			for(int j=0;j<gmr[i].t.size();j++)
			{
			
				fp<<" "<<gmr[i].t[j];
				//if(i==0)
				//{
				//	gmrr[ccount++].tt.push_back("/"+gmr[i].t[j]);
				//}
			//	else if(i!=0&&gmr[i].nt!=gmr[i-1].nt)
			//	{
			//		gmrr[ccount++].tt.push_back("/"+gmr[i].t[j]);
			//	}
			}
			if(gmr[i].nt!=gmr[i+1].nt)
				fp<<"\n";
			//fp<<'\n';
		} 
		fp<<"\n";
		//fp<<non_count<<'\n';
		/*for(int i=0;i<non_count;i++)
		{
			fp<<gmrr[i].ntt;
			for(int j=0;j<ccount;j++)
			{
				fp<<gmrr[i].tt[j];
			}
			fp<<'\n';
		}
		//fp<<"qq"<<endl;*/
		fp.close();
		system("pause");
		//fp.close();
		printf("Input file name:(xxx.txt) or exit the program(exit):");
		//fp.close();
	}
	
	return 0; 
}
