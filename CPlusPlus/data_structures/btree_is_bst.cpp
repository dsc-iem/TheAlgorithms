#include <bits/stdc++.h>
using namespace std;

struct node{
    public:
    int data;
    node* left;
    node* right;
};
node* newNode(int value){
    node* temp=new node();
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
}
bool isBST(node* root,node* min,node* max)
{
    if(root==NULL)
        return true;
    if(min!=NULL && root->data<=min->data)
        return false;
    if(max!=NULL && root->data>=max->data)
        return false;
    bool leftValid= isBST(root->left,min,root);//as max of left sub tree is root if it is a bst
    bool rightValid= isBST(root->right,root,max);//as min is root for a bst compared to right sub tree
    return leftValid and rightValid;
}
int main()
{
	node *root = newNode(5);
	root->left = newNode(2);
	root->right = newNode(7);
	root->left->left = newNode(1);
	root->left->right = newNode(11);
    if(isBST(root,NULL,NULL))
        cout<<"IS a Binary Search TRee";
    else
        cout<<"NOt a BST";
    return 0;
}
