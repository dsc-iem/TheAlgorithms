#include<iostream>
#include<queue>
using namespace std;

struct node
{
    node *left{nullptr};
    node *right{nullptr};
    int data{0};
};
node *root{nullptr};

node* create()
{
    int num;
    node *temp = new node;
    cout<<"Enter data (-1 for no node): ";
    cin>>num;
    cout<<endl;
    if(num==-1)
        return nullptr;
    temp->data=num;
    cout<<"(left child of "<<num<<")"<<endl;
    temp->left=create();
    cout<<"(right child of "<<num<<")"<<endl;
    temp->right=create();
    return temp;
}

bool isBST(node *temp, int min=INT_MIN, int max=INT_MAX)
{
    if(temp==nullptr)
        return true;
    else if(temp->data>min && temp->data<max && isBST(temp->left,min,temp->data) && isBST(temp->right,temp->data,max))
        return true;
    else
        return false;
}

int main()
{
    root=create(); // creates a binary tree and root is a pointer to root node
    if(isBST(root)==true)
                cout<<"BST"<<endl;
            else
                cout<<"Not a BST"<<endl;
    return 0;
}


 

