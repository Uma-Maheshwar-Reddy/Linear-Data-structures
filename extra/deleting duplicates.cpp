#include<iostream>
using namespace std;
typedef
struct node
{
	int data;
	struct node *next;
} *lptr;
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
	lptr l;
	int d;
	cout<<"enter the elements -1 if you want to end ";
	cin>>d;
	if(d!=-1)
	{
		l=new node;
		l->data=d;
		l->next=NULL;
		cout<<"enter element";
		cin>>d;
		while(d!=-1)
		{
			addend(l,d);
			cout<<"enter element";
			cin>>d;
		}
	}
	return l;
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
void delnode(lptr l,lptr t)
{
	t->next=t->next->next;
}
lptr rem(lptr l)
{
	lptr l1=l;
	lptr h,t;
	h=l1;
	while(h->next!=NULL)
	{
		t=h;
		while(t->next!=NULL)
		{
			if(t->next->data==h->data)
			{
				delnode(l,t);
			}
			t=t->next;
		}
		h=h->next;
	}
	return l1;
}
int main()
{
	lptr l,l1;
	l=create();
	print(l);
	cout<<endl;
	l1=rem(l);
	print(l1);
	return 0; 
}

