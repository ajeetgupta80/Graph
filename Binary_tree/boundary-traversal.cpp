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

bool isleaf(Node* root)
{
    return (!root->left && !root -> right);
}

void addleft(Node* root, vector<int> &ans)
{
    Node* curr = root -> left;
    while(curr)
    {
         if(!isleaf(curr))
         {
             ans.push_back(curr -> data);
         }
         if(curr -> left)
         {
            curr = curr -> left;
         }else{
            curr = curr -> right;
         }
    }
     
}

void addright(Node* root, vector<int> &ans)
{
    vector<int> temp;
    Node* curr = root -> right;
    while(curr)
    {
         if(!isleaf(curr))
         {
            temp.push_back(curr->data);
         }
         if(curr -> right)
         {
              curr = curr -> right;
         }else {
            curr = curr -> left;
         }
    }

    for(int i = temp.size()-1; i>=0; --i)
    {
         ans.push_back(temp[i]);
    }

     
}

void addleave(Node* root , vector<int> &ans)
{

    if(isleaf(root))
    {
        ans.push_back(root->data);
        return;
    }

    if(root -> left )
      addleave(root->left, ans);
    if(root -> right)
      addleave(root->right, ans);
     
}

vector<int> boundary(Node* root)
{
     vector<int> ans;
      if(!root)
      return ans;
   
      if(!isleaf(root))
      {
         ans.push_back(root->data);
      }

      addleft(root, ans);
      addleave(root, ans);
      addright(root, ans);

      return ans;
}





int main() 
{

  struct Node* root = new Node(1);
  root -> left = new Node(2);
  root -> left -> left = new Node(3);
  root -> left -> left -> right = new Node(4);
  root -> left -> left -> right -> left = new Node(5);
  root -> left -> left -> right -> right = new Node(6);
  root -> right = new Node(7);
  root -> right -> right = new Node(8);
  root -> right -> right -> left = new Node(9);
  root -> right -> right -> left -> left = new Node(10);
  root -> right -> right -> left -> right = new Node(11);

  
  vector<int> res;
  res = boundary(root);

  for(int i =0; i<res.size(); ++i)
  {
    cout<<res[i]<<" ";
  }
  cout<<endl;
   

	return 0;
}