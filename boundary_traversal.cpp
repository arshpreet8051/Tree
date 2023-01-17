/*    Algorithm :
                    . Store main root da data in the begining
                    1) get all left nodes (except leaf)
                    2) get all leaf nodes
                    3) get all right node (in reverse order) (except leaf)
                    4) for right nodes we need print nodes in reverse order:
                      so trverse first and then print 

*/ 
#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
};

vector<int> boundary_traversal(node* root){

    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    /* 1 */ans.push_back(root->data);

    /* 2 */leftNodes(root->left,ans);

    /* 3 */leafNodes(root->left,ans);
    /* 4 */leafNodes(root->right,ans);

    /* 5 */rightNodes(root->right,ans);

    return ans;
}

void leftNodes(node* root,vector<int>&ans){
    if(root==NULL){
        return;
    }

    if(root->left == NULL and root->right==NULL){
        return;
    }

    ans.push_back(root->data);

    if(root->left){
        leftNodes(root->left,ans);
    }

}

void rightNodes(node* root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    if(root->left==NULL and root->right==NULL){
        return;
    }

    if(root->right){
        rightNodes(root->right,ans);
    }
    else{
        rightNodes(root->left,ans);
    }

    ans.push_back(root->data); // at last because we want reverse order of nodes
}

void leafNodes(node*root,vector<int>ans){
    
    if(root==NULL){
        return;
    }
    if(root->left==NULL and root->right==NULL){
        ans.push_back(root->data);
    }

    leafNodes(root->left,ans);
    leafNodes(root->right,ans);
}