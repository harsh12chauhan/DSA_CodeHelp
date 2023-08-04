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
    int data[] = {  59 ,104 ,120 ,158, 165 ,190  ,193, 199  ,200 };

    int n = 9;
    for(int i = 0;i<n;i++){
        root = insertIntoBST(root,data[i]);
    }
}
// ====================================================================================================
// inorder traversal and storing data in vector ----------------------------
void inorderTraversal(node* root,vector<int> &inorderNodes){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left,inorderNodes);
    inorderNodes.push_back(root->data);
    inorderTraversal(root->right,inorderNodes);
}
// function to create BST from inorder ---------------------------------
node* InorderToBST(int s,int e,vector<int>&inorderNodes){
    if(s>e){
        return NULL;
    }
     int mid = s+(e-s)/2;

     node* root = new node(inorderNodes[mid]);
    root->left = InorderToBST(s,mid-1,inorderNodes);
    root->right = InorderToBST(mid+1,e,inorderNodes);

    return root;
}
//function for Normal BST To Balanced BST-------------------------------
node* balancedBst(node* root) {
    
    if(root == NULL){
        return NULL;
    }

    vector<int> inorderNodes;
    inorderTraversal(root,inorderNodes);

   return InorderToBST(0,inorderNodes.size()-1,inorderNodes);
}
// ===================================================================================================

int main(){
    node*root = NULL;

// insertion in BST ==========================================
    takeInput(root);

    levelOrderTraversal(root);
    cout<<"===================================="<<endl;

// Normal BST To Balanced BST =========
    balancedBst(root);

    levelOrderTraversal(root);

return 0;    
}