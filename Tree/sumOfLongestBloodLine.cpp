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
// Sum of the Longest Bloodline of a Tree ------------------------------------------
void sumOfLongRootToLeafPath(node*root,int sum,int &maxSum , int len ,int &maxLen){
    //base case
    if(root == NULL){
        if(len > maxLen){
            maxLen = len;
            maxSum = sum;
        }else if(len == maxLen){
            sum = max(sum,maxSum);
        }
        return;
    }

    sum = sum + root->data;
    sumOfLongRootToLeafPath(root->left,sum,maxSum,len + 1,maxLen);
    sumOfLongRootToLeafPath(root->right,sum,maxSum,len + 1,maxLen);
}

int main(){
    node*root = NULL;
    buildLevelOrder(root);
    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    //4 2 5 7 1 2 3 -1 -1 6 -1 -1 -1 -1 -1 -1 -1

// Sum of the Longest Bloodline of a Tree =====================================
    int sum = 0;
    int maxSum = 0;
    int len = 0;
    int maxLen = 0;
    sumOfLongRootToLeafPath(root,sum,maxSum,len,maxLen);
    cout<<endl<<"sum of longest bloodline is  -> "<<maxSum<<endl;
return 0;
}