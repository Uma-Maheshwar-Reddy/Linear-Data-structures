#include<iostream>
using namespace std;
typedef 
struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
}*bptr;
void insert(bptr &h,int a)
{
	if(h==NULL)
	{
		h=new node;
		h->data=a;
		h->lchild=NULL;
		h->rchild=NULL;
	}
	else
	{
		if(a>h->data)
		{
			insert(h->rchild,a);
		}
		else
		if(a<h->data)
		{
			insert(h->lchild,a);
		}
	}
}
void print(bptr h)
{
	if(h==NULL)
	{
		return;
	}
	else
	{
		cout<<h->data<<" ";
		print(h->lchild);
		if(h->rchild!=NULL)
		print(h->rchild);
	}
}
void inorder(bptr root)
{
	if(root==NULL)
	{
		return;
	}
	if(root!=NULL)
	{
		inorder(root->lchild);
		cout<<root->data<<" ";
		inorder(root->rchild);
	}
}
int main()
{
	bptr root;
	root=NULL;
	int n;
	cout<<"enter data you wish to add in the binary tree -1 to stop  ";
	cin>>n;
	while(n!=-1)
	{
		insert(root,n);
		cout<<"enter data ";
		cin>>n;
	}
	print(root);
	cout<<endl;
	inorder(root);
	return 0;
}
