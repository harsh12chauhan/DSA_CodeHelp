// Morris Traversal of binary tree
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

//Morris Traversal of binary tree ---------------------------------------
//-- question -- Flatten binary tree to linked list--
void flatten(node *root)
    {
        node*crr = root;
        while(crr != NULL){
            if(crr->left != NULL){
                node*pred = crr->left;
                while(pred->right != NULL){
                    pred = pred->right;
                }
                pred->right = crr->right;
                crr->right = crr->left;
                crr->left = NULL;
            }
            crr =  crr->right;
        }
    }


int main(){
    node*root = NULL;
    buildLevelOrder(root);
    // 1 2 5 3 4 -1 6 -1 -1 -1 -1 -1 -1
    //output -> 1 2 3 4 5 6

    flatten(root); //preorder pattern 
    
    node*temp = root;
    cout<<" tree flatten into linked list -> "<<endl;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp ->right;
    }
    cout<<endl;
return 0;
}