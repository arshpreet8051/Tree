#include<bits/stdc++.h>
using namespace std;

class node{
        public:
    int data;
    node* left;
    node* right;
};
/*    Algorithm :
                    To find kth ancestor of given node
                    
                    Logic -> . traverse roots by recursion 
                             . when you get " node " keep returnig and subtracting k
                             . when k == 0 ---> you have reached answer node
                             . set k = INT_MAX to lock anwer and return root
*/ 

int Kth_ancestor(node* root,int t_node,int k){

    node* ans = solve(root,t_node,k);

    if(ans == NULL or ans->data == t_node) { // conditon to check that the node is root itself
        return -1;
    }
    else{
        return root->data;
    }
}

node* solve(node* root,int t_node,int &k){ // to pass k by reference
    if(root==NULL){
        return NULL;
    }

    if(root->data == t_node){ // base case
        return root;
    }

    node* leftAns = solve(root->left,t_node,k);
    node* rightAns = solve(root->right,t_node,k);

    if(leftAns == NULL and rightAns != NULL){
        k--;
        if(k<=0){
            k = INT_MAX; // to lock answer;
            return root;
        }
        return rightAns;
    }

    if(rightAns == NULL and leftAns != NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    return NULL;

}


/* Another approach*/
/* vector wali*/
node* solve(node* root,int k,int Node,vector<int>& count){

    if(root==NULL){

        return NULL;
    }

    if(root->data == Node){
        return root;

    }
    node* left = solve(root->left,k,Node,count);
    node* right = solve(root->right,k,Node,count);

    if(left==NULL && right==NULL){
        return NULL;
    }

    else if(left!=NULL && right==NULL){
        count.push_back(root->data);
        return left;
    }
    else if(right!=NULL && left==NULL){
        count.push_back(root->data);
        return right;
    }
}

 

int kthAncestor(node *root, int k, int Node)

{

    // Code here

    vector<int>count;

    if(root->data==Node){

        return -1;

    }

    nsode*ans = solve(root,k,Node,count);

    if(k<=count.size()){

        return count[k-1];

    }

    return -1;
}