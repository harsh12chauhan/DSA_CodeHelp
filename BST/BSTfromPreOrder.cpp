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
        this->left =NULL;
        this->right = NULL;
    }
    ~node(){
            if(left)
                delete left;
            if(right)
                delete right;
            
            cout<<" memory is free"<<endl;
    }
};
// function for level order traversal of binary tree ---------------------------------
void levelOrderTraversal(node*root){
    if(root == NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node*temp = q.front();
        q.pop();

        if(temp == NULL){ //purana level complete ho chuka hai 
            cout<<endl;
            if(!q.empty()){ // queue still have child nodes
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" "; 
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
// function to  create the BST from preorder data array -------------------------------
node *createPreorder(int mini,int maxi,int &i,vector<int> &preOrder){
    if(i>=preOrder.size()){
        return NULL;
    }
    if(preOrder[i]< mini || preOrder[i] > maxi){
        return NULL;
    }

    node*root = new node(preOrder[i++]);

    root->left = createPreorder(mini,root->data,i,preOrder);
    root->right = createPreorder(root->data,maxi,i,preOrder);

    return root;
}
//---------------------------------------------------
node *preOrderTree(vector<int> &preOrder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i =0;
    return createPreorder(mini,maxi,i,preOrder);
}

int main(){
    node*root = NULL;
// create the BST from preorder data array============================
    vector<int> pre = {8 ,5 ,1 ,7 ,10 ,12};
    root = preOrderTree(pre);

// level order traversal ===============================================
    levelOrderTraversal(root);

return 0;    
}