#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~node(){
            delete left,right;
        cout<<"memory is free"<<endl;;
    }
};

// function to build a tree using level order---------------------------------------
void buildLevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter the data for root node: ";
    int rootdata;
    cin>>rootdata;
    root = new node(rootdata);
    q.push(root);

    while(!q.empty()){
        node*temp = q.front();
        q.pop();
        cout<<"Enter the data for leftside of "<<temp->data<<" : ";
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter the data for right side of "<<temp->data<<" : ";
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}
node* solve(node*root,int &k,int n){
    if(root == NULL){
        return NULL;
    }
    
    if(root->data == n){
        return root;
    }
    
    node* leftAns = solve(root->left,k,n);
    node* rightAns = solve(root->right,k,n);
    
    //wapis 
    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k <= 0){
            //to lock the answer
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k <= 0){
            //to lock the answer
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int main(){
    node*root = NULL;
    buildLevelOrder(root);   
    // 1 2 3 4 5 -1 -1 -1 -1 -1 -1

// Lowest Common Ancestor in a Binary Tree =====================================
    int k = 2;  // 2 4
    int n = 4;
    node*ans = solve(root,k,n); //1 2 3 4 5 -1 -1
    
    if(ans == NULL || ans->data == n){
        cout<<"-1"<< endl;
    }else{
        cout<<"answer is -> "<<ans->data<<endl;
    }

return 0;
}