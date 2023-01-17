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
                    Logic -> . Same as vertical traversal question
                             . number line system wali example
                             . horizontal distance mapping -> level-wise mapping
                             . use of map < hd , node->data >
                             . Level order logic -> queue < pair < node , hd > >
                             . last value of each vertical line will be ans
                             . use mp.erase() & insert only last value
                             . mp.erase() use krna v jarurui ni simply insert krde

                    

*/ 

vector<int> Top_view(node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    map<int,int> mp;
    queue<pair<node*,int>> q;

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node*,int> temp = q.front();
        q.pop();

        node* t = temp.first;
        int hd = temp.second;

        // just remove below login from top view

        // if(mp.find(hd)==mp.end()){//means fisrt entry
        //     mp[hd] = t->data;
        // }

        if(t->left){
            q.push(make_pair(t->left,hd-1));
        }
        if(t->right){
            q.push(make_pair(t->right,hd+1));
        }
    }
    for(auto i : mp){
        ans.push_back(i.second);
    }
    return ans;
}