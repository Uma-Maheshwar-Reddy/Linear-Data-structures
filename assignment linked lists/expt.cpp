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
int delbeg(dptr &d)
{
	dptr temp=d;
	d=d->next;
	d->prev=NULL;
	temp->next=NULL;
	int a=temp->data;
	delete temp;
	return a;
}
int delend(dptr &d)
{
	dptr t=d;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	dptr temp=t;
	t=t->prev;
	t->next=NULL;
	temp->prev=NULL;
	temp->next=NULL;
	int res=temp->data;
	return res;
	
}
int delel(dptr &d,int &a)
{
	dptr t=d;
	if(d->data==a)
	{
		int ans=delbeg(d);
		return ans;
	}
	else
	{
	while(t->data!=a&&t->next!=NULL)
	{
		t=t->next;
	}
	if(t->data==a&&t->next==NULL)
	{
		int ans=delend(d);
		return ans;
	}
	else
	{
	dptr temp=t;
	t=t->prev;
	t->next=temp->next;
	temp->next->prev=t;
	temp->next=NULL;
	temp->prev=NULL;
	int res=temp->data;
	return res;
}
}
}
int main()
{
	dptr d;
	d=NULL;
	int choice;
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
	char ch;
	cout<<"do you wish to delete"<<endl;
	cin>>ch;
	int in;
	if(ch=='y')
	{
		cout<<"1:del_begin   2:del_end   3:delete_element  0:exit"<<endl;
		cin>>in;
		while(1)
		{
		if(in==1)
		{
			int ans=delbeg(d);
			cout<<"the deleted element is "<<ans<<endl;
			print(d);
			cout<<endl;
		}
		else
		if(in==2)
		{
			int ans=delend(d);
			cout<<"the deleted element is "<<ans<<endl;
			print(d);
			cout<<endl;
		}
		if(in==3)
		{
			cout<<" which element"<<endl;
			cin>>choice;
			int ans=delel(d,choice);
			cout<<"the deleted element is "<<ans<<endl;
			print(d);
			cout<<endl;
		}
		if(in==0)
		{
			break;
		}
		cout<<"1:del_begin   2:del_end   3:delete_element  0:exit"<<endl;
		cin>>in;
	}
	}
	return 0;
}
