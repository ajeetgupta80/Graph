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

int mindepth(Node* root)
{
    if(root  == NULL )
     return 0;

    if(root -> left!=NULL && root -> right !=NULL )
    {
        int la = mindepth(root->left);
        int ra = mindepth(root ->right);
        return 1+min(la,ra);

    }else{

       int lb = mindepth(root -> left);
       int rb  = mindepth(root -> right);
       return 1+max(lb,rb);
    }
      
}








int main() 
{
	struct Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> right -> left = new Node(4);
    root -> right -> right = new Node(5);
    root -> right -> left -> left = new Node(6);
    
    int k = mindepth(root);
    cout<<k<<endl;

	return 0;
}