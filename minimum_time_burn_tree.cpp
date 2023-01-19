#include<bits/stdc++.h>
using namespace std;

class node{
        public:
    int data;
    node* left;
    node* right;

    node(int x){
        this->data = x;
        this->right = NULL;
        this->left = NULL;
    }
};
/*    Algorithm :
                    Logic -> . create child to parent mapping--> queue(level order) --> map
                             . find target node
                             . burn tree using BFS ----> queue ----> map (visited)
                             . 1 --> burn left child
                             . 2 --> burn right child
                             . 3 --> burn parent
*/ 
int minimum_time_burn_tree(node* root,int target){
    
    unordered_map<node*,node*> childToParent;

    //function to create mapping and find target node
    node* targetNode = create_mapping(root,target,childToParent);

    //function to burn tree
    int ans = burn_tree(targetNode,childToParent);
}

node* create_mapping(node* root,int target,unordered_map<node*,node*>&childToParent){

    queue<node*> q;
    q.push(root);
    childToParent[root] = NULL;

    node* res = NULL;

    while(!q.empty()){
        node* front = q.front();
        q.pop();

        if(front->data == target){
            res = front;
        }

        if(front->left){
            q.push(front->left);
            childToParent[front->left] = front;
        }
        if(front->right){
            q.push(front->right);
            childToParent[front->right] = front;
        }
    }
    return res;
}

int burn_tree(node* root,unordered_map<node*,node*> childToParent){
    
    unordered_map<node*,bool> visited;
    queue<node*> q;
    int ans = 0;

    q.push(root);
    visited[root] = true;

    while(!q.empty()){
        
        bool flag = 0;
        int size = q.size();

        for(int i = 0;i<size;i++){
            node* front = q.front();
            q.pop();

            //burning left child
            if(front->left and !visited[front->left]){
                q.push(front->left);
                visited[front->left] = true;
                flag = 1;
            }

            //burning right child
            if(front->right and !visited[front->right]){
                q.push(front->right);
                visited[front->right] = true;
                flag = 1;
            }

            //burning parent
            if(childToParent[front] and !visited[childToParent[front]]){
                q.push(childToParent[front]);
                visited[childToParent[front]] = true;
                flag = 1;
            }
        }
        if(flag==1){
            ans++;
        }

        return ans;
    }
}