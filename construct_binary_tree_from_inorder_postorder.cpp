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
/*    Algorithm  1) :
                    Logic -> . Take index from postorder as root
                             . here index will be n-1
                             . find root element ki position in inorder
                             Note---> for postorder right tree will be build first
                             . root->right call from pos+1 to inOrder-end
                             . root->left call from inOrder-start to pos-1
                             
*/ 

node* construct_tree_inorder_postorder(int in[],int post[],int n){
    int in_start = 0;
    int in_end = n-1;
    int post_index = n-1;

    node* ans = solve(in,in_start,in_end,post,post_index,n);
    return ans;
}

node* solve(int in[],int in_start,int in_end,int post[],int &post_index,int n){
    // base case
    if((post_index < 0) or (in_start > in_end)){
        return NULL;
    }

    int ele = post[post_index--];
    node* root = new node(ele);
    int pos = find_pos(in,in_start,in_end,ele);

    //incase of postorder and inorder right subtree will be build first
    root->right = solve(in,pos+1,in_end,post,post_index,n);
    root->left = solve(in,in_start,pos-1,post,post_index,n);

    return root;
}

int find_pos(int in[],int in_start,int in_end,int ele){
    //finding element in inorder
    for(int i = in_start;i<=in_end;i++){
        if(in[i] == ele){
            return i;
        }
    }
    return -1;
}