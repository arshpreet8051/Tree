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

// This is RECURSIVE approach  T.C ---> O(n)
//                             S.C ---> O(n)

/*    Algorithm  :
                    Logic ->  --> push root in stack
                              --> iterate while stack is not empty
                              --> set curr to st.top() and st.pop()
                              --> if(right exsists){push in stack}
                              --> if(left exsists){push in stack}
                              --> set curr - > right to st.top();
                              --> set curr -> left to NULL

                             
*/ 


void flatten_tree_to_linked_list_iterative_stack(node* root){

    if(root == NULL){return;}
    stack<node*>st;
    st.push(root);

    while(!st.empty()){

        node* curr = st.top();
        st.pop();

        if(curr->right){ // pehla right push krna
            st.push(curr->right);
        }
        if(curr->left){
            st.push(curr->left);
        }

        if(!st.empty()){
        curr->right = st.top();
        }
        curr->left = NULL;
    }
}