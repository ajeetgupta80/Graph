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


void markparent(Node* root, unordered_map<Node*,Node*> &parent, int k)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* current = q.front();
        q.pop();
        if(current -> left)
        {
            parent[current->left] = current;
            q.push(current->left);
        }
        if(current -> right)
        {
            parent[current->right] = current;
            q.push(current->right);
        }
    }

}



vector<int> kdistacne(Node* root, Node* target, int k)
{
    unordered_map<Node*,Node*> parent;
    markparent(root, parent, k);

    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(target);
    visited[target] = true;
    int curr_level = 0;

    while(!q.empty())
    {
        int m  = q.size();
        if(curr_level++ == k) break;


        for(int i = 0; i<m; ++i )
        {
            Node* current = q.front();
            q.pop();
            if(current->left && !visited[current->left])
            {
                q.push(current->left);
                visited[current->left] = true;
            }

            if(current->right && !visited[current->right]){
                q.push(current->right);
                visited[current->right] = true;
            }

            if(parent[current] && !visited[parent[current]])
            {
                q.push(parent[current]);
                visited[parent[current]]= true;
            }

        }
    }

    vector<int> res;
    while(!q.empty())
    {
        Node* curent = q.front();
        q.pop();
        res.push_back(curent->data);
    }

    sort(res.begin(), res.end());
    return res;


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
   dist = kdistacne(root,target,k);


 

  
}