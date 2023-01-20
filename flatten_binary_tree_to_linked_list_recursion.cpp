#include<bits/stdc++.h>
using namespace std;
class node{
        public:
    int data;
    node* left;
    node* right;

    node(int x){
        this->data = x;
        this->right = NULL;
        this->left = NULL;
    }
};

// This is RECURSIVE approach

/*    Algorithm  :
                    Logic ->  --> Set node* prev = NULL
                              --> if root NULL return
                              --> recursive call for right (1st)
                              --> recursive call dor left (2nd)
                             ... root->right = prev
                              .. root->left = NULL
                               . prev = root
                             
*/ 

class solution{
    public:

node* prev = NULL;

void flatten_tree_to_linked_list(node* root){

    if(root == NULL){return;}  //base case

    flatten_tree_to_linked_list(root->right);
    flatten_tree_to_linked_list(root->left);

    root->right = prev;
    root->left = NULL;
    prev = root;

    }
};