#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef
struct bnode
{
	int rno;
	int add;
	int pos;
	bnode* lchild;
	bnode* rchild;
}*bptr;
struct queue
{
	int size;
	int front;
	int rear;
	bptr elem[20];
};
void enque(struct queue &q,bptr &a)
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
bptr deque(struct queue &q)
{
	if(q.rear==-1)
	{
		cout<<"the queue is empty "<<endl;
	}
	else
	{
		bptr t=q.elem[q.front];
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
void level(bptr &h)
{
	struct queue q;
	q.front=-1;
	q.rear=-1;
	q.size=20;
	int c=0;
	enque(q,h);
	bptr t;
	while(q.front!=-1)
	{
		t=deque(q);
		t->pos=c;
		c++;
		if(t->lchild!=NULL)
		{
			enque(q,t->lchild);
		}
		if(t->rchild!=NULL)
		{
			enque(q,t->rchild);
		}
	}
}
void insert(bptr &h,int k,int off)
{
	if(h==NULL)
	{
		h=new bnode;
		h->rno=k;
		h->add=off;
		h->lchild=NULL;
		h->rchild=NULL;
	}
	else
	if(k<h->rno)
	{
		insert(h->lchild,k,off);
	}
	else
	{
		insert(h->rchild,k,off);
	}
}
int read(ifstream &fin,int &off)
{
	char buff[30];
	char x;
	int i=0;
	off=fin.tellg();
	fin>>x;
	while(x!='#')
	{
		if(x=='$')
		{
			return -1;
		}
		buff[i]=x;
		i++;
		fin>>x;
	}
	buff[i]='\0';
	i=0;
	while(buff[i]!='|')
	{
		i++;
	}
	i++;
	char num[5];
	int j=0;
	while(buff[i]!='|')
	{
		num[j++]=buff[i++];
	}
	num[j]='\0';
	return atoi(num);
}
void print(bptr &h)
{
	if(h!=NULL)
	{
		print(h->lchild);
		cout<<h->rno<<" "<<h->add<<" "<<h->pos<<endl;
		print(h->rchild);
	}
}
void out(ofstream &fout,int rno,int off,int l,int r)
{
	char buff[20];
	char num[5];
	itoa(rno,num,10);
	strcpy(buff,num);
	strcat(buff,"|");
	itoa(off,num,10);
	strcat(buff,num);
	strcat(buff,"|");
	itoa(l,num,10);
	strcat(buff,num);
	strcat(buff,"|");
	itoa(r,num,10);
	strcat(buff,num);
	strcat(buff,"|");
	int s=strlen(buff);
	for(int i=s;i<19;i++)
	{
		buff[i]='*';
	}
	buff[19]='\0';
	fout<<buff<<"#";
}
void level_print(ofstream& fout,bptr &h)
{
	struct queue q;
	q.front=-1;
	q.rear=-1;
	q.size=20;
	int c=0;
	enque(q,h);
	bptr t;
	int l,r;
	while(q.front!=-1)
	{
		t=deque(q);
		if(t->lchild==NULL)
		l=0;
		else
		l=t->lchild->pos;
		if(t->rchild==NULL)
		r=0;
		else
		r=t->rchild->pos;
		out(fout,t->rno,t->add,l,r);
		//fout<<t->rno<<"|"<<t->add<<"|"<<l<<"|"<<r<<"#";
		if(t->lchild!=NULL)
		{
			enque(q,t->lchild);
		}
		if(t->rchild!=NULL)
		{
			enque(q,t->rchild);
		}
	}
}
bool search(ifstream &fin,int s)
{
	int rrn=0;
	char buff[20],c='/';
	int i=0,j=0,k,l,r;
	char num[5],left[5],right[5];
	while(1)
	{
		fin.seekg(rrn*20,ios::beg);
		fin>>c;
		while(c!='*')
		{
			buff[i]=c;
			i++;
			fin>>c;
		}
		buff[i]='\0';
		cout<<buff<<" ";
		c='/';
		i=0;
		while(buff[i]!='|')
		{
			num[j]=buff[i];
			j++;i++;
		}
		num[j]='\0';
		j=0;
		i++;
		k=atoi(num);
		cout<<k<<" ";
		if(k==s){cout<<endl;return 1;}
		while(buff[i]!='|') i++;
		i++;
		while(buff[i]!='|')
		{
			left[j++]=buff[i++];
		}
		left[j]='\0';
		j=0;
		i++;
		while(buff[i]!='|')
		{
			right[j++]=buff[i++];
		}
		right[j]='\0';
		j=0;
		i=0;
		l=atoi(left);
		r=atoi(right);
		cout<<l<<" "<<r<<"\n";
		if(k>s) 
		{
			if(l==0) return 0;
			else
			rrn=l;
		}
		else
		{
			if(r==0) return 0;
			else
			rrn=r;
		}
	}
}
int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("records.txt");
	int key,off;
	bptr h=NULL;
	while(key!=-1)
	{
		key=read(fin,off);
		if(key!=-1)
		insert(h,key,off);
	}
	level(h);
	print(h);
	fin.close();
	fout.open("tree.txt");
	level_print(fout,h);
	fout.close();
	fin.open("tree.txt");
	int s;
	cout<<"enter search ";
	cin>>s;
	bool c;
	while(s!=-1)
	{
		c=search(fin,s);
		if(c)
		{
			cout<<"found "<<endl;
		}
		else
		{
			cout<<"not found "<<endl;
		}
		cout<<"enter search ";
		cin>>s;
	}
	return 0;
}
