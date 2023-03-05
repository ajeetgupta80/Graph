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


void find(Node* root, int level, vector<int> &v){
    if(root == NULL )
     return;

    if(level == v.size())
    {
        v.push_back(root -> data);
    }

    find(root -> left, level+1,v);
    find(root -> right,level+1,v);

}

vector<int> right(Node* root)
{
    vector<int> v;
   find(root, 0,v);
   return v;
  


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


  vector<int> res;
  res = right(root);
  

  for(auto &it:res)
  {
    cout<<it<<" ";
  }
  cout<<endl;
  

  
}