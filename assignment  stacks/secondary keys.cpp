#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
int read(ifstream &fin,int &off,char name[])
{
	char buff[30];
	char x;
	int i=0;
	off=fin.tellg();
	fin>>x;
	while(x!='#')
	{
		if(x=='$')
		{
			return -1;
		}
		buff[i]=x;
		i++;
		fin>>x;
	}
	buff[i]='\0';
	i=0;
	int k=0;
	while(buff[i]!='|')
	{
		name[k]=buff[i];
		i++;k++;
	}
	i++;
	name[k]='\0';
	char num[5];
	int j=0;
	while(buff[i]!='|')
	{
		num[j++]=buff[i++];
	}
	num[j]='\0';
	return atoi(num);
}
int main()
{
	ifstream fin;
	fin.open("records.txt");
	ofstream f1,f2;
	f1.open("pri_keys.txt");
	f2.open("sec_keys.txt");
	int key,off;
	char name[10];
	while(key!=-1)
	{
		key=read(fin,off,name);
		if(key!=-1)
		{
			f2<<name<<"|"<<key<<"#";
			f1<<key<<"|"<<off<<"#";	
		}
	}
	f1.close();
	f2.close();
	fin.close();
	return 0;
}
