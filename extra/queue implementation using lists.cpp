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
int delbeg(lptr l)
{
	int ans;
	if(l==NULL)
	{
		cout<<"the queue is empty ";
	}
	else
	{
		ans=l->data;
	    if(l->next!=NULL) l=l->next;
	    else l=NULL;
	    return ans;
	}
}
void enque(lptr l,int a)
{
	addend(l,a);
}
int deque(lptr l)
{
	int ans;
	ans=l->data;
	l=l->next;
	return ans;
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
	lptr l;
	l=NULL;
	int input,c,d;
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
			c=deque(l);
			cout<<"the dequeued element is"<<c<<endl;
		
		}
		else
		if(input==3)
		{
			break;
		}
	}
	return 0;
}
