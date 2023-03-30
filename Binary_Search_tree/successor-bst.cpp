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


Node* sucessor(Node* root, Node* key){
    
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

  int k = findceil(root, 7);
  cout<<k<<endl;

  


 

  
}