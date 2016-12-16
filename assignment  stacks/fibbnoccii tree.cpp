#include<iostream>
using namespace std;
typedef
struct node
{
	int data;
	node* lchild;
	node* rchild;
}*fptr;
int fibb(int n)
{
	if(n==0||n==1)
	{
		return 1;
	}
	else
	{
		return fibb(n-1)+fibb(n-2);
	}
}
fptr create(fptr h,int n)
{
	if(fibb(n)==0||fibb(n)==1)
	{
		h=new node;
		h->data=1;
		h->lchild=NULL;
		h->rchild=NULL;
	}
	else
	{
		h=new node;
		h->lchild=NULL;
		h->rchild=NULL;
		h->lchild=create(h->lchild,fibb(n-1));
		h->rchild=create(h->rchild,fibb(n-2));
		h->data=h->lchild->data+h->rchild->data;
	}
	return h;
}
void print(fptr h)
{
	if(h!=NULL)
	{
		cout<<h->data<<" ";
		print(h->lchild);
		print(h->rchild);
	}
}
int main()
{
	fptr h;
	h=NULL;
	int n;
	cout<<"enter n ";
	cin>>n;
	cout<<"hello ";
	h=create(h,n);
	print(h);
	return 0;
}
