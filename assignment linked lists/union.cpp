#include<iostream>
using namespace std;
union data
{
	int num;
    float a;
};
int main()
{
	data d;
	cout<<"enter number  ";
	cin>>d.num;
	cout<<d.num<<endl;
	d.a=3.503;
	cout<<d.num<<"  "<<d.a;
	return 0;
}
