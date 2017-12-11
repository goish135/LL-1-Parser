#include<iostream>
#include<vector>
#include<string.h>
int n,c;
int p[2];
using namespace std;

void fun(int,int[]);
int fun2(int i,int j,int p[],int);
//vector<string> vt;
vector<string> temp;
struct A{
	vector<string> vt;
};
A gmr[1000];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	char cc[1000];
	while(cin>>n&&n!=0)
	{
	
		int tmp = n;
		getchar();
		int count = 0;
		while(cin.getline(cc,1000)&&tmp--)
		{
			char *de = " ";
			char *ptr;
			ptr = strtok(cc,de);
	
			while(ptr!=NULL)
			{
				gmr[count].vt.push_back(ptr);
				//cout<<count<<" "<<ptr<<'\n';
				ptr=strtok(NULL,de);
			} 
			count++;
		}
	
		//vector<string> temp;
		for(int m=0;m<count;m++)
		{
			c = -1,p[0]=-1,p[1]=-1;
			cout<<m<<endl;
			//cout<<endl;
			fun(m,p);
		
			for(int z=0;z<temp.size();z++)
				cout<<temp[z]<<" ";
			//getch();
			printf("\n\n");
			//system("pause");
			temp.clear();	
		}
		//gmr.vt.clear();
		for(int k=0;k<count;k++)
		{
			gmr[k].vt.clear();
		}
	}
	//cout<<count<<endl;
	/*for(int i=0;i<count;i++){
		for(int j=0;j<a[i].vt.size();j++)
		{
			cout<<i<<" "<<j<<endl;
			cout<<a[i].vt[j]<<endl<<endl;
		}
		cout<<'\n';	
	}*/
	return 0;
}
	void fun(int i,int p[])
	{
		
		
		int j,k,key;
		
		
		
		
		for(j=2;j<gmr[i].vt.size();j++)
		{
			
			
			if(gmr[i].vt[j-1]=="/")
			{
				
				int mark = 0;
				for(int ct=0;ct<n;ct++)
				{
					if(gmr[i].vt[j]==gmr[ct].vt[0])
					{
						mark=1;
					}
				}
				
				//if(gmr[i].vt[j]=="S"||gmr[i].vt[j]=="A"||gmr[i].vt[j]=="B")
				if(mark==1)
				{
					
					key = 0;
					fun2(i,j,p,key);
				}
				else 
				{
					key = 1;
					if(fun2(i,j,p,key))
					{
					
						//system("pause");
						//temp[++c] = gmr[i].vt[j];
						string str = gmr[i].vt[j];
					    if(gmr[i].vt[j]!="lamda")
					    { 
							temp.push_back(str);
							++c;
						}	
						//temp[++c].push_back(str);
						
					}
					if(gmr[i].vt[j]=="lamda"&&p[0]!=-1)
					{
						
						int mark_2 = 0;
						for(int ct=0;ct<n;ct++)
						{
							if(gmr[p[0]].vt[p[1]]==gmr[ct].vt[0])
							{
								mark_2=1;
							}
						}
						if(mark_2==1)
						//if(gmr[p[0]].vt[p[1]]=="S"||gmr[p[0]].vt[p[1]]=="A"||gmr[p[0]].vt[p[1]]=="B")
						{
							key =0 ;
							fun2(p[0],p[1],p,key);
						}
						else if(gmr[p[0]].vt[p[1]]!="/"&&p[1]<gmr[p[0]].vt.size())
						{
							if(fun2(p[0],p[1],p,key))
							{
								if(gmr[p[0]].vt[p[1]]!="lamda")
								{
									temp.push_back(gmr[p[0]].vt[p[1]]);
									++c;
								}
							}
						}
					}	
				}
			}
		} 
	}
	
	int fun2(int i,int j,int p[],int key)
	{
	
		int k;
		if(!key)
		{
			
			for(k=0;k<n;k++)
			if(gmr[i].vt[j]==gmr[k].vt[0])
				break;
		
			p[0]=i,p[1]=j+1;
			fun(k,p);
			return 0;		
		}
		else
		{
		
			for(k=0;k<=c;k++)
			{
				if(gmr[i].vt[j]==temp[k])
				break;
			}
			if(k>c) return 1;
			else return 0;
			
		}
	}
	

