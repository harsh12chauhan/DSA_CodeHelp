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
int main(){
// Construct Tree from Inorder & Preorder ==================================================
    int preIndex = 0;
    int in[] = {1 ,6, 8, 7};
    int pre[] ={1 ,6 ,7 ,8};
    int n =4 ;
    node* ans = solve(in,pre,preIndex,0,n-1,n);
    postOrderTraversal(ans);
return 0;
}