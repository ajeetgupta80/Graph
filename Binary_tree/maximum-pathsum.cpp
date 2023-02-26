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










int main() 
{
	struct Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> right -> left = new Node(4);
    root -> right -> right = new Node(5);
    root -> right -> left -> left = new Node(6);

	return 0;
}