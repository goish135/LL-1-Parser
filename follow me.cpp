#include<iostream>
#include<vector>
#include<string.h>

int total,g; 
int b;

int r;
int n,c;
int p[2];
int flag;
using namespace std;

void fun(int,int[]);
int fun2(int i,int j,int p[],int);

int de[1000]; 
int sbl[1000];

void dlamda(void);
void sd(void); // symbol derive lamda
void fw(int,int);

vector<string> temp;
vector<int> b_record;

struct A{
	vector<string> vt;
};

struct C{
	vector<string> vv;
};

//vector<string> nt; // nonterminal's first set
 
struct D{
	vector<string> f_s;
};

struct E{
	vector<string> all;
};

struct F{
	vector<int> rule;
};

struct G{
	vector<string> fls;
};

A gmr[1000];
C fxs[1000];
D re[1000];
E nt[1000];
F mch[1000];
G rle[1000];

int main()
{
	freopen("input_2.txt","r",stdin);
	freopen("output_10.txt","w",stdout);
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
		dlamda(); // ->rule-> symbol -> symbol back -> follow ...
		int tt=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<gmr[i].vt.size();j++)
			{
				if(gmr[i].vt[j]=="/")
				{
					cout<<i<<" "<<tt<<endl;
					mch[i].rule.push_back(tt);
					tt++;
				}
			}	
		}
		cout<<"mch"<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<mch[i].rule.size();j++)
			{
				cout<<mch[i].rule[j]<<" ";
			}
			cout<<endl;
		}
		/*
		for(int i=0;i<tt-1;i++)
		{
			if(de[i]==0) // derive lamda
			{
				for(int j=0;j<n;j++)
				{
					int lock = 0;
					for(int k=0;k<mch[j].rule.size();k++)
					{
						if(i==mch[j].rule[k])
						{
							cout<<"rule: "<<i+1<<"<->"<<"symbol: "<<j+1<<endl;
							lock = 1;
							break;
						}
					}
					if(lock==1) break;
				}
			}
		}
		*/
		total = 0;
		int rr=0;
		for(int m=0;m<count;m++)
		{
			g = m;
			b = 0; 
			//total  = 0;
			c = -1,p[0]=-1,p[1]=-1;
			fun(m,p);
			
			//int len=0;
			
			for(int i=0;i<temp.size();i++)
			{
				nt[m].all.push_back(temp[i]);
				//len++;	
			}
			
			/*cout<<len<<endl;
			system("pause");
			cout<<nt[0].all.size()<<endl;
			system("pause");*/
			
			// test nt //
			for(int j=0;j<temp.size();j++)
			{
				cout<<nt[m].all[j]<<" ";
			}
			cout<<'\n';	
			//
			 
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
		//
		for(int i=0;i<tt-1;i++)
		{
			if(de[i]==0) // derive lamda
			{
				for(int j=0;j<n;j++)
				{
					int lock = 0;
					for(int k=0;k<mch[j].rule.size();k++)
					{
						if(i==mch[j].rule[k])
						{
							cout<<"rule: "<<i+1<<"<->"<<"symbol: "<<j+1<<endl;
							lock = 1;
							fw(j,i); // ��Xfollow set 
							break;
						}
					}
					if(lock==1) break;
				}
			}
		}
		//
		
		//
		/*for(int i=0;i<tt-1;i++)
		{
			if(rle[i].fls.size()!=0)
			/*for(int j=0;j<rle[i].fls.size();j++)
			{
				for(int k=j+1;k<rle[i].fls.size();k++)
				{
					if(rle[i].fls[j]==rle[i].fls[j]) // the same element => erase
					{
							rle[i].fls.erase();
					}	
				}	
			}*/
		/*	{
				for(vector<string>::iterator iter=rle[i].fls.begin();iter!=rle[i].fls.end();iter++)
				{
					for(vector<string>::iterator iter_2=rle[i].fls.begin()+1;iter_2!=rle[i].fls.end();iter_2++)
					if(*iter_2==*iter)
					{
						rle[i].fls.erase(iter_2);	
					}	
				}	
			}	
		}	*/	
		
		//
		
		//
		for(int i=0;i<tt-1;i++)
		{
			if(rle[i].fls.size()!=0)
			{
				cout<<"R: "<<i+1<<endl;
				for(int j=0;j<rle[i].fls.size();j++)
				{
					cout<<rle[i].fls[j]<<" ";
				}
			}
			cout<<endl;
		}
		//
		cout<<endl;
		
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
		
		for(int aa=0;aa<n;aa++)
		{
			mch[aa].rule.clear();
			nt[aa].all.clear();
		}
		
		for(int bb=0;bb<rr;bb++)
		{
			rle[bb].fls.clear();
		}
		
	
	}

	return 0;
}
	void fun(int i,int p[])
	{
		//p[0]=-1,p[1]=-1
		
		int j,k,key;
		for(j=2;j<gmr[i].vt.size();j++)
		{
			//int flag = 0;
			
			//if(g==i)
			//{
				//flag =0 ;
			//}
			
			if(gmr[i].vt[j-1]=="/"||flag==1) //
			{
				
				//cout<<"scan: "<<gmr[i].vt[j]<<endl;
				//
				if(flag==1)
				{
					p[0] = -1;
					p[1] = j ;
					//cout<< "j:" << j << endl;
					//cout<<"scan: "<<gmr[i].vt[j]<<endl;	
				}
				//
				
				if(g==i&&flag!=1) 
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
					    if(gmr[i].vt[j]!="lamda"&&gmr[i].vt[j]!="/")
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
								if(gmr[p[0]].vt[p[1]]!="lamda"&&gmr[p[0]].vt[p[1]]!="/")
								{
									temp.push_back(gmr[p[0]].vt[p[1]]);
									++c;
								}
							}
						}
					}	
				}
				
				int key_1,key_2;
				
				if(j<gmr[i].vt.size()&&g==i)
				{
					 key_1 = 0;
					 key_2 = 0;
				
					for(int ct=0;ct<n;ct++)
					{
						if(gmr[i].vt[j]==gmr[ct].vt[0])
						{
							key_1=1;
							key_2=ct;
						}
					}
				}	
				
				//
				if(key_1==1&&sbl[key_2]==1&&g==i)
				{
					//cout<<"g:"<<g<<endl;
					//cout<<"look here"<<endl;
					//cout<<key_2<<endl;
					//cout<<gmr[key_2].vt[0]<<endl;
					flag=1;
					//cout<<flag<<endl;
					//cout<<"look there"<<endl;
				}
				else if(g==i)
				{
					flag=0;
				}	
				//
					
			} // end if 
			
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

