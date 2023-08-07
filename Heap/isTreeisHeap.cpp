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
int countNodes( node*root){
    if(root == NULL){
        return 0;
    }
    
    return 1+ countNodes(root->left) + countNodes(root->right);
}
bool isCBT( node*root,int index,int cnt){
    if(root == NULL){
        return true;
    }
    if(index >= cnt){
        return false;
    }
    else{
        bool left = isCBT(root->left,2*index+1,cnt);
        bool right = isCBT(root->right,2*index+2,cnt);
        return (left&&right);
    }
}
bool isMaxOrder( node*root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    if(root->right == NULL){
        return (root->data > root->left->data);
    }
    else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);
        
        return (left && right &&(root->data > root->left->data &&root->data > root->right->data));
    }
}
 bool isHeap( node* tree) {
    int index = 0;
    int totalCount = countNodes(tree);
    if(isCBT(tree,index,totalCount) && isMaxOrder(tree)){
        return true;
    }else{
        return false;
    }
}
int main(){
    node*root = NULL;
    buildLevelOrder(root); // 10 20 30 40 60 -1 -1
    //1 2 3 -1 -1 4 6 -1 5 -1 -1 7 -1 -1 -1
    if(isHeap(root)){
        cout<<" yes !"<<endl;
    }else{
        cout<<"no"<<endl;
    }


return 0;
}