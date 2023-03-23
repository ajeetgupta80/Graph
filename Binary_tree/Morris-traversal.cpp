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

  vector<int> preorderTraversal(Node* root) {
        // morris traversal
        vector<int> ans;
        Node * curr = root;
        while(curr != NULL ){
            if(curr -> left == NULL )
            {
                ans.push_back(curr -> data);
                curr = curr -> right;

            }else{
                 Node* prev = curr->left;
                 while( prev -> right && prev->right!=curr)
                 {
                     prev = prev->right;
                 }
                 if(prev -> right == NULL )
                 {
                     prev -> right = curr;
                     ans.push_back(curr->data);
                     curr = curr -> left;
                 }else{
                     prev -> right = NULL;
                     curr = curr-> right;
                 }
            }
        }
        return ans;

        
    }

     vector<int> inorderTraversal(Node* root) {
        // morris traversal
        vector<int> ans;
        Node * curr = root;
        while(curr != NULL ){
            if(curr -> left == NULL )
            {
                ans.push_back(curr -> data);
                curr = curr -> right;

            }else{
                 Node* prev = curr->left;
                 while( prev -> right && prev->right!=curr)
                 {
                     prev = prev->right;
                 }
                 if(prev -> right == NULL )
                 {
                     prev -> right = curr;
                     curr = curr -> left;
                 }else{
                     prev -> right = NULL;
                     ans.push_back(curr->data);
                     curr = curr-> right;
                 }
            }
        }
        return ans;

        
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

  


   vector<int> dist;
   dist = preorderTraversal(root);
   for(auto it: dist)
   {
    cout<<it<<" ";
   }cout<<endl;

 

  
}