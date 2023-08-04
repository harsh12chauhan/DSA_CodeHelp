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
    int data[] = {6521171 ,5650934 ,9278816 ,899375,8989449};
    // int data[] = {15 ,10 ,20 ,8 ,12 ,16 ,25};
    int n = 5;
    for(int i = 0;i<n;i++){
        root = insertIntoBST(root,data[i]);
    }
}
// search in a BST  (iterative solution) time = O(n) space = O(1)-----------------------------------
node* searchInBSTiterative(node *root, int x) {
    node* temp = root;
    while(temp != NULL){
        if(temp->data == x){
            return temp;
        }
        if(temp->data < x){
            temp = temp->right;
        }else{
            temp = temp->left;
        }
    }
    return NULL;
}

// function to get the node with minimum value in the BST ---------------------
node* minValueInBST(node*root){
    node*temp = root;
    while(temp ->left != NULL){
        temp = temp->left;
    }
    return temp;
}

// function to get the node with maximum value in the BST ---------------------
node* maxValueInBST(node*root){
    node*temp = root;
    while(temp ->right != NULL){
        temp = temp->right;
    }
    return temp;
}
//function to get predecessor and successor of the target node ------------------------
pair<int,int> PredSuccBST(node*root,int key){
    //find the key node
    node*keyNode = searchInBSTiterative(root,key);
    if(keyNode == NULL){
        return {-1,-1};
    }

    int succ = minValueInBST(keyNode->right)->data;
    int pred = maxValueInBST(keyNode->left)->data;
    return {pred,succ};
}

int main(){ 
    node*root = NULL;
// ERROR AA RA THA ISME KUCH CODING NINJAS PLATFORM PE JAB KIYA THA YE QUESTION 
// insertion in BST ==========================================
    cout<<"Enter the data to insert in BST : "<<endl;
    takeInput(root);
    int data = 9615950;
    pair<int,int> p = PredSuccBST(root,data);
    cout<<"The Predecessor of "<<data<<" is -> "<<p.first<<endl;
    cout<<"The Successor of "<<data<<" is -> "<<p.second<<endl;

return 0;    
}