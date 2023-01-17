#include<set>
#include<queue>
#include<stdlib.h>
#include<map>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
};
/*    Algorithm :

    main condition = if(vector.size() == level) -----> means new level reached
    
                    Logic -> . last node of each level
                             . based on level only
                             . horizontal distance da koi kam nahi
                             . recursive calls based on view
                             . inorder traversal (right call first)

                    

*/ 
void solve(node* root,vector<int>&ans,int lvl){
    if(root==NULL){
        return;
    }
    
    if(lvl==ans.size()) // conditon to indicate that we have reached new level
    {
        ans.push_back(root->data);
    }
    
    solve(root->right,ans,lvl+1);
    solve(root->left,ans,lvl+1);
    
    }
    //Function to return list containing elements of right view of binary tree.
vector<int> rightView(node *root)
    {
       vector<int> ans;
   if(root==NULL){
       return ans;
   }
   
   solve(root,ans,0);
   return ans;
    }