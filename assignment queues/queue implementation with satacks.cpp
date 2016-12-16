#include<iostream>
#include<cstring>
using namespace std;
struct stack
{
	int size;
	char elem[100];
	int top;
};
void push(struct stack &s,char &a)
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
char pop(struct stack &s)
{
	if(s.top==-1)
	cout<<"the stack is empty";
	else
	return s.elem[s.top--];
}
void enque(struct stack &s,char &a)
{
	push(s,a);
}
char deque(struct stack &s)
{
	struct stack s1;
	s1.top=-1;
	s1.size=100;
	char a,res;
	while(s.top!=-1)
	{
		a=pop(s);
		push(s1,a);
	}
	res=pop(s1);
	while(s1.top!=-1)
	{
		a=pop(s1);
		push(s,a);
	}
	return res;
}
int main()
{
	int n;
	char ch,in,res;
	struct stack s;
	s.top=-1;
	s.size=100;
	cout<<"enter the number of elements "<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ch;
		enque(s,ch);
	}
	cout<<"do you wish to deque y/n";
	cin>>in;
	while(in=='y')
	{
		res=deque(s);
		cout<<endl<<" "<<res<<" ";
		cout<<"do you want to deque y/n";
		cin>>in;
	}
	return 0;
}
