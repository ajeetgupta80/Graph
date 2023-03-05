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

vector<int> top(Node* root)
{

    vector<int> ans;
     map<int,int> mp;
     queue<pair<Node*, int>> q;

     q.push({root, 0});
     while(!q.empty())
     {
        auto p = q.front();
        q.pop();
        
        Node* node = p.first;
        int line = p.second;

       if(mp.find(line) == mp.end())
       {
           mp[line] = node -> data;
       }
       if(node -> left)
         q.push({node->left, line-1});
        
       if(node -> right)
         q.push({node -> right, line+1});

        
     }
     for(auto &it: mp)
     {
        ans.push_back(it.second);
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


  vector<int> res;
  res = top(root);
  

  for(auto &it:res)
  {
    cout<<it<<" ";
  }
  cout<<endl;
  

  
}