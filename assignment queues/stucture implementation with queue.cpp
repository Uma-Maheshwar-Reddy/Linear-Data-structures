#include<iostream>
using namespace std;
struct queue
{
	int front;
	int rear;
	int elem[100];
	int size;
};
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
void push(struct queue &q,int &a)
{
	enque(q,a);
}
int pop(struct queue &q)
{
	int res=q.elem[q.rear];
	if(q.rear==q.front)
	{
		q.rear=-1;
		q.front=-1;
	}
	else
	if(q.rear==0)
	{
		q.rear=q.size-1;
	}
	else
	{
		q.rear--;
	}
	return res;
}
int main()
{
	struct queue q;
	q.front=-1;
	q.rear=-1;
	q.size=100;
	int n,a,res;
	char in;
	cout<<"enter num of elements";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		push(q,a);
	}
		cout<<"do you wish to deque y/n";
	cin>>in;
	while(in=='y')
	{
		res=pop(q);
		cout<<endl<<" "<<res<<" ";
		cout<<"do you want to pop y/n";
		cin>>in;
	}
	return 0;
}
