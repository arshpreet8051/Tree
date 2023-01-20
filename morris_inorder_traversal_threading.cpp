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
/*    Algorithm  1) :
                    Logic -> 
                
                case 1) if Left of curr does NOT exsits
                            { print curr->data;
                              move to right ----> curr = curr->right;
                             }
                
                case 2) else { ---> left exsists

                            create node temp = curr->left;
                            move temp to right untill
                                                    1) --> temp->right becomes NULL {create threading make temp->right to point curr and move to left;}
                                                    2) --> temp->right points to curr {threading already there , remove it temp->right = NULL and store curr->data and move right}

                }
                             
*/ 

vector<int> morris_inorder_traversal(node* root){

    node* curr = root;
    vector<int> ans;

    while(curr!=NULL){

        //case 1) left does not exsist
        if(curr->left == NULL){
            ans.push_back(curr->data); // store data
            curr = curr->right; //move right
        }

        //case 2) left exsists
        else{
                node* temp = curr->left;

                while(temp->right and temp->right!=curr){
                    temp = temp->right; // finding right-most guy
                }

                //case 1) no threading (temp->right == NULL)
                            // create threading
                if(temp->right == NULL){
                    temp->right = curr; //creating thread
                    curr = curr->left;  // move left
                }

                //case 2) threading already done(remove threading)
                else{
                    ans.push_back(curr->data);
                    temp->right = NULL;
                    curr = curr->right; //move right
                }
        }

    }
    return ans;

}