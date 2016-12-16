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
bool isnum(char a)
{
	if(a>='0'&&a<='9')
	return 1;
	else 
	return 0;
}
bool canbepushed(struct stack &s,char a)
{
	if(s.top==-1)
	{
		return 1;
	}
	else
	{
	   if((s.elem[s.top]=='+'||s.elem[s.top]=='-')&& (a=='*'||'/'))
	   return 1;
	   else 
	   return 0;
	}

}

int main()
{
	struct stack s;
	s.top=-1;
	s.size=100;
	char infix[100];
	char postfix[100];
	int j=0;
	char c;
	cout<<"enter the infix expression needed "<<endl;
	cin.getline(infix,100);
	int len=strlen(infix);
	for(int i=0;i<len;i++)
	{
		if(isnum(infix[i]))
		{
			postfix[i]=infix[j];
			j++;
		}
		else if(!isnum(infix[i]))
		{
			if(canbepushed(s,infix[i]))
			{
			push(s,infix[i]);
		    }
			else
			{
				while(s.elem[s.top]!=infix[i])
				{
				c=pop(s);
				postfix[j]=c;
				j++;
				if(canbepushed(s,infix[i]))
				{
					push(s,infix[i]);
				}}
			}
		}
	}
	while(s.top!=-1)
	{
		postfix[j]=pop(s);
		j++;
	}
	cout<<"the equivalent postfix expression for "<<infix<<" is ";
	for(int i=0;i<j;i++)
	{
		cout<<postfix[i];
	}
	return 0;
}
