#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;



// void init_code(){
//     #ifndef ONLINE_JUDGE
//     freopen("inptree.txt", "r", stdin);
//     freopen("outtree.txt", "w", stdout);
//     #endif 
// }



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

void preorder(Node *root)
{
    if(root == NULL )
    {
        return;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root -> right);
}
void post_order(Node * root)
{
    if(root == NULL)
        return;
    post_order(root->left);
    post_order(root->right);
    cout<<(root->data)<<" ";

}
// storing data in vector
vector<int> trav;
vector<int> PREorder(Node * root)
{
    
    if(root == NULL)
    {
        return trav;
    }
    trav.push_back(root->data);
    PREorder(root->left);
    PREorder(root->right);

    return trav;


}
void inorder(Node * root)
{
    if(root == NULL)
    {
        return ; 
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void bfs(Node * root)
{
    vector<vector<int> > ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        vector<int> level;
        for(int i=0; i<n; ++i)
        {
            Node * node = q.front();
            q.pop();
            if(node->left !=NULL ) q.push(node->left);
            if(node->right != NULL ) q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
 

}






int main() 
{
	// init_code();
	
    struct Node * root = new Node(1);
  root -> left = new Node(2);
  root -> right = new Node(3);
  root -> left -> left = new Node(4);
  root -> left -> right = new Node(5);
  root -> left -> right -> left = new Node(8);
  root -> right -> left = new Node(6);
  root -> right -> right = new Node(7);
  root -> right -> right -> left = new Node(9);
  root -> right -> right -> right = new Node(10);
    preorder(root);
    cout<<endl;
    cout<<"preorder using vector "<<endl;
    vector<int> ans;
    ans =  PREorder(root);
    for(int i = 0; i<ans.size(); ++i)
    {
        cout<<ans[i]<<" ";
    }cout<<endl;
    post_order(root);
    cout<<endl;
    inorder(root);
    


	return 0;
}