#include <bits/stdc++.h>
using namespace std;

struct node{
    public:
    int data;
    node* left;
    node* right;
};
//helper to make a  node
node* newNode(int value)
{
    node* temp=new node();
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
}
//left root right
void inorder(node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//root left right
void preorder(node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
//left right root
void postorder(node* root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void levelOrder(node* root)
{
    if(root==NULL)
        return;
    queue<node* >q;
    q.push(root);
    q.push(NULL);
    while(q.empty()==false)
    {
        node* temp=q.front();
        q.pop();
        if(temp!=NULL)
        {
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}
int main()
{
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Level Order traversal of binary tree is \n";
	levelOrder(root);
    cout<<endl;
    cout << "IN Order traversal of binary tree is \n";
    inorder(root);
    cout<<endl;
    cout << "Pre Order traversal of binary tree is \n";
    preorder(root);
    cout<<endl;
    cout << "Post Order traversal of binary tree is \n";
    postorder(root);
    cout<<endl;
	return 0;
}
