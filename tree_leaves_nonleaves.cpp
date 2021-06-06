#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node
{   public:
    int data;
    node *left,*right;
    node(int val)
    {
        data=val;
        left = NULL;
        right=NULL;
    }
};
//counting no of leaves and non leaves in a tree
 /* we can do this program in two ways:
    1. count leaves and non leaves separately 
    2. count total no. of nodes and no of leaves 
        then non-leaves = total-leaves
Here I am going to use 1st process. */
int count_leaves(node* n)
{
    // RECURSIVE EQUATION is :
        /* count(n)= 0; if n is null
                    = 1 ; if n is a leaf
                    = count(left)+count(right); (leaves in left and right subtree)  */
    
    if(n==NULL) return 0;
    if(((n->right)==NULL)&&((n->left)==NULL)) return 1;
    return (count_leaves(n->left)+count_leaves(n->right));

}
int count_nonleaves( node* n)
{
    //RECURSIVE EQUATION IS :
        /* COUNT(N) = 0 ; IF N IS NULL OR N IS A LEAF
                    = 1+ COUNT(LEFT) + COUNT(RIGHT); (1 is added since the root will also be a non leaf) */
    if(n==NULL) return 0;
    if(((n->left)==NULL)&&((n->right)==NULL)) return 0;
    return (1+count_nonleaves(n->right)+count_nonleaves(n->left));
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
                                      2   3                 no of leaves =2 
                                     /     \                no of non-leaves = 3
                                    5       6 */
    int l=count_leaves(root);
    int nl= count_nonleaves(root); 
    cout<<"\n no of leaves in the tree is :"<<l;
    cout<<"\n no of non leaves in the tree is : "<<nl;
return 0;
}