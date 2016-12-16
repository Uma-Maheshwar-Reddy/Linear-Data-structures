#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
void sort(int arr[])
{
	int t;
	for(int j=0;j<2;j++)
	{
		for(int i=0;i<2;i++)
		{
			if(arr[i]>arr[i+1])
			{
				t=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=t;
			}
		}
	}
}
void merge(ifstream& b1,ifstream &b2,ofstream &a1,ofstream &a2,int ind,int f,int say)
{
	if(ind==0)
	{
		return;
	}
	char k1[5],k2[5];
	int a,b;
	int x=0,y=0;
	while(!b1.eof()&&!b2.eof())
	{
		b1>>k1;
		b2>>k2;
		while(k1[0]!='#'||k2[0]!='#')
		{
			if(k1[0]=='#')
			{
				if(f)
				{
					a1<<k2<<" ";
					x++;
				}
				else
				{
					a2<<k2<<" ";
					y++;
				}
				b2>>k2;
			}
			else
			if(k2[0]=='#')
			{
				if(f)
				{
					a1<<k1<<" ";
					x++;
				}
				else
				{
					a2<<k1<<" ";
					y++;
				}
				b1>>k1;
			}
			else
			{
				a=atoi(k1);
				b=atoi(k2);
				if(a<b)
				{
					if(f)
					{
						a1<<a<<" ";
						x++;
					}
					else
					{
						a2<<a<<" ";
						y++;
					}
					b1>>k1;
				}
				else
				{
					if(f)
					{
						a1<<b<<" ";
						x++;
					}
					else
					{
						a2<<b<<" ";
						y++;
					}
					b2>>k2;
				}
			}
		}
		if(f)
		{
			a1<<"# ";
		}
		else
		{
			a2<<"# ";
		}
		if(f) f--;
		else f++;
	}
	a1.close();
	a2.close();
	b1.close();
	b2.close();
	if(say)
	{
		a1.open("f1.txt");
		a2.open("f2.txt");
		b1.open("f11.txt");
		b2.open("f22.txt");
		say--;
		
	}
	else
	{
		b1.open("f1.txt");
		b2.open("f2.txt");
		a1.open("f11.txt");
		a2.open("f22.txt");
		say++;
	}
	merge(b1,b2,a1,a2,ind/2,1,say);
}
int partition(ifstream &fin,ofstream &a1,ofstream &a2,int f)
{
	char num[5];
	int arr[3];
	fin>>num;
	arr[0]=atoi(num);
	fin>>num;
	arr[1]=atoi(num);
	fin>>num;
	arr[2]=atoi(num);
	sort(arr);
	int prev=-1;
	int ind=0;
	while(!fin.eof())
	{
		if(arr[0]>prev)
		{
			if(f)
			a1<<arr[0]<<" ";
			else
			a2<<arr[0]<<" ";
			prev=arr[0];
			arr[0]=-1;
			if(!fin.eof())
			{
				fin>>num;
				arr[0]=atoi(num);
			}
			sort(arr);
		}
		else
		{
			if(f)
			{
				a1<<arr[1]<<" "<<arr[2]<<" # ";
				f--;	
			}
		
			else
			{
				a2<<arr[1]<<" "<<arr[2]<<" # ";
				f++;	
			}
			ind++;
			arr[1]=-1;
			arr[2]=-1;
			prev=-1;
			if(!fin.eof())
			{
				fin>>num;
				arr[1]=atoi(num);
			}
			if(!fin.eof())
			{
				fin>>num;
				arr[2]=atoi(num);
			}
			sort(arr);
		}
	}
	int c=0;
	if(arr[2]!=-1)
	{
		if(f)
		a1<<arr[2]<<" ";
		else
		a2<<arr[2]<<" ";
		c++;
	}
	if(c!=0)
	{
		if(f)
		a1<<"# ";
		else
		a2<<"# ";
		ind++;
	}
	return ind;
}
int main()
{
	
	ifstream fin;
	ofstream a1,a2;
	fin.open("numbers.txt");
	a1.open("f1.txt");
	a2.open("f2.txt");
	int ind;
	ind=partition(fin,a1,a2,1);
	cout<<"ind :"<<ind; 
	fin.close();
	a1.close();
	a2.close();
	a1.open("f11.txt");
	a2.open("f22.txt");
	ifstream b1,b2;
	b1.open("f1.txt");
	b2.open("f2.txt");
	merge(b1,b2,a1,a2,ind,1,1);
	a1.close();
	a2.close();
	b1.close();
	b2.close();
	return 0;
}
