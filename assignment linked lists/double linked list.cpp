#include<iostream>
using namespace std;
typedef
struct node
{
	int data;
	struct node* prev;
	struct node* next;
}*dptr;
void addend(dptr &d,int &a)
{
	dptr t=d;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=new node;
	t->next->data=a;
	t->next->next=NULL;
	t->next->prev=t;
	t=t->next;
}
void addbegin(dptr &d,int &a)
{
	d->prev=new node;
	d->prev->data=a;
	d->prev->next=d;
	d->prev->prev=NULL;
	d=d->prev;
}
void print(dptr d)
{
	dptr t=d;
	while(t!=NULL)
	{
		cout<<t->data<<"  ";
		t=t->next;
	}
}
int main()
{
	dptr d;
	d=NULL;
	int a;
	cout<<"enter num -1 to end";
	cin>>a;
	if(a!=-1)
	{
		d=new node;
		d->data=a;
		d->next=NULL;
		d->prev=NULL;
	}
	cout<<"enter the data";
	cin>>a;
	while(a!=-1)
	{
		addend(d,a);
		cout<<"enter data";
		cin>>a;
	}
	print(d);
	cout<<"enter data to add at begin"<<endl;
	cin>>a;
	addbegin(d,a);
	print(d);
	return 0;
}
