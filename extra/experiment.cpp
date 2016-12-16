
#include<iostream>
using namespace std;
typedef
struct node
{
	int data;
	struct node* next;
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
lptr delbeg(lptr l)
{
	cout<<"the dequed element is"<<l->data<<endl;
	if(l->next==NULL)
	{
		return NULL;
	}
	else
	{
		l=l->next;
		return l;
	}
}
void enque(lptr l,int a)
{
	addend(l,a);
}
lptr deque(lptr l)
{
	if(l==NULL)
	{
		cout<<"the queue is empty";
	}
	else
	{
		l=delbeg(l);
	}
	return l;
}
void print (lptr l)
{
	lptr t=l;
	while(t!=NULL)
	{
		cout<<t->data<<"  ";
		t=t->next;
	}
}
int main()
{
	lptr l,c;
	l=NULL;
	int input,d;
	while(1)
	{
		cout<<"1:enque  2:deque   3:exit";
		cin>>input;
		if(input==1)
		{
			cout<<"enter data";
			cin>>d;
			if(l==NULL)
			{
				l=new node;
				l->data=d;
				l->next=NULL;
			}
			else
			{
			  enque(l,d);
		    }
		}
		else
		if(input==2)
		{
			l=deque(l);
		}
		else
		if(input==3)
		{
			break;
		}
	}
	return 0;
}
