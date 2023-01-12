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

void preorder(Node* root)
{
    vector<int> ans;
    stack<Node*> st;
    if(root== NULL) return;
    st.push(root);
    while(!st.empty())
    {
        root = st.top();
        st.pop();
        ans.push_back(root->data);
        if(root->right != NULL) st.push(root->right);
        if(root->left !=NULL ) st.push(root->left);
    }
    for(int i=0; i<ans.size(); ++i)
    {
        cout<<ans[i];
    }

}

void inorder(Node * root)
{
    vector<int> ans;
    stack<Node*> st;
    if(root == NULL )
      return ;

    Node* node = root;

    while(true)
    {
        if(node != NULL )
        {
            st.push(node);
            node = node->left;

        }
        else
        {
            if(st.empty()== true) break;
            node = st.top();
            st.pop();
            ans.push_back(node->data);
            node = node->right;


        }
    }
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;

}

// post order iteratively using 2 stacks and 1stack
void stack_1(Node * root)
{
    vector<int> ans;
    if(root == NULL)
    {
        return;
    }
    stack<Node*> st1,st2;
    st1.push(root);
    while(!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left !=NULL ){ st1.push(root->left );};
        if(root->right !=NULL ){ st1.push(root->right);};


    }
    while(st2.empty()==0)
    {
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
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
  inorder(root);
  stack_1(root);


	return 0;
}