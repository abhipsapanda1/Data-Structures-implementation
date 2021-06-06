#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node
{   public:
    int data;
    node* left;
    node* right;
    /*node (int val)
    {
        data = val;
        right = NULL;
        left = NULL;

    }*/
};
node* create_node(int val)
{
    node* nn;
    nn=new node;
    nn->data=val;
    nn->right = NULL;
    nn->left= NULL;
    return nn;
}
void preoder(node *n) //preorder travesal of a tree (using recursion)
{
    if(n)
    {
        cout<<(n->data)<<" ";
        preoder(n->left);
        preoder(n->right);
    }
}
void inorder(node *n)
{
    if(n)
    {
        inorder(n->left);
        cout<<(n->data)<<" ";
        inorder(n->right);
    }
}
void postorder(node *n){
    if(n)
    {
        postorder(n->left);
        postorder(n->right);
        cout<<(n->data)<<" ";
    }
}
int main()
{
    node* root =create_node(1);
    node* n1 = create_node(2);
    node* n2=  create_node(3);
    root->right = n2;
    root->left = n1;
    root->left->left = create_node(4);
    /* NOW THE BINARY TREE 
                    1
                   / \                  preorder: 1243     
                  2   3                 inodrder: 4213
                 / \                    postorder: 4231
                 4 NULL
                / \
             NULL  NULL
    */
   // now we will print the tree in preorder , inorder and postorder traversal
    cout<<"\n preoder traversal of the binary tree: ";
    preoder(root);
    cout<<"\n inorder traversal of the binary tree: ";
    inorder(root);
    cout<<"\n postorder traversal of the binary tree: ";
    postorder(root);
    return 0;

}

