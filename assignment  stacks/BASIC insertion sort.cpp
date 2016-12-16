#include<iostream>
using namespace std;
void print(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";    
    }
    cout<<endl;
}
bool is_sorted(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        return 0;
    }
    return 1;
}
void insertionSort(int *arr,int n,int sz) 
{
    if(n==sz-1||is_sorted(arr,sz))
    {
    	reeturn;
	}
	for(int i=0;i<)
}
int main(void) {
    int *a;
    int n;
    cin>>n;
    a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    insertionSort(a,1,n);
    return 0;
}
