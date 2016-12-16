#include<iostream>
#include<string.h>
using namespace std;
struct s{
	int a;
	char b;
};
struct queue{
	int front;
	int rear;
	int size;
	struct s ele[100];
};
void enque(queue &q,struct s n)
{
	if((q.rear+1)%q.size==q.front)
	{
		cout<<"queue is full";
	}
	else
	{
		q.rear=(q.rear+1)%q.size;
		if(q.front==-1)
		{
			q.front=0;
		}
		q.ele[q.rear]=n;
	}
}
struct s deque(struct queue &q)
{
	if(q.front==-1)
	{
		cout<<"queue is full";
	}
	int t;
	t=q.front;q.front=(q.front+1)%q.size;
	if(q.rear==t)
	{
		q.rear=-1;
		q.front=-1;
	}
	return q.ele[t];
}
int func(char ch)
{
	switch(ch)
	{
		case '*':return 1;
		case '/':return 1;
		case '-':return 0;
		case '+':return 0;
	}
}
int func2(int n1,int n2,char ch)
{
	switch(ch)
	{
		case '*':return n1*n2;
		case '/':return n1/n2;
		case '-':return n1-n2;
		case '+':return n1+n2;
	}
}
int main()
{
	struct queue q;
	q.size=100;q.rear=-1;q.front=-1;
	char st[100];
	cout<<"enter the infix expression:";
	cin>>st;
	int l=strlen(st);
	struct s s1[100],ts,ts1;
	int i;char ch1,ch2;
	for(i=0;i<l;i++)
	{
		s1[i].b=st[i];
		enque(q,s1[i]);
	}
	ch1='@';ch2='@';
	for(i=0;i<l;i++)
	{
	    
		ts=deque(q);
		if(ts.b>='0'&&ts.b<='9')
		{
			enque(q,ts);
		}
		else
		{
			if(ch1!='@'&&ch2!='@')
			{
				ts1.b=ch2;enque(q,ts1);
				ts1.b=ch1;enque(q,ts1);
				ch1=ts.b;
				ch2='@';
			}
			else
			{
				if(ch1=='@')
				{
					ch1=ts.b;
				}
				else
				{
					if(func(ch1)<func(ts.b))
					{
						ch2=ts.b;
					}
					else
					{
						ts1.b=ch1;
						enque(q,ts1);
						ch1=ts.b;
					}
				}
			}
		
		}
	}
	if(ch2!='@')
	{
		ts.b=ch2;
		enque(q,ts);
	}
	if(ch1!='@')
	{
		ts.b=ch1;
		enque(q,ts);
	}
	cout<<"postfix expression is:   ";
	
	for(i=0;i<l;i++)
	{
		ts=deque(q);
		enque(q,ts);
		cout<<ts.b;
	}
	int ar[10];int j=0;struct s ts2;
	for(i=0;i<l;i++)
	{
		ts2=deque(q);
		if(ts2.b>='0'&&ts.b<='9')
		{
			ar[j]=ts2.b-'0';j++;
		}
		else
		{
			ar[j-2]=func2(ar[j-2],ar[j-1],ts2.b);j--;
		}
	}
	cout<<endl<<"the value for the expression is "<<ar[0];
}
