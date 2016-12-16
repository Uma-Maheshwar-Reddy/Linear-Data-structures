#include<iostream>
using namespace std;
void merge(int *a,int* ex,int lo,int mid,int hi)
{
	for(int i=lo;i<=hi;i++)
	{
		ex[i]=a[i];
	}
	int i,j,k;
	i=lo;
	j=mid+1;
	for(k=lo;k<=hi;k++)
	{
		if(i>mid) a[k]=ex[j++];
		else
		if(j>hi) a[k]=ex[i++];
		else
		if(ex[i]<ex[j]) a[k]=ex[i++];
		else
		a[k]=ex[j++];
	}
}
void merge_sort(int* a,int *ex,int lo,int hi)
{
	if(hi<=lo) return;
	int mid=(lo+hi)/2;
	merge_sort(a,ex,lo,mid);
	merge_sort(a,ex,mid+1,hi);
	merge(a,ex,lo,mid,hi);
}
int main()
{
	int *a;
	int *ex;
	int n;
	cout<<"enter the number of elements ";
	cin>>n;
	a=new int[n];
	ex=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int low,high;
	low=0;
	high=n-1;
	merge_sort(a,ex,low,high);
	cout<<endl<<"MERGE SORTED ARRAY IS : ";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
