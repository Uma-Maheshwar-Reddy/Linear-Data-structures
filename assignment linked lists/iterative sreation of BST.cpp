#include<iostream>
using namespace std;
typedef
struct bstnode
{
	struct bstnode* lchild;
	int data;
	struct bstnode* rchild;
}*bstptr;
void insert(bstptr &h,int &k)
{
	bstptr t=h;
	while(t!=NULL)
	{
		if(t->data>k)
		{
			t=t->lchild;
		}
		else
		{
			t=t->rchild;
		}
	}
	t=new bstnode;
	t->data=k;
	t->lchild=NULL;
	t->rchild=NULL;
}
void print(bstptr &t)
{
	if(t!=NULL)
	{
		print(t->lchild);
		cout<<t->data<<" ";
		print(t->rchild);
	}
	else 
	{
		return;
	}
}
int main()
{
	bstptr root;
	root=NULL;
	int in;
	cout<<"enter data -1 if you want to end ";
	cin>>in;
	root=new bstnode;
	root->data=in;
	root->lchild=NULL;
	root->rchild=NULL;
	cout<<"enter data ";
	cin>>in;
	while(in!=-1)
	{
		insert(root,in);
		cout<<"enter data ";
		cin>>in;
	}
	print(root);
	return 0;
}
