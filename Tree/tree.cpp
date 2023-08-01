//binary tree
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
        this->left = NULL;
        this->right = NULL;
    }
};
//function for creating the binary tree
node*buildTree(node*root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data in right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}
// function for level order traversal of binary tree 
void levelOrderTraversal(node*root){
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
int main(){

    node*root = NULL;
    
//creation of tree
    root = buildTree(root); //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

// level order traversal of binary tree 
    levelOrderTraversal(root);
return 0;
}