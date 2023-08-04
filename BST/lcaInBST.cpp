#include <iostream>
#include <queue>
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
    int data[] = {2 ,1 ,3 ,5};
    int n =4;
    for(int i = 0;i<n;i++){
        root = insertIntoBST(root,data[i]);
    }
}

// ( recursive approach )funciton to find the LCA lowest common ancestor of 2 nodes ------------------
node*LCAinaBSTRecursive(node*root, int P, int Q)
{
    // base case
    if(root == NULL){
        return NULL;
    }
    if(root->data > P && root->data > Q){
        return LCAinaBSTRecursive(root->left,P,Q);
    }
    if(root->data < P && root->data < Q){
        return LCAinaBSTRecursive(root->right,P,Q);
    }
    return root;
       
}
// ( iterative approach )funciton to find the LCA lowest common ancestor of 2 nodes ------------------
node*LCAinaBST(node*root, int P, int Q)
{
    while(root != NULL){
        if(root->data > P && root->data > Q){
            root = root->left;
        }
        else if(root->data < P && root->data < Q){
            root = root->right;
        }else{
             return root;
        }
    }
}

int main(){
    node*root = NULL;

// insertion in BST ==========================================
    cout<<"Enter the data to insert in BST : "<<endl;
    takeInput(root);

// find the LCA lowest common ancestor of 2 nodes=============
    int n1 = 3;
    int n2 = 5;
    node * ans = LCAinaBST(root,n1,n2);
    node * ansRecursive = LCAinaBSTRecursive(root,n1,n2);
    cout<<"LCA of "<<n1<<" and "<<n2<<" is "<<ans->data<<endl;
    cout<<"LCA (Recursive) of "<<n1<<" and "<<n2<<" is "<<ansRecursive->data<<endl;


return 0;    
}