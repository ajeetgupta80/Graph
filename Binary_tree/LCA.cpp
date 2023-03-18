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
Node* LCA(Node* root, Node* p , Node* q)
{
   if(root == NULL || root == p || root == q)
     return root;

    Node* left = LCA(root ->left, p, q);
    Node* right = LCA(root -> right, p, q);

    if(left == NULL )
      return right;
    else if(right == NULL )
      return left;
    else
     return root;
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

  Node* node = LCA(root);

  

  
}