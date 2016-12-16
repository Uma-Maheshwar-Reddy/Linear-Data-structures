#include<iostream>
using namespace std;
typedef
struct node
{
	int coeff;
	int exp;
	struct node* next;
} *lptr;
void addend(lptr l,int co,int ex)
{
	lptr t=l;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=new node;
	t=t->next;
	t->exp=ex;
	t->coeff=co;
	t->next=NULL;
}
lptr create()
{
	lptr l;
	int co,ex;
	l=new node;
	cout<<"enter the coeff and exp -1 to end "<<endl;
	cin>>co>>ex;
	l->coeff=co;
	l->exp=ex;
	l->next=NULL;
	cout<<"enter coef and exp";
	cin>>co>>ex;
	while(ex!=-1)
	{
		addend(l,co,ex);
		cout<<"enter coeff and exp ";
		cin>>co>>ex;
	}
	return l;
}
void print (lptr l)
{
	lptr t=l;
	while(t!=NULL)
	{
		cout<<t->coeff<<"x"<<t->exp<<"+";
		t=t->next;
	}
}
lptr add(lptr l1,lptr l2)
{
	lptr l,t1,t2;
	l=new node;
	t1=l1;
	t2=l2;
	if(t1->exp==t2->exp)
	{
		l->coeff=t1->coeff+t2->coeff;
		l->exp=t1->exp;
		l->next=NULL;
		if(t1!=NULL) t1=t1->next;
		if(t2!=NULL) t2=t2->next;
	}
	else
	if(t1->exp>t2->exp)
	{
		l->coeff=t1->coeff;
		l->exp=t1->exp;
		l->next=NULL;
		if(t1!=NULL) t1=t1->next;
	}
	else
	if(t1->exp<t2->exp)
	{
		l->coeff=t2->coeff;
		l->exp=t2->exp;
		l->next=NULL;
		if(t1!=NULL) t1=t1->next;
	}
	while(t1!=NULL||t2!=NULL)
	{
		if(t1==NULL)
		{
			while(t2!=NULL)
			{
				addend(l,t2->coeff,t2->exp);
				t2=t2->next;
			}
		}
		else
		if(t2==NULL)
		{
			while(t1!=NULL)
			{
				addend(l,t1->coeff,t1->exp);
				t1=t1->next;
			}
		}
		else
		{
			if(t1->exp==t2->exp)
			{
				addend(l,t1->coeff+t2->coeff,t1->exp);
				t1=t1->next;
				t2=t2->next;
			}
			else
			if(t1->exp>t2->exp)
			{
				addend(l,t1->coeff,t1->exp);
				t1=t1->next;
			}
			else
			if(t1->exp<t2->exp)
			{
				addend(l,t2->coeff,t2->exp);
				t2=t2->next;
			}
		}
	}
	return l;

}
int main()
{
	lptr l1,l2,l3;
	l1=create();
	l2=create();
	cout<<endl;
	print(l1);
	cout<<endl;
	print(l2);
	cout<<endl;
	l3=add(l1,l2);
	print(l3);
	return 0;
}
