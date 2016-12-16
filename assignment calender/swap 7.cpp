#include<iostream>
using namespace std;
void swap(int *x,int &y);
int main()
{
	int a=1,b=3;
	cout<<a<<" "<<b<<endl;
	swap(&a,b);
	cout<<a<<" "<<b;
	return 0;
}
void swap(int *x,int &y)
{
	int t;
	t=*x;
	*x=y;
	y=t;
}
