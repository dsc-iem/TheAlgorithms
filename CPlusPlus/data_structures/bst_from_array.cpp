#include <bits/stdc++.h>
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
    temp->right=temp->left=NULL;
    return temp;
}
node* insertBST(node* root,int value)
{
    if(root==NULL)
        return newNode(value);
    if(value<root->data)
        root->left=insertBST(root->left,value);
    else
        root->right=insertBST(root->right,value);
    return root;
}
void inorder(node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    int arr[]={6,2,7,4,9,2,5,1,11};
    node* root=NULL;
    int l=sizeof(arr)/sizeof(arr[0]);
    root=insertBST(root,arr[0]);
    for(int i=1;i<l;i++)
        insertBST(root,arr[i]);
    inorder(root);
    return 0;
}
