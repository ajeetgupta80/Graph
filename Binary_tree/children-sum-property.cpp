#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
    
};

void reorder(Node* root)
{
    if(root == NULL )
      return;
    
    int child = 0;
    if(root -> left)
     child+= root ->left -> data;
    if(root -> right)
      child+=root->right->data;
    
    if(child >= root -> data)
      root->data = child;
    else{
        if(root -> left)
         root-> left -> data = child;
        if(root -> right)
         root-> right -> data = child;
    }

    reorder(root -> left);
    reorder(root -> right);
   
    int tot =0;
    if(root -> left)
     tot+=root->left-> data;
    if(root -> right)
     tot+=root->right->data;

   
}







int main() 
{
 

  struct Node * root = new Node(1);
  root -> left = new Node(3);
  root -> left -> left = new Node(5);
  root -> left -> left -> left = new Node(7);
  root -> right = new Node(2);
  root -> right -> right = new Node(4);
  root -> right -> right -> right = new Node(6);

  

  reorder(root);

 

  
}