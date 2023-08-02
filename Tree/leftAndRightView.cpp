#include<iostream>
#include<bits/stdc++.h>
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
//function for left view of the tree-------------------------------------
void leftView(node*root,vector<int> &ans,int level){
    //base case
    if(root == NULL){
        return;
    }
    
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    
    leftView(root->left,ans,level+1);
    leftView(root->right,ans,level+1);
}

//function for right view of the tree-------------------------------------
void rightView(node*root,vector<int> &ans,int level){
    //base case
    if(root == NULL){
        return;
    }
    
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    
    rightView(root->right,ans,level+1);
    rightView(root->left,ans,level+1);
}
int main(){
    
    node*root = NULL;
    buildLevelOrder(root); //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

// left view of the  tree ===================================
    // vector<int> ans;
    // leftView(root,ans,0);

    // cout<<endl<<"left view of the tree is  -> "<<endl;
    // for(int i = 0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;

// left view of the tree ===================================
    vector<int> ans;
    rightView(root,ans,0);

    cout<<endl<<"left view of the tree is  -> "<<endl;
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

return 0;
}