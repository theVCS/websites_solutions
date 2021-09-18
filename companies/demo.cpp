#include <iostream>
#include <stack>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

void preorder(Node *root)
{
    stack<Node*>st;
    st.push(root);

    while (st.empty()==false)
    {
        Node *node = st.top();
        st.pop();
        cout<<node->data<<" ";
        if(node->right)st.push(node->right);
        if(node->left)st.push(node->left);
    }
}

void inorder(Node *root)
{
    stack<Node*>st;
    Node *curr = root;

    while(st.empty()==false || curr)
    {
        while(curr)
        {
            st.push(curr);
            curr = curr->left;
        }

        cout<<st.top()->data<<" ";
        curr=st.top()->right;
        st.pop();
    }
}

void postorder(Node *root)
{
    stack<Node*>st;
    stack<int>res;

    st.push(root);

    while(st.empty()==false)
    {
        Node *node = st.top();
        st.pop();

        res.push(node->data);

        if(node->left)st.push(node->left);
        if(node->right)st.push(node->right);
    }

    while(res.empty()==false)
    {
        cout<<res.top()<<" ";
        res.pop();
    }
}

int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    preorder(root);cout<<endl;
    postorder(root);cout<<endl;
    inorder(root);cout<<endl;

    return 0;
}