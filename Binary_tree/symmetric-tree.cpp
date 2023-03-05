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

bool help(Node*left, Node* right)
{   
    if(left == NULL || right == NULL)
        return left == right;  
     
    if(left->data!=right->data)
     return false;

    return help(left->left,right->right) && help(left->right, right->left);

}

bool issymetric(Node* root)
{
     return root == NULL || help(root->left, root->right);
}


int main() 
{
 
   

  struct Node* root = new Node(1);
  root -> left = new Node(2);
  root -> left -> left = new Node(4);
  root -> left -> right = new Node(10);
  root -> left -> left -> right = new Node(5);
  root -> left -> left -> right -> right = new Node(6);
  root -> right = new Node(3);
  root -> right -> left = new Node(9);
  root -> right -> right = new Node(10);

  if(issymetric(root))
  {
    cout<<"true"<<endl;
  }else{
    cout<<"false"<<endl;
  }


 

  
}