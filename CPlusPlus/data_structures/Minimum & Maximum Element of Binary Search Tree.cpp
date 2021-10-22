#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*A binary tree in which all elements of left subtree of any node is lesser than the value in that node 
and all elements of right subtree of any node is greater than the value in that node is called Binary Search Tree
Thus the minimum element of the whole BST is the lowest left most element of the left subtree of root node
while the maximum element of the whole BST is the lowest right most element of the right subtree of the root node
So we will iterate to the end of the subtrees to find our required values
Space & Time Complexity->
O(n) for finding minimum element if the tree is left skewed and O(1) for finding maximum element in that case as maximum element will be the root element
O(n) for finding maximum element if the tree is right skewed and O(1) for finding minimum element in that case as minimum element will be the root element*/

struct node
{
	int data;
	node *left;
	node *right;
};

node *root=NULL;

node *create(int data)
{
	node *temp=new node ();
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
}

int findmin(node *root)
{
	if(root==NULL)
	{
		return -1;
	}
	node *temp=root;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp->data;
}

int findmax(node *root)
{
	if(root==NULL)
	{
		return -1;
	}
	node *temp=root;
	while(temp->right!=NULL)
	{
		temp=temp->right;
	}
	return temp->data;
}

int main()
{
	root=insert(root,15);
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,25);
	root=insert(root,8);
	root=insert(root,12);
	
	cout<<"Minimum Element is:"<<findmin(root)<<endl;
	cout<<"Maximum Element is:"<<findmax(root)<<endl;
}
