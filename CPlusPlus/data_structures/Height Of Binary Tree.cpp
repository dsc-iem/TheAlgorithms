#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
The height of binary tree is the height of root node from the lowest leaf node.
We find the height of binary tree by the help of recursion. The function takes root node of the tree as parameter
If the root of the tree is null which means that it is an empty tree so height is -1
Else with the help of recursion we find the height of both left and right subtress
The highest value is actually considered and height is highest value of both + 1 (for root of the tree)
Time Complexity->O(n) as we are travelling all nodes only once
*/

struct node
{
	int data;
	node *left;
	node *right;
};

node *root=NULL;

node *create(int data)
{
	node *temp=new node();
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}

node *insert(node *root,int data)
{
	if(root==NULL)
	{
		root=create(data);
	}
	else if(data<=root->data)
	{
		root->left=insert(root->left,data);
	}
	else
	{
		root->right=insert(root->right,data);
	}
	return root;
}

int findheight(node *root)
{
	node *temp=root;
	if(root==NULL)
	{
		return -1;
	}
	else
	{
		int a=findheight(root->left);
		int b=findheight(root->right);
		if(a>b)
		{
			return a+1;
		}
		else
		{
			return b+1;
		}
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
	
	cout<<"Height of the tree is:"<<findheight(root);
}
