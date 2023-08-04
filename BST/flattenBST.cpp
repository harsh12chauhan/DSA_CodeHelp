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
   ~node() {
            if(left)
                delete left;
            if(right)
                delete right;
            
        cout<<" memory is free"<<endl;                
        }
};

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
    int data[] = {10,6,12,2,8,11,15};  // output 2 6 8 10 11 12 15 
    int n = 7;
    for(int i = 0;i<n;i++){
        root = insertIntoBST(root,data[i]);
    }
}
//===========================================================================================================================
// using inorder traversal  to store int in sorted way in vector ------------------------
void inordorTraversal(node*root,vector<int> &inorderNodes){

    if(root == NULL){
        return;
    }

    inordorTraversal(root->left,inorderNodes);
    inorderNodes.push_back(root->data);
    inordorTraversal(root->right,inorderNodes); 
}
// (as storing INTEGET'S in array ) function to flatten the tree into linked list ---------------------------
node* flatten(node* root)
{
    if(root == NULL){
        return NULL;
    }

    vector<int> inorderNodes;
    inordorTraversal(root,inorderNodes);
    node* newRoot = new node(inorderNodes[0]);
    node* crr = newRoot;
    int n = inorderNodes.size();
    for(int i = 1;i<n;i++){
       node* temp = new node(inorderNodes[i]);
        crr->left = NULL;
        crr->right = temp;
        crr = temp;
    }
    return newRoot;
}
/*=================================================================================================================
// using inorder traversal  to store node in sorted way in vector ------------------------
void inordorTraversal(node*root,vector<node*> &inorderNodes){

    if(root == NULL){
        return;
    }

    inordorTraversal(root->left,inorderNodes);
    inorderNodes.push_back(root);
    inordorTraversal(root->right,inorderNodes);
}
// (as storing NODE'S in array ) function to flatten the tree into linked list ---------------------------
node* flatten(node* root)
{
    if(root == NULL){
        return NULL;
    }
    vector<node*> inorderNodes;
    inordorTraversal(root,inorderNodes);
    int n = inorderNodes.size();
    for(int i = 0;i<n-1;i++){
        inorderNodes[i]->left = NULL;
        inorderNodes[i]->right = inorderNodes[i+1];
    }
    inorderNodes[n-1]->right = NULL;
    inorderNodes[n-1]->left = NULL;
    return inorderNodes[0];
}
=================================================================================================================
*/

int main(){
    node*root = NULL;

// insertion in BST ==========================================
    takeInput(root);
    
// find Two node in BST whose sum is equal to target =========
    node*temp = flatten(root);
    cout<<" tree flatten into linked list -> "<<endl;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp ->right;
    }
    cout<<endl;
return 0;    
}