/*    Algorithm :
                    1) inorder traversal using queue
                    2) use of flag bool to dtermine direction
                    3) index = leftToRight ? i : size-1-i
                    4) using temporary vector with size mentioned
                    5) index alltment based on flag
                    6) or reverse temp based on flag
                    
*/ 

#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* right;
        node* left;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function for Zig Zag traversal
// also known as spiral traversal

vector<int> zig_zag(node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    queue<node*> q;
    q.push(root);

    bool leftToRight = true;    /* NOTE:------> using flag to get direaction of traversal*/

    while(!q.empty()){
        int size = q.size();
        vector<int> temp(size); /* using temporary vector with size intialised*/

        for(int i = 0;i<size;i++){
            node* t = q.front();
            q.pop();

            int index = leftToRight ? i : size-1-i; /*  IMP (main Logic) ----> 
                                                        using terenary operator to
                                                        get position of insertion */
            temp[index] = t->data;

            if(t->left){q.push(t->left);}
            if(t->right){q.push(t->right);}    
        }

        for(auto x : temp){
            ans.push_back(x);
        }

        leftToRight = !leftToRight;  /* Don't forget this step */

    }     

    return ans;

}


int main(){

}
