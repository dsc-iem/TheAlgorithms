#include<bits/stdc++.h>
using namespace std;

struct node{
    public:
    int data;
    node* left;
    node* right;
};
node* newNode(int value)
{
    node* temp=new node();
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
}
int  sumlevelOrder(node* root,int k)
{
    if(root==NULL)
        return -1;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int sum=0;
    int level=0;
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp!=NULL)
        {   
            if(level==k)
                sum+=temp->data;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        else if(!q.empty())
        {
            q.push(NULL);//after every level one NUll
            level++;
        }
    }
    return sum;
}
int main()
{
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
    root->right->left = newNode(4);
	root->right->right = newNode(5);
    int sum =sumlevelOrder(root,2);
    cout<<sum;
    return 0;
}
