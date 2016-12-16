#include<iostream>
#include<cstring>
using namespace std;
struct stack
{
	int size;
	int elem[100];
	int top;
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
int main()
{
	stack s1,s2;
	s1.top=-1;
	s2.top=-1;
	s1.size=100;
	s2.size=100;
	int n,a,b,c,min;
	cout<<"enter the numbe of elements"<<endl;
	cin>>n;
	cout<<"enter "<<n<<" elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		push(s1,a);
	}
	for(int i=0;i<n;i++)
	{
		if(s1.top==0)
		{
			cout<<s1.elem[s1.top]<<endl;
			break;
		}
		else
		{ min=pop(s1);
			while(s1.top!=-1)
			{
				
				b=pop(s1);
				if(b>=min)
				{
					push(s2,b);
				}
				else
				{
					push(s2,min);
					min=b;
				}
			}
			cout<<min<<endl;
		
		while(s2.top!=-1)
		{
			c=pop(s2);
			push(s1,c);
		}
	    }
	}
return 0;
}
