#include<iostream>
using namespace std;
typedef
struct node
{
	int data;
	struct node* next;
} *lptr;
lptr findbef(lptr l,int a)
{
	lptr t=l;
	while(t->next!=NULL)
	{
		if(t->next->data>a)
		{
			break;
		}
		else
		{
			t=t->next;
		}
	}
	return t;
}
lptr insert(lptr l,int a)
{
	if(l->data>a)
	{
		lptr t=l;
		l=new node;
		l->data=a;
		l->next=t;
	}
	else
	{
		lptr temp=findbef(l,a);
		lptr n=temp->next;
		lptr m=new node;
		temp->next=m;
		m->data=a;
		m->next=n;
	}
	return l;
}
void print(lptr l)
{
	lptr t=l;
	while(t->next!=NULL)
	{
		cout<<t->data<<"  ";
		t=t->next;
	}
}
int main()
{
	lptr l;
	int d;
	cout<<"enter data -1 to end"<<endl;
	cin>>d;
	l=new node();
	l->data=d;
	l->next=NULL;
	while(d!=-1)
	{
		l=insert(l,d);
		cout<<"enter data";
		cin>>d;
	}
	print(l);
	return 0;
}
