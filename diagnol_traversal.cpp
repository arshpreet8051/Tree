// #include<set>
// #include<queue>
// #include<stdlib.h>
// #include<map>
// #include<vector>
#include<bits/stdc++.h>
using namespace std;

class node{
        public:
    int data;
    node* left;
    node* right;
};
/*    Algorithm :
                    Logic -> . store root data
                             . if left exists push in queue
                             . while queue is not empty
                             . get front
                             . store front node data
                             . if left exists push in queue
                             . move root to right
                             . repeate

    root ka right print krwate jao or agar left hai to queue mai push krte jao

*/ 
vector<int> diagonal(node *root)
{
   vector<int> ans;
   if(root==NULL){
       return ans;
   }
   
   queue<node*> q;
   q.push(root);
   
   while(!q.empty()){
       node* temp = q.front();
       q.pop();
       
       while(temp){
           ans.push_back(temp->data);
           if(temp->left){
               q.push(temp->left);
           }
           temp = temp->right;
       }
       
   }
   return ans;
}