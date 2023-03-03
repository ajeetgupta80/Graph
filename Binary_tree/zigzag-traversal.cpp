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


void zigzag(Node* root)
{
     
      vector<vector<int> > ans;
      queue<Node*> quenode;
      bool flag = true;

      quenode.push(root);
      while(!quenode.empty())
      {
        int size = quenode.size();
        vector<int> row(size);
        for(int i =0; i<size; ++i )
        {
            Node* node = quenode.front();
            quenode.pop();


            int ind = (flag)?i:(size-1-i);

            row[ind] = node->data;
            if(node -> left)
              quenode.push(node->left);
            if(node -> right)
              quenode.push(node->right);

        }
        flag = !flag;
        ans.push_back(row);
      }

      for(auto &it:ans)
      {
         for(auto &x:it)
         {
             cout<<x<<" ";
         }
      }
      cout<<endl;

}

int main() 
{
    int maxi = 0; 
	struct Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> right = new Node(6);

    zigzag(root);

	return 0;
}