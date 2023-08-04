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
    int data[] = {10,6,12,2,8,11,15};
    int n = 7;
    for(int i = 0;i<n;i++){
        root = insertIntoBST(root,data[i]);
    }
}
//
void inorderTraversal(node* root,vector<int> &inorder){
    if(root == NULL){
        return;
    }

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}
//function to find Two node in BST whose sum is equal to target --------------------------
bool twoSumInBST(node* root, int target) {
	vector<int> inorder;
    inorderTraversal(root,inorder);
    int i = 0;
    int j = inorder.size()-1;
    while(i<j){
        int sum = inorder[i] + inorder[j];
        if (sum == target) {
          return true;
        }else if (sum > target){
            j--;
        }else{
            i++;
        }
    }
    return false;
}
int main(){
    node*root = NULL;

// insertion in BST ==========================================
    takeInput(root);
    
// find Two node in BST whose sum is equal to target =========
    int target = 14;
    if(twoSumInBST(root,target)){
        cout<<"Yes!  a pair exist's in BST "<<endl;
    }else{
        cout<<"No ! no such pair exist's in BST "<<endl;
    }
return 0;    
}