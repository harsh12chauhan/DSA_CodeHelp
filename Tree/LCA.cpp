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
//Lowest Common Ancestor in a Binary Tree -----------------------------------------------------------
node* lca(node* root ,int n1 ,int n2 )
{
    if(root == NULL){
       return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    
    node* leftAns = lca(root->left,n1,n2);
    node* rightAns = lca(root->right,n1,n2);
    
    if(rightAns != NULL && leftAns != NULL){
        return root;
    }else if(leftAns != NULL && right == NULL){
        return leftAns;
    }else if(rightAns != NULL && leftAns == NULL){
        return rightAns;
    }else{
        return NULL;
    }
}
int main(){
    node*root = NULL;
    buildLevelOrder(root);
    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    //4 2 5 7 1 2 3 -1 -1 6 -1 -1 -1 -1 -1 -1 -1
    // 5 2 -1 3 4 -1 -1 -1 -1 

// Lowest Common Ancestor in a Binary Tree =====================================
    node* lcaNode = lca(root,3,4);  //(3 ,4)
    cout<< "the node value of lca is -> "<<lcaNode->data<<endl;
return 0;
}