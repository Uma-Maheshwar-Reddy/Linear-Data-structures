#include<iostream>
using namespace std;
struct queue
{
	int size;
	int front;
	int rear;
	int elem[100];
};
struct stack
{
	int size;
	int top;
	int elem[100];
};
void push(struct stack &s,int &a)
{
	if(s.top==s.size-1)
	{
		cout<<"the stack is full";
	}
	else
	{
		s.top++;
		s.elem[s.top]=a;
	}
}
int pop(struct stack &s)
{
	if(s.top==-1)
	cout<<"the stack is empty";
	else
	return s.elem[s.top--];
}
void enque(struct queue &q,int &a)
{
	if((q.rear+1)%q.size==q.front)
	{
		cout<<"the queue is full"<<endl;
	}
	else
	{
		if(q.front==-1)
		q.front=0;
		q.rear=(q.rear+1)%q.size;
		q.elem[q.rear]=a;
	}
}
int deque(struct queue &q)
{
	if(q.rear==-1)
	{
		cout<<"the queue is empty "<<endl;
	}
	else
	{
		int t=q.elem[q.front];
		if(q.front==q.rear)
		{
			q.rear=-1;
			q.front=-1;
		}
		else
		{
			q.front=(q.front+1)%q.size;
		}
		return t;
	}
}
int main()
{
	struct queue q;
	struct stack s;
	s.top=-1;
	s.size=100;
	q.front=-1;
	q.rear=-1;
	q.size=100;
	int n,d,a;
	cout<<"enter the number of elements in the queue"<<endl;
	cin>>n;
	cout<<"enter the n elements in the queue in order"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>d;
		enque(q,d);
	}
	for(int i=0;i<n;i++)
	{
		a=deque(q);
		push(s,a);
	}
	for(int i=0;i<n;i++)
	{
		a=pop(s);
		enque(q,a);
	}
	cout<<"the elements of queue in reverse are "<<endl;
	for(int i=0;i<n;i++)
	{
		a=deque(q);
		cout<<" "<<a<<" ";
	}
}
