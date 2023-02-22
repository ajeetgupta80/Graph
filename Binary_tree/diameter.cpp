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

int maxi =0;
 



int diam(Node* root,maxi)
{
     if(root == NULL )
     return 0;


     int l = diam()
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
    // root -> left ->left ->left -> = new Node(5);

    if(check(root))
    {
       cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }

     
}

