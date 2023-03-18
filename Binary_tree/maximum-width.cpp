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

int maxwidth(Node* root )
{
     if(root == NULL )
      return 0;

     queue<pair<Node*,int>> q;
     q.push({root,0});

     int ans =0;
     

     while(!q.empty())
     {
        int m = q.size();
        int mini = q.front().second;
        int first;
        int last;
       

        for(int i=0; i<m; ++i)
        {
            long long curr_id = q.front().second-mini;
             Node* node = q.front().first;
             q.pop();

             if(i == 0) first= curr_id;
             if(i == m-1) last = curr_id;
             if(node->left)
              q.push({node->left, curr_id*2+1});
             if(node -> right)
               q.push({node->right, curr_id*2+2});
        }
        ans = max(ans, last-first+1);

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

  int x = maxwidth(root);
  cout<<x<<endl;

  
}