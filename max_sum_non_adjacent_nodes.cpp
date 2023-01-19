#include<bits/stdc++.h>
using namespace std;

class node{
        public:
    int data;
    node* left;
    node* right;
};
/*    Algorithm  1) :
                    Logic -> . use pair to store ans for 2 cases
                             . pair < int a ,int b >
                             . case 1) --> a = including node data 
                             . case 2) --> b = when node is excluded
                            
    when we can include node then we cannot include child node so we will consider 
    child node's pair's right

    when we donot include root then we can include child or may not wherever the sum is 
    maximum;

            Main Logic -->  .pair < a, b >
                            .a = root->data + left.second + right.second
                            . b = max(left.first,left.second) + max(right.first,right.second)

*/ 

int max_sum_non_adjacent(node* root){

    pair<int,int> ans = solve(root);
    return max(ans.first,ans.second);
}

pair<int,int> solve(node* root){
    
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);

    pair<int,int> res;

    // including node
    res.first = root->data + left.second + right.second;

    //excluding node
    res.second = max(left.first,left.second) + max(right.first,right.second);

    return res;

}


/*    Algorithm  2) :
                    Logic -> . when included root -----> recursive calls for grandchildren
                             . when root excluded ------> recursive calls for children
                             . using map for optimization
                             . DP approach
                            
    when we can include node then we cannot include child node so we will consider 
    child node's pair's right

    when we donot include root then we can include child or may not wherever the sum is 
    maximum;

            Main Logic -->  .pair < a, b >
                            .a = root->data + left.second + right.second
                            . b = max(left.first,left.second) + max(right.first,right.second)

*/ 

unordered_map<node*,int> mp;

int max_sum_non_adjacent_dp(node* root){

    if(root == NULL){return 0;}

    //optimization
    if(mp[root]){
        return mp[root];
        }

    int with_node = root->data;

    if(root->left){
        with_node+=max_sum_non_adjacent_dp(root->left->left);
        with_node+=max_sum_non_adjacent_dp(root->left->right);
    }

    if(root->right){
        with_node+=max_sum_non_adjacent_dp(root->right->left);
        with_node+=max_sum_non_adjacent_dp(root->right->right);
    }


    int without_node = max_sum_non_adjacent_dp(root->left) + max_sum_non_adjacent_dp(root->right);

    return mp[root] = max(with_node,without_node);

}