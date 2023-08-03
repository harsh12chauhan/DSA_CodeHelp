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
// Maximum sum of Non-adjacent nodes-----------------------------------------
 pair<int,int> maxSumOfNonAdjacentNodes(node*root){
        if(root == NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = maxSumOfNonAdjacentNodes(root->left);
        pair<int,int> right = maxSumOfNonAdjacentNodes(root->right);
        
        pair<int,int> res;
        
        res.first = root->data + left.second + right.second;
        res.second = max(left.first,left.second) + max(right.first,right.second);
        
        return res;
    }
int main(){
    node*root = NULL;
    buildLevelOrder(root);   
    // 1 2 3 -1 -1 4 6 -1 5 -1 -1 7 -1

// // Maximum sum of Non-adjacent nodes =====================================
    pair<int,int> ans = maxSumOfNonAdjacentNodes(root); 
    int val = max(ans.first,ans.second);

    cout<<"Maximum sum of Non-adjacent nodes are -> "<<val<<endl;

return 0;
}