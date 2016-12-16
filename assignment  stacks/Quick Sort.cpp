#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
int partition(int *a,int low,int high)
{
	int l,h,p;
	l=low+1;
	h=high;
	p=a[low];
	while(l<=h)
	{
		while(a[l]<p)
		l++;
		while(a[h]>p)
		h--;
		if(h>l)
		swap(a[h],a[l]);
	}
	if(low<h)
	{
		swap(a[low],a[h]);
	}
	return h;
}
void quick_sort(int *a,int low,int high)
{
	if(low<high)
	{
		int j;
		j=partition(a,low,high);
		quick_sort(a,low,j-1);
		quick_sort(a,j+1,high);
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
	int low,high;
	low=0;
	high=n-1;
	quick_sort(a,low,high);
	cout<<endl<<"QUICK SORTED ARRAY IS : ";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}

