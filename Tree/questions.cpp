#include <iostream>
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

//creation of tree--------------------------------------
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

// height of tree --------------------------------------
int height(node* root){
    if(root == NULL){
        return 0;
    }
    
    int left = height(root->left);
    int right = height(root->right);
    
    int ans = max(left,right) + 1;
    return ans;
}
// longest diameter in the tree O(n^2) time ------------------------------
int diameter(node* root) {        
    if(root == NULL){
        return 0;
    }
    
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right) + 1;
    
    int ans = max(op1, max(op2,op3));
    return ans;
}

// longest diameter in the tree  O(n) time ------------------------------
pair<int,int> diameterFast(node*root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    
    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);
    
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
    
    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second,right.second)+1;
    
    return ans;
}
// is balance or not ----------------------------------------------------
pair<bool,int> isBalancedFast(node*root){
        if(root == NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        pair<bool,int> left = isBalancedFast(root->left);
        pair<bool,int> right = isBalancedFast(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = abs(left.second - right.second) <= 1;
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if(leftAns && rightAns && diff){
            ans.first = true;
        }else{
            ans.first = false;
        }
        return ans;
    }
int main(){
    node*root = NULL;
    root = buildTree(root); // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
//height of tree ==================================================
    // int h = height(root);
    // cout<<endl;
    // cout<<"maximum height is "<<h<<endl;

// longest diameter in the tree ===================================
    // int d = diameter(root); // O(n^2) time complexity
    // int d = diameterFast(root).first;  // O(n) time complexity
    // cout<<"longest Diameter is : "<<d<<endl;

// is balance or not===============================================
    if(isBalancedFast(root).first){
        cout<<"Balanced tree "<<endl;
    }else{
        cout<<"Not a Blanced tree"<<endl;
    }
return 0;
}