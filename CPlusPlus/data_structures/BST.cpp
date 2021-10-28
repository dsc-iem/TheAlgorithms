#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
node* inorder_suc(node* root){
    node* temp=root;
    if(temp&&temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
node* get_new_node(int data){
    node* newnode =new node();
    newnode -> data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
node* insert_node(node* root,int data){
    if(root==NULL){
        root=get_new_node(data); 
    }
    else if(data <= root->data){
        root->left = insert_node(root->left,data);
    }
    else{
        root->right = insert_node(root->right,data);
    }
    return root;

}
bool search(node* root,int data){
    if(root=NULL){
        return false;
    }
    else if(root->data==data){
        return true ;
    }
    else if(data <= root->data){
        return search(root->left,data);
    }
    else {
        return search(root->right,data);
    }
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data <<" ";
    inorder(root->right);


}
node* delete_node(node* root,int data){
    if(root==NULL){
        return root;
    }
    else if(data<root->data){
        root->left = delete_node(root->left,data);
    }
    else if(data>root->data){
        root->right=delete_node(root->right,data);
    }
    else{
        //Case 1 : No Child
        if(root->left==NULL && root->right==NULL){
          delete root ;
          root=NULL;
          
          
        }
        //Case 2 :1 child
        else if(root->left==NULL){
            node* temp =root->right;
            delete root;
            return temp;
            
        }
        else if(root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
          
        }
        //Case 3: 2 children
        else{
            node* temp = inorder_suc(root->right) ;
            root->data =temp->data;
            root->right=delete_node(root->right,temp->data);

       }

      
    }

  return root;
}
int main(){
node* root=NULL;
root=insert_node(root,10);
root=insert_node(root,20);
root=insert_node(root,30);
root=insert_node(root,1);
root=insert_node(root,9);
root=insert_node(root,5);
root=insert_node(root,40);
 inorder(root);
 cout<<endl;
 delete_node(root,20);
 inorder(root);
return 0;
}