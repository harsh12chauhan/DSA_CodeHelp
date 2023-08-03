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
// postorder traversal ------------------------------------------------------------
void postOrderTraversal(node*root){
    if(root == NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

// Construct Tree from Inorder & Preorder -------------------------------------------------
int findPostion(int in[],int start,int end,int element,int n){
    for(int i = start;i<=end;i++){
        if(in[i] == element){
            return i;
        }
    }
    return -1;
}
// normal apporach-------------------
node* solve(int in[],int pre[],int &index ,int start,int end,int n){
   // base case
    if((index >= n) || (start > end)){
        return NULL;
    }
    
    int element =  pre[index++];
    node* root = new node(element);
    int position = findPostion(in,start,end,element,n);
    
    //recursive calls
    root->left = solve(in,pre,index,start,position-1,n);
    root->right = solve(in,pre,index,position+1,end,n);
    
    return root;
}

// optimized apporach-------------------
// node* solve(int in[],int pre[],int &index ,int start,int end,int n,map<int,int> &nodeToIndex){
//    // base case
//     if((index >= n) || (start > end)){
//         return NULL;
//     }
    
//     int element =  pre[index++];
//     node* root = new node(element);
//     int position = nodeToIndex[element];
    
//     //recursive calls
//     root->left = solve(in,pre,index,start,position-1,n,nodeToIndex);
//     root->right = solve(in,pre,index,position+1,end,n,nodeToIndex);
    
//     return root;
// }
int main(){
// Construct Tree from Inorder & Preorder ==================================================
    int preIndex = 0;
    int in[] = {1 ,6, 8, 7};
    int pre[] ={1 ,6 ,7 ,8};
    int n =4 ;
    node* ans = solve(in,pre,preIndex,0,n-1,n);
    postOrderTraversal(ans);

//optimize apporach================================================
    // int preIndex = 0;
    // int in[] = {1 ,6, 8, 7};
    // int pre[] ={1 ,6 ,7 ,8};
    // int n =4 ;

    //wrong answer
    // int in[] = {7 ,3 ,11, 1 ,17, 3, 18};
    // int pre[] ={1 ,3 ,7 ,11 ,3 ,17, 18};
    // int n =7;
    

    //creating mapping of elements and their index
    // map<int,int> nodeToIndex;

    //     for(int i = 0;i<n;i++){  
    //         nodeToIndex[in[i]] = i;
    //     }
    // //function call 
    // node* ans = solve(in,pre,preIndex,0,n-1,n,nodeToIndex);
    // postOrderTraversal(ans);
return 0;
}