#include<iostream>
#include<cstring>
using namespace std;
struct queue1
{
	int front;
	int rear;
	int elem[100];
	int size;
};
struct queue2
{
	int front;
	int rear;
	char elem[100];
	int size;
};
void enque(struct queue1 &q,int &a)
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
int deque(struct queue1 &q)
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

void enque(struct queue2 &q,char &a)
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
char deque(struct queue2 &q)
{
	if(q.rear==-1)
	{
		cout<<"the queue is empty "<<endl;
	}
	else
	{
		char t=q.elem[q.front];
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
bool is_num(char a)
{
	if(a>='0'&&a<='9')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int num(char a)
{
	if(a=='0') return 0;
	if(a=='1') return 1;
	if(a=='2') return 2;
	if(a=='3') return 3;
	if(a=='4') return 4;
	if(a=='5') return 5;
	if(a=='6') return 6;
	if(a=='7') return 7;
	if(a=='8') return 8;
	if(a=='9') return 9;
}
bool pref(char op1,char op2)
{
	if((op1=='+'||op1=='-')&&(op2=='*'||op2=='/'))
	return 0;
	else
	return 1;
}
int operation(int &a,int &b,char &c)
{
	switch(c)
	{
		case '+':
			return a+b;
			break;
		case '-':
			return a-b;
			break;
		case '*':
			return a*b;
			break;
		case '/':
			return a/b;
			break;
	}
}
int main()
{
	struct queue1 q1;
	struct queue2 q2;
	q1.front=-1;
	q1.rear=-1;
	q2.front=-1;
	q2.rear=-1;
	q1.size=100;
	q2.size=100;
	int ans,res,nu;
	char infix[100];
	cout<<"enter a valid infix expression "<<endl;
	cin.getline(infix,100);
	int len=strlen(infix);
	for(int i=0;i<len;i++)
	{
		if(is_num(infix[i]))
		{
			nu=num(infix[i]);
			enque(q1,nu);
		}
		else
		{
			enque(q2,infix[i]);
		}
	}
	int v1,v2;
	char op1,op2;
	v1=deque(q1);
	v2=deque(q1);
	op1=deque(q2);
	while(q2.front!=0)
	{
		if(q2.front==-1)
		{
			ans=operation(v1,v2,op1);
			break;
		}
		else{
		
		op2=deque(q2);
		//cout<<v1<<" "<<v2<<" "<<op1<<" "<<op2<<endl;
		if(pref(op1,op2))
		{
			enque(q2,op2);
			res=operation(v1,v2,op1);
			cout<<res<<"  ";
			enque(q1,res);
			enque(q2,op2);
			v1=deque(q1);
	        v2=deque(q1);
	        op1=deque(q2);
		}
		else
		{
			enque(q2,op1);
			enque(q1,v1);
			v1=deque(q1);
			op1=op2;
		}}
	}
	cout<<"the result of the expression is "<<ans;
	return 0;
}
