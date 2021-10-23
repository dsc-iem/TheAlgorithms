#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* 
In Level Order Traversal of Binary Tree we try to cover data in each node of tree at 1 level.
After we finish 1 level we can go to the next level and we will continue this till we reach to the leaf node level
The function used to print the level order traversal elements is created. 
It contains a queue that is used to store the pointer to node to reach back to te nodes while traversing so that we can reach back to any node if needed
while we have root node address we will push that to a queue and loop until the queue is empty and simultaneously pop elements from front 
This way we can cover all the elements at one level and then go to next level
Time & Space Complexity->O(n) as each node is traversed once 
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
	return temp;
}

node *insert(node *root, int data)
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

void levelorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		node *temp=q.front();
		cout<<temp->data<<" ";
		if(temp->left!=NULL)
		{
			q.push(temp->left);
		}
		if(temp->right!=NULL)
		{
			q.push(temp->right);
		}
		q.pop();
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
	cout<<"Level Order Traversal:";
	levelorder(root);
}
