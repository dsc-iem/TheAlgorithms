#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
	//node *parent;
};

//pointer to root node defined as null so empty tree is defined
//global variable gives access of the variable to all functions
node *root=NULL;

node *create(int data)
{
	node *temp=new node();
	temp->data=data;
	//for new node created both left and right links are set as null
	temp->left=temp->right=NULL;
	return temp;
}

node *insert(node *root,int data)
{
	//if tree is empty then we will just create new node and insert data
	if(root==NULL)
	{
		root=create(data);
	}
	//if data value is less than root value then recursively insert to left
	else if(data<=root->data)
	{
		root->left=insert(root->left,data);
	}
	//if data value is more than root value then recursively insert to right
	else
	{
		root->right=insert(root->right,data);
	}
	return root;
}

node *getsuccessor(node *root,int data)
{
	node *current=find(root,data); 
	if(current==NULL)
	{
		return NULL;
	}
	//case 1->node has only right subtree
	else if(current->right!=NULL)
	{
		node *temp=current->right;
		while(temp->left!=NULL)
		{
			temp=temp->left;
		}
		return temp;
	}
	else
	{
		node *successor=NULL;
		node *ancestor=root;
		while(ancestor!=current)
		{
			if(current->data<ancestor->data)
			{
				successor=ancestor;
				ancestor=ancestor->left;
			}
			else
			{
				ancestor=ancestor->right;
			}
		}
		return successor;
	}
}

int main()
{
	root=insert(root,15);
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,25);
	root=insert(root,8);
	root=insert(root,12);
	
	cout<<getsuccessor(root,10)->data;
}
