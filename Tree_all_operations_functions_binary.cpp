#include<iostream>
#include<queue>
#include<stack>
using namespace std;

/*

    Function                 -------> Logic 

1) build tree                -------> new node creation by recursive calls
2) level order traversal     -------> Queue
3) inorder recursive         -------> Recursion
4) inorder iterative         -------> Stack
5) preorder recursive        -------> Recursion
6) postorder recursive       -------> Recursion
7) height O(n^2)             -------> Recursive calls
8) height O(n)               -------> level order traversal
9) diameter O(n^2)           -------> Dia left -- Dia Right -- height(root)
10) diameter O(n)            -------> using pair to store height (avoid recursive calls)
11) check balanced O(n^2)    -------> condition = | H (left) - H (right) | <= 1
12) check balanced O(n)      -------> using pair to store height
13) identical tree           -------> inorder traversal & checking data elements
14) sum tree                 -------> root -> data = left(subtree) + right(subtree)
*/

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

// 1) Building Tree
node* build_tree(node* root){

    int d;
    cout<<"Enter value : ";
    cin>>d;

    if(d==-1){return NULL;}

    root = new node(d);

    cout<<"For left of "<<d<<endl;
    root->left = build_tree(root->left);
    cout<<"For right of "<<d<<endl;
    root->right = build_tree(root->right);

    return root;
}

// 2) Level order traversal
void level_order_traversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        if(temp==NULL and q.size()==0){return;}
        else if(temp == NULL and q.size()>0)
        {
            q.push(NULL);
            cout<<endl;
        }   
        else{
            cout<<temp->data<<" ";
            if(temp->left){q.push(temp->left);}
            if(temp->right){q.push(temp->right);}
        }
    }
}

// 3) Inorder Traversal ===== left root right
void inorder(node* root){
    if(root==NULL){return;}

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// 4) Inorder (Iterative)
void inorder_itr(node* root){
    stack<node*> st;
    node* temp = root;

    while(true){     // -----> Striver's Logic

        if(temp!=NULL){
            st.push(temp);
            temp = temp->left;
        }
        else{
            if(st.empty()){break;}
            temp = st.top();
            st.pop();
            cout<<temp->data<<" ";
            temp = temp->right;
        }
    }
}

// 5) preorder (Recursive) -----> root left right
void preorder(node* root){
    if(root==NULL){return;}

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// 6) postorder (Recursive) -----> left right root
void postorder(node* root){
    if(root==NULL){return;}

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

// 7) Height of Binary Tree O(n^2)
int height(node* root){
    if(root==NULL){return 0;}

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right)+1;
    return ans;
}

// 8) Height in O(n)
int fast_height(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int count = 1;

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp==NULL and q.size()==0){return count;}
        else if(temp==NULL and q.size()>0){
            q.push(NULL);
            count++;
        }
        else{
            if(temp->left){q.push(temp->left);}
            if(temp->right){q.push(temp->right);}
        }
    }
    //return count;
}

// 9) Diameter O(n^2)
int diameter(node* root){
    if(root==NULL){
        return 0;
    }

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left)+height(root->right)+1;

    int ans = max(op1,max(op2,op3));
    return ans;
    
    }

// 10) Diameter O(n)
pair<int,int> fast_diameter(node* root){
    if(root==NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = fast_diameter(root->left);
    pair<int,int> right = fast_diameter(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second+right.second+1;

    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second,right.second)+1;
    return ans;
}

// 11) Balanced Tree O(n^2)
bool balanced(node* root){
    if(root==NULL){
        return true;
    }

    bool left = balanced(root->left);
    bool right = balanced(root->right);

    bool condition = abs(height(root->left)-height(root->right))<=1;

    if(left and right and condition){
        return true;
    }
    else{
        return false;
    }
}

// 12) Balanced O(n)
 pair<bool,int> fast_balanced(node* root){
        if(root==NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        pair<bool,int> left = fast_balanced(root->left);
        pair<bool,int> right = fast_balanced(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool condition = abs(left.second - right.second) <= 1;
    
        pair<bool,int> ans;
        if(leftAns and rightAns and condition){
            ans.first = true;
            ans.second = max(left.second,right.second)+1;
        }
        else{
            ans.first = false;
        }
        
        return ans;
 }

 // 13) Identical Trees
 bool inorder(node* r1,node* r2){
            if(r1==NULL and r2==NULL){
                return true;
            }
            if(r1==NULL and r2!=NULL){
                return false;
            }
            if(r2==NULL and r1!=NULL){
                return false;
            }
            
            bool left = inorder(r1->left,r2->left);
            bool right = inorder(r1->right,r2->right);
            
            bool ans;
            if(left and right and r1->data==r2->data){
                ans = true;
            }
            else{
                ans = false;
            }
            return ans;
 }

// 14) Sum tree = O(n)
 pair<bool,int> sum_tree(node* root){
        if(root == NULL){
            pair<bool,int> p =make_pair(true,0);
            return p;
        }
        if(root->left==NULL and root->right==NULL){
            pair<bool,int> x = make_pair(true,root->data);
            return x;
        }
        
        pair<bool,int> left = sum_tree(root->left);
        pair<bool,int> right = sum_tree(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool condition = root->data == left.second+right.second;
        
        pair<bool,int> ans;
        if(leftAns and rightAns and condition){
            ans.first =  true;
            ans.second = root->data+left.second+right.second;
        }
        else{
            ans.first =  false;
        }
        
        return ans;
    }

int main(){
    /*INPUT testcase 
    1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    */

    node* root = NULL;
    
    root = build_tree(root);
    cout<<" "<<endl;
    cout<<"\nLevel Order Traversal "<<endl;
    level_order_traversal(root);
    cout<<" "<<endl;
    cout<<"\nInorder (Recursive) -> ";
    inorder(root);
    cout<<" "<<endl;
    cout<<"\nInorder (Iterative) -> ";
    inorder_itr(root);
    cout<<" "<<endl;
    cout<<"\nPreorder (Recursive) -> ";
    preorder(root);
    cout<<" "<<endl;
    cout<<"\nPostorder (Recursive) -> ";
    postorder(root);
    cout<<" "<<endl;
    cout<<"\nHeight O(n^2) -> "<<height(root);
    cout<<" "<<endl;
    cout<<"\nHeight O(n) -> "<<fast_height(root);
    cout<<" "<<endl;
    cout<<"\nDiameter O(n^2) -> "<<diameter(root);
    cout<<" "<<endl;
    cout<<"\nDiameter O(n) -> "<<fast_diameter(root).first;
    cout<<" "<<endl;
    cout<<"\nBalanced O(n^2) -> "<<balanced(root);
    cout<<" "<<endl;
    cout<<"\nBalanced O(n) -> "<<fast_balanced(root).first;
    
    
}