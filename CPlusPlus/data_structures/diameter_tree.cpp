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
int heightNode(node* root)
{
    if(root==NULL)
        return 0;
    int lh=heightNode(root->left);
    int rh=heightNode(root->right);
    return max(lh,rh)+1;
}
int diameter(node* root)
{
    if(root==NULL)
        return 0;
    int lh=heightNode(root->left);
    int rh=heightNode(root->right);
    int curDiameter = max(lh,rh)+1;

    int ldai=diameter(root->left);
    int rdia=diameter(root->right);

    return max(curDiameter,max(ldai,rdia));
}
int main()
{
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

    cout<<diameter(root);
    return 0;
}
