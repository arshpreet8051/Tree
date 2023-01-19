/* Question --> Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
A path may start from any node and end at any node in the downward direction*/

#include<bits/stdc++.h>
using namespace std;

class node{
        public:
    int data;
    node* left;
    node* right;
};
/*    Algorithm :
                    Logic -> . use a vector to push back node's data at each recursive call
                             . on that vector apply k sum logic
                             . if k sum condition satisfied ---> cnt++
                             . return cnt++
                            
    GFG ----> only down-ward directed paths -----> backtracking ----> path.pop_back()
    Leetcode -----> no need of backtracking

*/ 

int K_sum_paths(node* root,int k){

    vector<int> path;
    int count = 0;
    solve(root,k,path,k);

    return count;
}

void solve(node* root,int &count, vector<int> path,int k){

    if(root==NULL){ return;}
     
     path.push_back(root->data);

     solve(root->left,count,path,k);
     solve(root->right,count,path,k);

     // K-sum logic
     int size = path.size();
     int sum = 0;
     for(int i = size-1;i>=0;i--){
        sum+=path[i];
        if(sum==k){
            count++;
        }
     }
    }