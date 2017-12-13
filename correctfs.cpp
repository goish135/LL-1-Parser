#include<iostream>
#include<vector>
#include<string.h>

int total,g; // ²Äth '/' ²Äth 'grammar' 
int b; // begin index
//vector<string> fs; // answer

//vector<string> b_record;

int r;
int n,c;
int p[2];
//vector<string> b_record;
using namespace std;

void fun(int,int[]);
int fun2(int i,int j,int p[],int);
//vector<string> vt;
vector<string> temp;
vector<int> b_record;

struct A{
	vector<string> vt;
};

struct C{
	vector<string> vv;
};

struct D{
	vector<string> f_s;
};

A gmr[1000];
C fxs[1000];
D re[1000];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	char cc[1000];
	while(cin>>n&&n!=0)
	{
		r = 0;
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
				ptr=strtok(NULL,de);
			} 
			count++;
		}
		int rr=0;
		for(int m=0;m<count;m++)
		{
			g = m;
			b = 0; // begin index
			total  = 0;
			c = -1,p[0]=-1,p[1]=-1;
			fun(m,p);
			int cclemon = 0; // rule ªº index
			 
			for(int i=0;i<b_record.size();i++)
			{
				if((i+1)<b_record.size())
				{
					for(int j=b_record[i];j<b_record[i+1];j++)
					{
						
						fxs[cclemon].vv.push_back(temp[j]);
					}
				}
				else if((i+1)==b_record.size())
				{
					
					for(int k=b_record[i];k<temp.size();k++)
					{
						
						fxs[cclemon].vv.push_back(temp[k]);
					}
				}
				cclemon++;
			}
			
		
			for(int ok=0;ok<cclemon;ok++)
			{
				
			
				for(int ook=0;ook<fxs[ok].vv.size();ook++)
				{
				
					re[rr].f_s.push_back(fxs[ok].vv[ook]);
				}
			
				rr++;
			
			}
			
		
			
			for(int zz=0;zz<cclemon;zz++)
			{
				fxs[zz].vv.clear();
			}
		
			
			temp.clear();
			b_record.clear();	
		}
		
		for(int k=0;k<count;k++)
		{
			gmr[k].vt.clear();
		}
		
		for(int aa=0;aa<rr;aa++)
		{
			cout<<"rule"<<aa+1<<endl;
		
			for(int bb=0;bb<re[aa].f_s.size();bb++)
			{
				cout<<re[aa].f_s[bb]<<" ";
			}
			cout<<endl;
		} 
		
		for(int e=0;e<rr;e++)
		{
			re[e].f_s.clear();
		}
	}

	return 0;
}
	void fun(int i,int p[])
	{
		int j,k,key;
		for(j=2;j<gmr[i].vt.size();j++)
		{
			if(gmr[i].vt[j-1]=="/")
			{
				if(g==i) 
				{
					total++;
					r++;
					if(temp.size()!=0)
					b = temp.size();
				
					b_record.push_back(b);				
				}
				int mark = 0;
				for(int ct=0;ct<n;ct++)
				{
					if(gmr[i].vt[j]==gmr[ct].vt[0])
					{
						mark=1;
					}
				}
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
						string str = gmr[i].vt[j];
					    if(gmr[i].vt[j]!="lamda")
					    { 
							temp.push_back(str);
							++c;
						}		
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
	

