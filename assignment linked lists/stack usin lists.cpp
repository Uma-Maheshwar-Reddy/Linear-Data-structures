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
	t=t->next;
	t->next=new node;
	t=t->next;
	t->data=a;
	t->next=NULL;
}
int delend(lptr l)
{
	
	if(l->next==NULL)
	{
		int p=l->data;
		l=NULL;
		return p;
	}
	else
	{
		lptr t=l;
	while(t->next->next!=NULL)
	{
		t=t->next;
	}
	int res=t->next->data;
	t->next=NULL;
	return res;
    }
}
void push(lptr l,int a)
{
	addend(l,a);
}
int pop(lptr l)
{
	lptr t;
	int ans;
	t=l;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	if(t==l)
	{
		cout<<"stack is empty"<<endl;
	}
	else
	{
		ans=delend(l);
	}
	return ans;
}
int main()
{
	int choice;
	int d,p;
	lptr l;
	l=new node;
	l->data=0;
	l->next=NULL;
	while(1)
	{
	cout<<"do byou wish to push or pop 1: push 2:pop 3:exit ";
	cin>>choice;
	if(choice==1)
	{
		cout<<"enter data";
		cin>>d;
		push(l,d);
	}
	if(choice==2)
	{
		p=pop(l);
		cout<<p<<endl;
	}
	if(choice==3)
	{
		break;
	}
}
return 0;
}
