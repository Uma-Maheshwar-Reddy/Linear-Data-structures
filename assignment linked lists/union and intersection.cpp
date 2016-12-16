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
void print(lptr l)
{
	lptr t=l;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->next;
	}
}
lptr create()
{
	lptr l;
	int d;
	cout<<"enter d -1 to end";
	cin>>d;
	if(d!=-1)
	{
		l=new node;
		l->data=d;
		l->next=NULL;	
	}
	cout<<"enter data";
	cin>>d;
	while(d!=-1)
	{
		addend(l,d);
		cout<<"enter data ";
		cin>>d;
	}
	return l;
}
bool search(lptr l,int k)
{
	lptr t;
	t=l;
	int count=0;
	while(t!=NULL)
	{
		if(t->data==k)
		count++;
		t=t->next;
	}
	if(count==0) return 0;
	else return 1;
}
lptr unin(lptr l1,lptr l2)
{
	lptr l,t1,t2;
	t1=l1;
	t2=l2;
	l=new node;
	l->data=t1->data;
	l->next=NULL;
	t1=t1->next;
	while(t1!=NULL)
	{
		addend(l,t1->data);
		t1=t1->next;
	}
	while(t2!=NULL)
	{
		if(!(search(l1,t2->data)))
		{
			addend(l,t2->data);
		}
		t2=t2->next;
	}
	return l;
}
void inter(lptr l1,lptr l2)
{
	lptr t1,t2;
	t1=l1;
	t2=l2;int p;
	while(t1!=NULL)
	{
		p=t1->data;
		if(search(l2,p))
		{
			cout<<p<<"  ";
		}
		t1=t1->next;
	}
}
int main()
{
	lptr l1,l2;
	l1=create();
	l2=create();
	print(l1);
	cout<<endl;
	print(l2);
	lptr lu,li;
	cout<<endl<<"union is :  ";
	lu=unin(l1,l2);
	print(lu);
	cout<<endl<<"the intersecttion is  : ";
	inter(l1,l2);
	return 0;
}
