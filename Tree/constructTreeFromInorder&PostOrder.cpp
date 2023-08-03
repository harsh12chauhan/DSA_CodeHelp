
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
        this->left = NULL;
        this->right = NULL;
    }
    ~node(){
            delete left,right;
        cout<<"memory is free"<<endl;;
    }
};
// preorder traversal -------------------------------------------------------------
void preOrderTraversal(node*root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
// Construct Tree from Inorder & Postorder -----------------------------------
//  int findPostion(int in[],int start,int end,int element,int n){
//     for(int i = start;i<=end;i++){
//         if(in[i] == element){
//             return i;
//         }
//     }
//     return -1;
// }
// normal approach ------------------------------
// node* solve(int in[],int post[],int &index ,int start,int end,int n){
//     // base case
//     if((index < 0) || (start > end)){
//        return NULL;
//     }
        
//     int element =  post[index--];
//     node* root = new node(element);
//     int position = findPostion(in,start,end,element,n);

//     //recursive calls in case of post order first build right tree
//     root->right = solve(in,post,index,position+1,end,n);
//     root->left = solve(in,post,index,start,position-1,n);
        
//     return root;
// }

// optimized apporach for Construct Tree from Inorder & Preorder -----------------------------
node* solve(int in[],int post[],int &index ,int start,int end,int n,map<int,int> &nodeToIndex){
   // base case
    if((index >= n) || (start > end)){
        return NULL;
    }
    
    int element =  post[index--];
    node* root = new node(element);
    int position = nodeToIndex[element];
    
    //recursive calls
    root->right = solve(in,post,index,position+1,end,n,nodeToIndex);
    root->left = solve(in,post,index,start,position-1,n,nodeToIndex);
    
    return root;
}
int main(){
// Construct Tree from Inorder & Postorder ==================================================
    // int in[] =  {4 ,8 ,2 ,5 ,1 ,6 ,3 ,7};
    // int post[] ={8 ,4 ,5 ,2 ,6 ,7 ,3 ,1};
    // int n =8;
    // int postIndex = n-1;
    // node* ans = solve(in,post,postIndex,0,n-1,n);
    // preOrderTraversal(ans);
    
    // output ->  1 2 4 8 5 3 6 7

//optimize apporach================================================
   
    int in[] =  {4 ,8 ,2 ,5 ,1 ,6 ,3 ,7};
    int post[] ={8 ,4 ,5 ,2 ,6 ,7 ,3 ,1};
    int n =8;
    int postIndex = n-1;
    

    // creating mapping of elements and their index
    map<int,int> nodeToIndex;

        for(int i = 0;i<n;i++){  
            nodeToIndex[in[i]] = i;
        }
    //function call 
    node* ans = solve(in,post,postIndex,0,n-1,n,nodeToIndex);
    preOrderTraversal(ans);

return 0;
}