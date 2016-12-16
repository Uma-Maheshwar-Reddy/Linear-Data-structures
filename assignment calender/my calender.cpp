#include<iostream>
using namespace std;
int firstday(int y)
{
	int d=y;
	y=y%100;
	y=y/4;
	y+=2;
	if((d%400==0)||((d%4==0)&&(d%100!=0)))
	y--;
     y=y+6;
	y=y+(d%100);
	y=y%7;
	if(y==0) y=7;
	return y;
}
void printmonth(int x)
{
	cout<<endl<<"________________________";
	if(x==1) cout<<endl<<"JANUARY"<<endl;
	if(x==2) cout<<endl<<"FEBRUARY"<<endl;
	if(x==3) cout<<endl<<"MARCH"<<endl;
	if(x==4) cout<<endl<<"APRIL"<<endl;
	if(x==5) cout<<endl<<"MAY"<<endl;
	if(x==6) cout<<endl<<"JUNE"<<endl;
	if(x==7) cout<<endl<<"JULY"<<endl;
	if(x==8) cout<<endl<<"AUGUST"<<endl;
	if(x==9) cout<<endl<<"SEPTEMBER"<<endl;
	if(x==10) cout<<endl<<"OCTOBER"<<endl;
	if(x==11) cout<<endl<<"NOVEMBER"<<endl;
	if(x==12) cout<<endl<<"DECEMBER"<<endl;
}
int max(int x,int y)
{
	if(x==1||x==3||x==5||x==7||x==8||x==10||x==12) return 31;
	else if(x==4||x==6||x==9||x==11) return 30;
	else if(x==2){
		if(y%4==0) return 29;
		else return 28;
	}
}
void printcal(int day1,int year)
{
	int month;
	int day;
	cout<<endl;
	for(int month=1;month<=12;month++)
	{
		printmonth(month);
		cout<<"S  M  T  W  T  F  S"<<endl;
		int maxdate;
		maxdate=max(month,year);
		for(int i=0;i<(3*day1-3);i++)
			cout<<" ";
		for(int day=1;day<=maxdate;day++)
		{
			if(day<9) {cout<<day<<"  ";day1++;if(day1==8) {
			cout<<endl;day1=1;}}
			else {cout<<day<<" ";day1++;if(day1==8) {
				cout<<endl;day1=1;
			}}
			
		}
	}
}
int main()
{
	int year;
	cout<<"enter the year you want a calender for ";
	cin>>year;
	int day1;
	day1=firstday(year);
	printcal(day1,year);
}
