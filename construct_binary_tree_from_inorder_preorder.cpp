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
                    Logic -> . Take index from preorder as root
                             . find root element ki position in inorder
                             . root->left call from inOrder-start to pos-1
                             . root->right call from pos+1 to inOrder-end
*/ 

node* construct_tree(int in[],int pre[],int n){

    int in_start = 0;
    int in_end = n-1;
    int pre_index = 0;

    node* ans = solve(in,in_start,in_end,pre,pre_index,n);

    return ans;
}

node* solve(int in[],int in_start,int in_end,int pre[],int &pre_index,int n){

    //base case
    if((pre_index >= n) or (in_start > in_end) ){
        return NULL;
    }

    int ele = pre[pre_index++]; // index gets increased
    node* root = new node(ele);
    int pos = find_pos(in,in_start,in_end,ele);

    root->left = solve(in,in_start,pos-1,pre,pre_index,n);
    root->right = solve(in,pos+1,in_end,pre,pre_index,n);

    return root;

}

int find_pos(int in[],int in_start,int in_end,int ele){

    //to traverse between in_start and in_end to tackle duplicate entries in tree
    for(int i = in_start;i <= in_end;i++){
        if(in[i] == ele){
            return i;
        }
    }
    return -1;
}
