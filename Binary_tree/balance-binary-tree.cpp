#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};



int dfs(Node* root)
{
     if(root == NULL )
     return 0;

     int l = dfs(root->left);
     if(l == -1)
        return -1;

     int r = dfs(root -> right);
     if(r == -1)
        return -1;
     

     if(abs(l-r)>1)
       return -1;

     return max(l,r)+1;
}
bool check(Node* root)
{ 
    return dfs(root)!=-1;
    
}


int main()
{

    struct Node* root = new Node(1);
    root ->left = new Node(2);
    root -> right = new Node(2);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(3);
    // root -> right -> right -> left = new Node(7);
    root -> left -> left -> left = new Node(4);
    root -> left -> left -> right = new Node(4);

    if(check(root))
    {
       cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }

     
}

