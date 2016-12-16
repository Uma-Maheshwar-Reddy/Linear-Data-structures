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
void merge(ifstream &b1,ifstream &b2,ofstream &a1,ofstream &a2,int ind,int say,int a[],int b[],int c[])
{
	if(ind==0)
	{
		return;
	}
	char k1[5],k2[5];
	int f=1;
	int p=0;
	int i,j;
	while(p<ind)
	{
		i=0,j=0;
		p++;
		b1>>k1;
		b2>>k2;
		cout<<"takes "<<k1<<" "<<k2<<endl;
		while(k1[0]!='#'&&k2[0]!='#')
		{	
			a[i]=atoi(k1);
			b[j]=atoi(k2);
			i++,j++;
			b1>>k1;
			b2>>k2;
			cout<<"taking "<<k1<<" "<<k2<<endl;
		}
		int sa,sb;
		sa=i;
		sb=j;
		int k=0;
		i=0;j=0;
		while(i<sa||j<sa)
		{
			if(i>=sa)
			{
				while(j<sb)
				{
					c[k++]=b[j++];
				}
			}
			else
			if(j>=sb)
			{
				while(i<sa)
				{
					c[k++]=a[i++];
				}
			}
			else
			{
				if(a[i]<b[j])
				{
					c[k++]=a[i++];
				}
				else
				{
					c[k++]=b[j++];
				}
			}
		}
		int sc;
		sc=k;
		if(f)
		{
			for(int i=0;i<sc;i++)
			{
				a1<<c[i]<<" ";
			}
			a1<<"# ";
			f--;
		}
		else
		{
			for(int i=0;i<sc;i++)
			{
				a2<<c[i]<<" ";
			}
			
			a2<<"# ";
			f++;
		}
	}
	a1.close();
	a2.close();
	b1.close();
	b2.close();
	cout<<endl;
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
	merge(b1,b2,a1,a2,ind/2,say,a,b,c);
}
void merg(ifstream &b1,ifstream &b2,ofstream &a1,ofstream &a2,int ind,int say)
{
	if(ind==0)
	{
		return;
	}
	char k1[5],k2[5];
	int f=1;
	int a[3],b[3],c[6];
	int p=0;
	int i,j,h=0;
	while(p<ind)
	{
		i=0,j=0;
		p++;
		if((k1[0]=='#'&&k2[0]=='#')||h==0)
		{
			b1>>k1;
			b2>>k2;
			cout<<"takes "<<k1<<" "<<k2<<endl;
			h++;
		}
		while(k1[0]!='#'&&k2[0]!='#')
		{	
			if(i<3&&j<3)
			{
				a[i]=atoi(k1);
				b[j]=atoi(k2);
				i++,j++;
			}
			else
			{
				break;
			}
			b1>>k1;
			b2>>k2;
			cout<<"taking "<<k1<<" "<<k2<<endl;
		}
		cout<<"end of loop"<<endl;
		cout<<"A : ";
		for(int z=0;z<3;z++)
		{
			cout<<a[z]<<" ";
		}
		cout<<"\n\nB : ";
		for(int z=0;z<3;z++)
		{
			cout<<b[z]<<" ";
		}
		int k=0;
		i=0;j=0;
		while(i<3||j<3)
		{
			if(i>=3)
			{
				while(j<3)
				{
					c[k++]=b[j++];
				}
			}
			else
			if(j>=3)
			{
				while(i<3)
				{
					c[k++]=a[i++];
				}
			}
			else
			{
				if(a[i]<b[j])
				{
					c[k++]=a[i++];
				}
				else
				{
					c[k++]=b[j++];
				}
			}
		}
		cout<<"\n\n";
		for(int i=0;i<6;i++)
		{
			cout<<c[i]<<" ";
		}
		cout<<"\n\n";
		if(f)
		{
			for(int i=0;i<6;i++)
			{
				a1<<c[i]<<" ";
			}
			a1<<"# ";
			f--;
		}
		else
		{
			for(int i=0;i<6;i++)
			{
				a2<<c[i]<<" ";
			}
			
			a2<<"# ";
			f++;
		}
	}
	a1.close();
	a2.close();
	b1.close();
	b2.close();
	cout<<endl;
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
	merg(b1,b2,a1,a2,ind/2,say);
}
int main()
{
	char q;
	char num[5];
	int arr[3];
	ifstream fin;
	ofstream a1,a2;
	fin.open("data.txt");
	a1.open("f1.txt");
	a2.open("f2.txt");
	int i=0,c=0;
	int j=0;
	int ind=0;
	while(!fin.eof())
	{
		fin>>q;
		if(q=='|')
		{
			num[i]='\0';
			i=0;
			arr[j]=atoi(num);
			//cout<<"a: "<<arr[j]<<" j: "<<j<<endl;
			if(j==2)
			{
				sort(arr);
				if(c)
				{
					a2<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" # ";
					c--;
					ind++;
				}
				else
				{
					a1<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" # ";
					c++;
				}
				j=0;
			}
			else
			j++;
		}
		else
		{
			num[i]=q;
			i++;
		}
	}
	cout<<"ind: "<<ind<<endl;
	fin.close();
	a1.close();
	a2.close();
	a1.open("f11.txt");
	a2.open("f22.txt");
	ifstream b1,b2;
	b1.open("f1.txt");
	b2.open("f2.txt");
	int a[30],b[30],res[60];
	merge(b1,b2,a1,a2,ind,1,a,b,res);
	return 0;
}

