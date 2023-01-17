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
                    
                    HARD ---- > Leetcode
                    
                    Logic -> . number line system wali example
                             . horizontal distance mapping -> level-wise mapping
                             . use of 2 maps
                             . use of level as well as horizontal distance
                             . use of multiset -> coz same [lvl[hd] nodes to be ascending
                             . Level order logic

                    

*/ 
vector<vector<int>> vertical_traversal(node* root){
    vector<vector<int>> ans;
    if(root == NULL){
        return ans;
    }

    map<int,map<int,multiset<int>>> mp;
    queue<pair<node*,pair<int,int>>> q;

    q.push(make_pair(root,make_pair(0,0)));

    while(!q.empty()){
        pair<node*,pair<int,int>> temp = q.front();
        q.pop();

        node* t = temp.first;
        int lvl = temp.second.first;
        int hd = temp.second.second;

        mp[hd][lvl].insert(t->data);

        if(t->left){
            q.push(make_pair(t->left,make_pair(lvl+1,hd-1)));
        }
        if(t->right){
            q.push(make_pair(t->right,make_pair(lvl+1,hd+1)));
        }
    }
    for(auto i : mp){
        vector<int> temp;
        for(auto j : i.second){
            temp.insert(temp.end(),j.second.begin(),j.second.end());
        }
        ans.push_back(temp);
    }
    return ans;

}




/*    Algorithm :
                    
                    Medium ---- > GFG
                    
                    Logic -> . number line system wali example
                             . horizontal distance mapping -> level-wise mapping
                             . use of map
                             . Level order logic

                    

*/

vector<int> vertical_traversal_gfg(node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    map<int,vector<int>> mp;
    queue<pair<node*,int>> q;

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node*,int> temp = q.front();
        q.pop();

        node* t = temp.first;
        int hd = temp.second;

        mp[hd].push_back(t->data);

        if(t->left){
            q.push(make_pair(root->left,hd-1));
        }
        if(root->right){
            q.push(make_pair(root->right,hd+1));
        }
    }

    for(auto i:mp){
        for(auto j:i.second){
            ans.push_back(j);
        }
    }
    return ans;
}