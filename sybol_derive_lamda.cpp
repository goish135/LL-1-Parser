#include<iostream>
#include<vector>
#include<string.h>

int total,g; 
int b;

int r;
int n,c;
int p[2];

using namespace std;

void fun(int,int[]);
int fun2(int i,int j,int p[],int);

int de[1000]; 
int sbl[1000];

void dlamda(void);
void sd(void); // symbol derive lamda

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
	freopen("input_2.txt","r",stdin);
	freopen("output_2.txt","w",stdout);
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
		sd();
		dlamda();
		total = 0;
		int rr=0;
		for(int m=0;m<count;m++)
		{
			g = m;
			b = 0; 
			//total  = 0;
			c = -1,p[0]=-1,p[1]=-1;
			fun(m,p);
		
			 
			for(int i=0;i<b_record.size();i++)
			{
				if((i+1)<b_record.size())
				{
					for(int j=b_record[i];j<b_record[i+1];j++)
					{
						
						fxs[rr].vv.push_back(temp[j]);
					}
				}
				else if((i+1)==b_record.size())
				{
					
					for(int k=b_record[i];k<temp.size();k++)
					{
						
						fxs[rr].vv.push_back(temp[k]);
					}
				}
			
				rr++;
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
		
			for(int bb=0;bb<fxs[aa].vv.size();bb++)
			{
				cout<<fxs[aa].vv[bb]<<" ";
			}
			cout<<endl;
		}
		for(int zz=0;zz<rr;zz++)
		{
				fxs[zz].vv.clear();
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
					//total++;
					//printf("total:%d\n\n",total);
					//if(de[total-1]==0) 
						//printf("%d check\n",total-1);
						
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
					//cout<<"i: "<<i<<" "<<"j: "<<j<<'\n';
					//cout<<"notice:  "<<i<<j<<endl<<endl; 
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
						if(mark_2==1)//
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
		//cout<<"i: "<<i<<"j: "<<endl;
		//cout<<"p[0]:"<<p[0]<<"p[1]:"<<p[1]<<endl;
		
		int k;
		if(!key)
		{
			
			for(k=0;k<n;k++)
			if(gmr[i].vt[j]==gmr[k].vt[0])
				break;
		
			p[0]=i,p[1]=j+1;
			//cout<<"apple"<<p[0]<<" "<<p[1]<<endl;
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
	
	void dlamda()
	{
	
		for(int i=0;i<1000;i++)
		{
			de[i] = 0;
		}
			
		int cc = -1;
		for(int i=0;i<n;i++)			
		{
			for(int j=1;j<gmr[i].vt.size();j++)
			{ 
				if(gmr[i].vt[j]=="/") cc++;
				
				if(gmr[i].vt[j]!="/") 
				{
					int mk=0;
					for(int k=0;k<n;k++)
					{
						if(gmr[k].vt[0]==gmr[i].vt[j])
						{
							mk = 1;
							break;
						}
					}
					if(mk==0&&gmr[i].vt[j]!="lamda") 
					{
						de[cc] = 1;
					}	
				}	
			}
		}
	
		for(int i=0;i<=cc;i++)
		{
			cout<<"rule:"<<i+1<<endl;
			if(de[i]==1) cout<<"No"<<endl;  
			else cout<<"Yes"<<endl;
		
		}
	}
	
void sd()
{
	for(int z=0;z<1000;z++)
	{
		sbl[z] = 0;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=2;j<gmr[i].vt.size();j++)
		{
			if(gmr[i].vt[j]=="lamda")
				sbl[i] = 1 ; // derive lamda 
		}	
	}
	
	for(int i=0;i<n;i++)
	{
		if(sbl[i]==0)
		{
			int key = 0;
			int kk = 0 ;
			for(int j=2;j<gmr[i].vt.size();j++)
			{
				if(gmr[i].vt[j]=="/")
				{
					if(kk==1) break;
					else
					{
						kk=1;
						continue;
					}
				}
				key = 0;
				//kk = 1;
				for(int k=0;k<n;k++)
				{
					if(gmr[k].vt[0]==gmr[i].vt[j]&&sbl[k]==1) 
					{
						key=1;
						break;
					}
				}	
				if(key!=1) kk=0;
				
			}
			if(kk==1) sbl[i] = 1;
		}
	}
	
	
	for(int k=0;k<n;k++)
	{
		if(sbl[k]==1) cout<<"derive lamda"<<endl;
		else cout<<"No derive lamda"<<endl;
	}
		
}	 
