#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// in this question used backtracking to find the path ....................................

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


 bool findpath(Node* root, vector<int> &path, int x)
 {
    if(!root)
      return false;

    path.push_back(root->data);
    if(root -> data == x)
      return true;
    
    if(findpath(root->left, path,x) || findpath(root -> right, path, x))
      return true;
    
    path.pop_back();
    return false;
   
 }
  






int main() 
{

  struct Node * root = new Node(1);
  root -> left = new Node(2);
  root -> left -> left = new Node(4);
  root -> left -> right = new Node(5);
  root -> left -> right -> left = new Node(6);
  root -> left -> right -> right = new Node(7);
  root -> right = new Node(3);

  
  vector<int> path;

  bool res;
  res = findpath(root, path, 7);
  

  for(auto &it:path)
  {
    cout<<it<<" ";
  }
  cout<<endl;
  

  
}