void fw(int j,int r2) // r2 : rule#
{
	//cout<<"j: "<<j<<endl;
	//cout<<gmr[j].vt[0]<<endl<<endl;
	for(int i=0;i<n;i++)
	{
		//cout<<"test 123"<<endl;
		int behind=0;
		for(int k=2;k<gmr[i].vt.size();k++)
		{
			if(gmr[j].vt[0]==gmr[i].vt[k]||behind==1)
			{
				//cout<<
				//cout<<"qqq"<<gmr[i].vt[k]<<endl<<endl;
				behind = 0;
				if(k+1<gmr[i].vt.size())
				{
					int symbol;
					cout<<"back "<<gmr[i].vt[k+1]<<endl;
					
					
					//if(gmr[i].vt[k+1]=="lamda"||gmr[i].vt[k+1]=="/") // 
					if(gmr[i].vt[k+1]=="lamda")
					{
						if(i!=j) 
						 fw(i,r2);	
					}
					
					int have = 0;
					for(int wq=0;wq<n;wq++)
					{
						if(gmr[wq].vt[0]==gmr[i].vt[k+1])
						{
							have = 1;
							symbol=wq;
						}
					} 
					if(have==0) 
					{
						if(gmr[i].vt[k+1]!="lamda"&&gmr[i].vt[k+1]!="/")
						{
							int d=0;
							for(int ok=0;ok<rle[r2].fls.size();ok++)
							{
								if(gmr[i].vt[k+1]==rle[r2].fls[ok])
								{
									d = 1;
									break;	
								}
							}
							if(d==0)
							{
								rle[r2].fls.push_back(gmr[i].vt[k+1]);
							}
							
							cout<<"add "<<gmr[i].vt[k+1]<<endl;
						}
					}
					else
					{
						for(int jj=0;jj<nt[symbol].all.size();jj++)
						{
							int d_2=0;
							for(int ok=0;ok<rle[r2].fls.size();ok++)
							{
								if(nt[symbol].all[jj]==rle[r2].fls[ok])
								{
									d_2 = 1;
									break;	
								}
							}
							
							if(d_2==0)
							{
								rle[r2].fls.push_back(nt[symbol].all[jj]);
							}
							cout<<"add: "<< nt[symbol].all[jj]<<endl; 
						}
						if(sbl[symbol]==1)
						{
							//fw(symbol,r2);
							behind=1;
							continue;
						}
						else
							behind=0;
					}
				}
				else if(k+1==gmr[i].vt.size()){
					cout<<"the end"<<"\n";
					cout<<gmr[i].vt[k]<<"can do it"<<endl;
					cout<<i+1<<" "<<r2+1<<endl;
					fw(i,r2);
				}
			}
		}
		//cout<<"test 321"<<endl;	
	}		
}	
 
