#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

node *create()
{
	int x;
	node *temp;
	temp=new node();
	cout<<"Enter the data (Enter -1 for no node):";
	cin>>x;
	//base case condition
	if(x==-1)
	{
		//exit the function
		return 0;
	}
	temp->data=x;
	cout<<"Enter left child of "<<x<<endl;
	//recursively calling the create function to store left child
    //the function returns a pointer to left child so it will be stored in parent node left child link
	temp->left=create();
	cout<<"Enter right child of "<<x<<endl;
	//recursively calling the create function to store right child
    //the function returns a pointer to right child so it will be stored in parent node right child link
	temp->right=create();
	return temp;
}

void inorder(node *head)
{
	//left root right
	if(head==NULL)
	{
		return;
	}
	else
	{
		inorder(head->left);
		cout<<head->data<<" ";
		inorder(head->right);
	}
}

void preorder(node *head)
{
	//root left right
	if(head==NULL)
	{
		return;
	}
	else
	{
		cout<<head->data<<" ";
		preorder(head->left);
		preorder(head->right);
	}
}

void postorder(node *head)
{
	//left right root
	if(head==NULL)
	{
		return;
	}
	else
	{
		postorder(head->left);
		postorder(head->right);
		cout<<head->data<<" ";
	}
}

int main()
{
	node *head;
	head=create();
	cout<<"Inorder Traversal:";
	inorder(head);
	cout<<endl;
	cout<<"Preoreder Traversal:";
	preorder(head);
	cout<<endl;
	cout<<"Postorder Traversal:";
	postorder(head);
	cout<<endl;
}
