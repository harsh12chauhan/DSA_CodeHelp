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
//function to insert the data into binary search tree ( BST ) ------------------------
node* insertIntoBST(node*root,int data){
    if( root == NULL){
        root = new node(data);
        return root;
    }

    if(data > root->data){
        root->right = insertIntoBST(root->right,data);
    }else{
        root->left = insertIntoBST(root->left,data);
    }

    return root;
}

//taking input and calling the BST function --------------------
void takeInput(node* &root){
    // int data[] = {10,6,12,2,8,11,15};
    int data[] = {8,5,9,1,6,7,2,4,3};

    int n = 9;
    for(int i = 0;i<n;i++){
        root = insertIntoBST(root,data[i]);
    }
}
// inorder traversal and storing data in vector ----------------------------
void inorderTraversal(node* root,vector<int> &inorderNodes){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left,inorderNodes);
    inorderNodes.push_back(root->data);
    inorderTraversal(root->right,inorderNodes);
}
// Convert BST to Min Heap--------------------------------------------------
void fillPreOrder(node*&root,vector<int> in,int index){
    if(root == NULL){
        return;
    }
    root->data = in[index++];
    fillPreOrder(root->left,in,index);
    fillPreOrder(root->right,in,index);
}
int main(){
    node*root = NULL;

// insertion in BST ==========================================
    takeInput(root); 

// Convert BST to Min Heap ==========================================
    // inorder -------
    vector<int> in;
    inorderTraversal(root,in);
    for(auto i:in){
        cout<<i<<" ";
    }cout<<endl;
    //BST to Min Heap ----------------
    fillPreOrder(root,in,0);
    cout<<" Min heap value -> "<<endl;
    levelOrderTraversal(root);

return 0;    
}