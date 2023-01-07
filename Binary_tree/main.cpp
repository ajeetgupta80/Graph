#include<iostream>
#include<vector>
using namespace std;



void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("inptree.txt", "r", stdin);
    freopen("outtree.txt", "w", stdout);
    #endif 
}



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






int main() 
{
	init_code();
	
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
    


	return 0;
}