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

Node* buildtre(vector<int>  &preorder, vector<int> &inorder)
{
     map<int,int> hash;
     for(int i =0; i<inorder.size(); ++i)
         hash[inorder[i]] = i;
     
     Node* root = tree(preorder, 0, preorder.size()-1, inorder, 0 , inorder.size()-1, hash);
     return root;
}

Node* tree(vector<int>& preorder, int prestart, int prend, vector<int>&inorder, int instart, int inend, map<int,int> hash)
{
      
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

  
  struct Node * root = new Node(1);
  root -> left = new Node(3);
  root -> left -> left = new Node(5);
  root -> left -> left -> left = new Node(7);
  root -> right = new Node(2);
  root -> right -> right = new Node(4);
  root -> right -> right -> right = new Node(6);

   vector<int> dist;
   dist = kdistacne(root,target,k);


 

  
}