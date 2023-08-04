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
// inorder traversal --------------------------------------------------------------
void inOrderTraversal(node*root){
    if(root == NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

// preorder traversal -------------------------------------------------------------
void preOrderTraversal(node*root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// postorder traversal ------------------------------------------------------------
void postOrderTraversal(node*root){
    if(root == NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}
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
// different types of traversal -------------------------------------------------
void diffTraversal(node*root){
    cout<<"level order traversal -> "<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"inorder traversal -> "<<endl;
    inOrderTraversal(root);
    cout<<endl;
    cout<<"preorder traversal -> "<<endl;
    preOrderTraversal(root);
    cout<<endl;
    cout<<"postorder traversal -> "<<endl;
    postOrderTraversal(root);
    cout<<endl;
    cout<<" traversal completed ======================="<<endl;
}

// search in a BST  (recursive solution) time = O(n) space = O(n)------------------------------
bool searchInBST(node *root, int x) {
    // Write your code here.
    if(root == NULL){
        return false;
    }
    
    if(x == root->data){
        return true;
    }

    if(x > root->data){
        return searchInBST(root->right, x);
    }else{
        return searchInBST(root->left, x);
    }
}

// search in a BST  (iterative solution) time = O(n) space = O(1)-----------------------------------
bool searchInBSTiterative(node *root, int x) {
    node* temp = root;
    while(temp != NULL){
        if(temp->data == x){
            return true;
        }
        if(temp->data < x){
            temp = temp->right;
        }else{
            temp = temp->left;
        }
    }
    return false;
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
    int data;
    cin>>data;
    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
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
// function to delete a target node ----------------------------------------------
node* deleteNodeInBST(node* root,int target){
    //base case
    if(root == NULL){
        return root ;
    }
    if(root->data == target){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 child
            //left child
            if(root->left != NULL && root->right == NULL){
                node*temp = root->left;
                delete root;
                return temp;
            }
            //right child
            if(root->left == NULL && root->right != NULL){
                node*temp = root->right;
                delete root;
                return temp;
            }
        // 2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minValueInBST(root->right)->data;
            root->data = mini;
            root->right = deleteNodeInBST(root->right,mini);
            return root;
        }
    }else if( root->data < target){
        root->right =  deleteNodeInBST(root->right,target);
    }else{
        root->left = deleteNodeInBST(root->left,target);
    }
}

int main(){
    node*root = NULL;

// insertion in BST ==========================================
    cout<<"Enter the data to insert in BST : "<<endl;
    takeInput(root);

// traversal of BST using level order traversal ===================
    // levelOrderTraversal(root);

// search an element in the BST ====================================
    // int x = 5;
    // // if(searchInBST(root,x)){             // recursive approach
    // if(searchInBSTiterative(root,x)){       // itrative approach
    //     cout<<"Element found !"<<endl;
    // }else{
    //     cout<<"Element not found."<<endl;
    // }

// min and max value in the BST =======================================

    // cout<<" Minimun value in the BST is -> "<<minValueInBST(root)->data<<endl;
    // cout<<" Maxiimun value in the BST is -> "<<maxValueInBST(root)->data<<endl;

// traversals ==============================================================
    cout<<"before deletion ------------"<<endl;
    diffTraversal(root);

//delete a element in BST ==============================================
    //50 20 70 10 30 90 110 -1
    root = deleteNodeInBST(root,50);

// traversals ==============================================================
    cout<<"after deletion ------------"<<endl;
    diffTraversal(root);



    return 0;
}