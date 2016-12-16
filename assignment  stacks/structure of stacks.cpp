#include<iostream>
using namespace std;
struct student
{
	int rno;
	char name[100];
	char section;
};
struct stack
{
	int top;
	int size;
	struct student a[100];
};
void push(struct stack &s,struct student &st)
{
	if(s.top==s.size-1)
	{
		cout<<"the stack is full "<<endl;
	}
	else
	{
		s.top++;
		s.(a.rno)=st.rno;
		s.(a.name)=st.name;
		s.(a.section)=st.section;
	}
}
struct student pop(struct stack &s)
{
	if(s.top=-1)
	{
		cout<<"empty stack "<<endl;
	}
	else
	{
		return s.a[s.top--];
	}
}
int main()
{
	int n;
	cout<<"enter the number of students "<<endl;
	cin>>n;
	struct stack s;
	s.top=-1;
	s.size=100;
	student st[100];
	student st2;
	for(int i=0;i<n;i++)
	{
		cout<<"enter name,rno,section"<<endl;
		cin>>st.name>>st.rno>>st.section;
	    push(s,st[i]);
	}
	for(int i=0;i<n;i++)
	{
		st2=pop(s);
		cout<<st2.name<<"  "<<st2.rno<<"  "<<st2.section<<endl;
	}
}
