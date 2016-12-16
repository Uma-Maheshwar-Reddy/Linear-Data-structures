#include<iostream>
using namespace std;
void insertion_sort(int *a,int n)
{
	int i,j,p;
	int k;
	for(i=0;i<n-1;i++)
	{
		p=0;
		j=i+1;
		k=a[j];
		while(p<=i)
		{
			if(a[p]>a[j])
			{
				break;
			}
			p++;
		}
		if(p<=i)
		{
			for(int t=i+1;t>p;t--)
			{
				a[t]=a[t-1];
			}
			a[p]=k;
		}
	}
}
int main()
{
	int *a;
	int n;
	cout<<"enter the number of elements ";
	cin>>n;
	a=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	insertion_sort(a,n);
	cout<<endl<<"insertion SORTED ARRAY IS : ";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
