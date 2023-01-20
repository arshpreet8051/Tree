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
// Similar to Morris inorder Traversal just print ans while creating thread and not while remoing thread
// only one line change


/*    Algorithm  1) :
                    Logic -> 
                
                case 1) if Left of curr does NOT exsits
                            { print curr->data;
                              move to right ----> curr = curr->right;
                             }
                
                case 2) else { ---> left exsists

                            create node temp = curr->left;
                            move temp to right untill
                                                    1) --> temp->right becomes NULL {create threading make temp->right to point curr and store curr->data and move to left;}
                                                    2) --> temp->right points to curr {threading already there , remove it temp->right = NULL and move right}

                }
                             
*/

vector<int> morris_preorder_traversal(node*root){
    vector<int> ans;
    node* curr = root;

    while(curr!=NULL){

        if(curr->left == NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        }

        else{
            node* temp = curr->left;
            while(temp->right and temp->right!=curr){
                temp = temp->right;
            }

            if(temp->right==NULL){
                ans.push_back(curr->data);
                temp->right = curr;
                curr = curr->left;
            }

            else{
                temp->right = NULL;
                curr = curr->right;
            }
        }
    }
    return ans;
}

// for more clarity refer striver's video and morris inorder traversal .cpp