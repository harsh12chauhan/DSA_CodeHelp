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
    int data[] = {4,1,5,2,6,2,8,3,20,98};
    int n =10;
    for(int i = 0;i<n;i++){
        root = insertIntoBST(root,data[i]);
    }
}

// function to check if a BST is valid BST ---------------------------------
bool isValidBST(node*root,int min,int max){
    if(root == NULL){
        return true;
    }

    if(root->data >= min && root->data <= max){
        bool left  = isValidBST(root->left, min, root->data);
        bool right  = isValidBST(root->right, root->data, max);
        return left && right;
    }else{
        return false;
    }
}

int main(){
    node*root = NULL;

// insertion in BST ==========================================
    cout<<"Enter the data to insert in BST : "<<endl;
    takeInput(root);

// check if a BST is valid BST ================================ 
    if(isValidBST(root,INT16_MIN,INT16_MAX)){
        cout<<"Valid BST "<<endl;
    }else{
        cout<<"not a Valid BST "<<endl;
    }

return 0;    
}