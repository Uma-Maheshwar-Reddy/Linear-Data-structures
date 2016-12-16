#include<iostream>
using namespace std;
typedef
struct node
{
	int data;
	struct node* n1;
	struct node* n2;
	struct node* n3;
}*nptr;
nptr create()
{
	nptr head;
	head=NULL;
	int num;
	cout<<"enter data ";
	cin>>num;
	head=new node;
	head->data=num;
	int n;
	cout<<"how many branches 1 or 2 or 3";
	cin>>n;
	if(n==-1)
	{
		head->n1=NULL;
		head->n2=NULL;
		head->n3=NULL;
		return head;
	}
	if(n==1)
	{
		head->n2=NULL;
		head->n3=NULL;
		cout<<"enter the data about first branch "<<endl;
		head->n1=create();
	}
	else
	if(n==2)
	{
		head->n3=NULL;
		cout<<"enter data about first branch"<<endl;
		head->n1=create();
		cout<<"enter data about second branch "<<endl;
		head->n2=create();
	}
	else
	if(n==3)
	{
		cout<<"enter data about first branch"<<endl;
		head->n1=create();
		cout<<"enter data about second branch"<<endl;
		head->n2=create();
		cout<<"enter data about third branch"<<endl;
		head->n3=create();
	}
}
void print(nptr head)
{
	if(head==NULL)
	{
		return;
	}
	cout<<head->data<<" ";
	print(head->n1);
	print(head->n2);
	print(head->n3);
}
int main()
{
	nptr head;
	head=create();
	print(head);
}
