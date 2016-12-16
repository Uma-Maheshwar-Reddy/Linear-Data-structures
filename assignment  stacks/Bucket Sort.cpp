#include<iostream>
using namespace std;
int main()
{
	int arr[11];
	for(int i=0;i<11;i++)
	arr[i]=0;
	int k;
	cin>>k;
	while(k!=-1)
	{
		arr[k]++;
		cin>>k;
	}
	cout<<"sorted ";
	for(int i=0;i<11;i++)
	{
		if(arr[i]!=0)
		{
			cout<<i<<" ";
		}
	}
	return 0;
}
