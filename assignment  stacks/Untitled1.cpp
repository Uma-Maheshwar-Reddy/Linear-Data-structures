#include<iostream>
using namespace std;
typedef
struct node
{
	int data;
	struct node *next;
}*lptr;
void addend(lptr l,int a)
{
	lptr t=l;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=new node;
	t=t->next;
	t->data=a;
	t->next=NULL;
}
lptr create()
{
	lptr l1;
	l1=new node;
	l1->data=3;
	l1->next=NULL;
	addend(l1,8);
	addend(l1,4);
	addend(l1,9);
	addend(l1,6);
	return l1;
}
void print(lptr l)
{
	lptr t=l;
	while(t!=NULL)
	{
		cout<<t->data<<"  ";
		t=t->next;
	}
}
lptr make(lptr l1)
{
	lptr t,m;
	t=l1;
	m=new node;
	m->data=t->data;
	m->next=NULL;
	t=t->next;
	while(t!=NULL)
	{
		addend(m,t->data);
		t=t->next;
	}
	return m;
}
int main()
{
	lptr l1,l2,t1,t2;
	l1=create();
	l2=new node;
	l2->data=2;
	l2->next=NULL;
	addend(l2,5);
	t1=l1;
	t2=l2;
	while(t2->next!=NULL)
	{
		t2=t2->next;
	}
	while(t1->next->next!=NULL)
	{
		t1=t1->next;
	}
	t2->next=t1;
	print(l1);
	cout<<endl;
	print(l2);
	cout<<endl<<"after splitting the two linked lists"<<endl;
	
	print(m1);
	cout<<endl;
	print(m2);
	return 0;
}

