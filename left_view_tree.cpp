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

                    Logic -> . first node of every level
                             . based on level only
                             . horizontal distance da koi kam nahi
                             . recursive calls based on view
                             . inorder traversal

                    

*/ 
void solve(node* root,vector<int>&ans,int lvl){
    if(root==NULL){
        return;
    }
    
    if(lvl==ans.size()) // conditon to indicate that we have reached new level
    {
        ans.push_back(root->data);
    }
    
    solve(root->left,ans,lvl+1);
    solve(root->right,ans,lvl+1);
    
}
vector<int> leftView(node *root)
{
   vector<int> ans;
   if(root==NULL){
       return ans;
   }
   
   solve(root,ans,0);
   return ans;
   
}