#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
// its a fucking hard question babe ---- -  -- - - -- ---------------

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


 vector<vector<int>> findvertical(Node* root )
 {
     map<int, map< int, multiset<int>>> nodes;
     queue<pair<Node*, pair<int,int>>> todo;

     todo.push({root, {0,0}});

     while(!todo.empty()){
    
        auto p = todo.front();
        todo.pop();

        Node* node = p.first;
        
      
        // vertical = x  level = y
        int x = p.second.first;
        int y = p.second.second;
    
     nodes[x][y].insert(node->data);
     if(node->left){
        todo.push({node->left, {x-1,y+1}});
     }
     if(node->right){
       todo.push({node->right,{x+1,y+1}});
     }

     }

     vector<vector<int>> ans;
     for(auto &p:nodes)
     {
        vector<int> col;
        for(auto &k:p.second){
            col.insert(col.end(), k.second.begin(), k.second.end());
        
        }
        ans.push_back(col);
     }
return ans;

     
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


  vector<vector<int>> res;
  res = findvertical(root);

  for(auto &it:res)
  {
     for(auto &x:it)
     {
         cout<<x<<" ";
     }cout<<endl;
  }
  

  
}