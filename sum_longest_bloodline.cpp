// #include<set>
// #include<queue>
// #include<stdlib.h>
// #include<map>
// #include<vector>
// #include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

class node{
        public:
    int data;
    node* left;
    node* right;
};
/*    Algorithm :
                    Logic -> . using variables ---> len , max_len , sum , max_sum
                             . len ---> to track length of bllodline
                             . max_len ---> to compare if len has become more than len
                             . sum ---> to calculate sum after reaching each new node
                             . max_sum ---> to compare sum if len == max_len
                             . store sum as max_sum only when len > max_len
                             . if(len == max_len) ---> max_sum = max( max_sum , sum )

*/ 

int max_sum_bloodline(node* root){
    int sum = 0;
    int max_sum = INT_MIN;

    int len = 0;
    int max_len = INT_MIN;

    solve(root,sum,max_sum,len,max_len);

    return max_sum;
}

void solve(node* root,int sum,int &max_sum,int len,int &max_len){
    if(root==NULL){

        if(len > max_len){
            max_len = len;
            max_sum = sum;
        }

        if(len==max_len){
            max_sum = max(sum,max_sum);
        }

        return;
    }

    sum = sum + root->data;

    solve(root->left,sum,max_sum,len,max_len);
    solve(root->right,sum,max_sum,len,max_len);
}
