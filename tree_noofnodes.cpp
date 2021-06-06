#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//counting no. of nodes in a tree
class node
{
    public:
        int data;
        node *left,*right;
        node(int val)   //constructor to create node
        {
            data=val;
            left = NULL;
            right = NULL;
        }
};
int countnode(node* n)
{
    /* by analysing the recurrence relation we get the relation as
        count(n)= 0 if n is null
                = 1+ count(left subtree) + count(right subtree) 
        again in the relation we add 1 for the node(root node) passed in the function */
    if(n==NULL) return 0;
    else
    {
        return(1+countnode(n->left)+countnode(n->right));
    }
}
int main()
{
    node* root = new node(1);
    root->right = new node(3);
    root->left = new node(2);
    root ->left->left = new node (5);
    root->right->right = new node (6);
    /* the above tree looks like 
                                        1
                                       / \                  no of nodes = 5
                                      2   3
                                     /     \
                                    5       6 */
    int nodes=countnode(root);
    cout<<"\n no of nodes in the tree is :"<<nodes;

}