#include<iostream>
#include<cstdlib>
#include<ctime>
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
	lptr t=l;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=l;
	return l;
}
void delnode(lptr l,lptr t)
{
	t->next=t->next->next;
	t=t->next;
}
int play(lptr l)
{
	srand(time(0));
	int n;
	lptr t=l;
	while(t!=t->next)
	{
		n=rand()%6+1;
		for(int i=0;i<n-1;i++)
		{
			t=t->next;
		}
		delnode(l,t);
	}
	return t->data; 
}
int main()
{
	lptr loop;
	loop=create();
	int a=play(loop);
	cout<<"the winner of the game is "<<a;
}
