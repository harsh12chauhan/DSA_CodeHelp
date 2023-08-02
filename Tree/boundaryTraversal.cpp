// Boundary Traversal of binary tree
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

//Boundary Traversal of binary tree ---------------------------------------
//traverse left nodes ------------
void traverseLeft(node*root,vector<int> &ans){
    if((root == NULL) || (root->right == NULL && root->left == NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        traverseLeft(root->left,ans);
    }else{
        traverseLeft(root->right,ans);
    }
}   
//traverse leaf nodes ------------
void traverseLeaf(node* root ,vector<int> &ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
}    
//traverse right nodes ------------
void traverseRight(node*root,vector<int> &ans){
    if((root == NULL) || (root->right == NULL && root->left == NULL)){
        return;
    }
    if(root->right){
        traverseRight(root->right,ans);
    }else{
        traverseRight(root->left,ans);
    }
    ans.push_back(root->data);
}
// function for boundary traversal of tree -----------
vector <int> boundaryTraversal(node *root)
{
    vector<int> ans;
    ans.push_back(root->data);
    //traverse left
    traverseLeft(root->left,ans);
    //traverse leafs of left sub-tree
    traverseLeaf(root->left,ans);
    //traverse leafs of right sub-tree
    traverseLeaf(root->right,ans);
    //traverseRight
    traverseRight(root->right,ans);
    return ans;
}

int main(){
    node*root = NULL;
    buildLevelOrder(root);//1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    vector<int> boundary = boundaryTraversal(root);
    cout<<endl<<"boundary traversal -> "<<endl;
    for(int i = 0;i<boundary.size();i++){
        cout<<boundary[i]<<" ";
    }
    cout<<endl;

return 0;
}