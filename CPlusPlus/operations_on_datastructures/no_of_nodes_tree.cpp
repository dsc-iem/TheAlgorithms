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

int countNOdes(node* root)
{
    if(root == NULL)
        return 0;
    return countNOdes(root->left)+countNOdes(root->right)+1;
}
int sumTRee(node* tree)
{
    if(tree == NULL)
        return 0;
    return sumTRee(tree->left)+sumTRee(tree->right)+tree->data;
}
int main()
{
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
    cout<<"COUNT "<<countNOdes(root)<<endl;
    cout<<"sum "<<sumTRee(root);
    return 0;
}
