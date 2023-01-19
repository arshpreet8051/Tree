/*   IMPORTANT QUESTION   */

#include<bits/stdc++.h>
using namespace std;

class node{
        public:
    int data;
    node* left;
    node* right;
};

/*    Algorithm :
                    Logic -> . use recursion to find nodes
                             . after finding nodes from left and right return nodes themselves
                             . for all other nodes return NULL
                             . where u get non-NULL ans from both sides --> it is the answer
*/

node* lca(node* root,int n1,int n2){

    if(root==NULL){
        return NULL;
    }

    if(root->data == n1 or root->data == n2){ //base case
        return root;
    }

    node* leftAns = lca(root->left,n1,n2);
    node* rightAns = lca(root->right,n1,n2);// recursive calls for left and right

    if(leftAns != NULL and rightAns == NULL ){
        return leftAns;
    }

    else if(leftAns == NULL and rightAns != NULL){
        return rightAns;
    }

    else if(leftAns != NULL and rightAns != NULL){
        return root;
    }
    else{
        return NULL;
    }

}