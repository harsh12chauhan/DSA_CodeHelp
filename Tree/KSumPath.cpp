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
//K Sum Paths----------------------------------------------------
 void solve(node*root,int k,int &count, vector<int> path){
      if(root == NULL){
            return ;
        }
        
        path.push_back(root->data);
        
        solve(root->left,k,count,path);
        solve(root->right,k,count,path);
        
        // checking the sum of the array  = k;
        int sum = 0;
        int size = path.size();
        for(int i = size-1;i>=0;i--){
            sum += path[i];
            if(sum == k){
                count++;
            }
        }
        path.pop_back();
  }

int main(){
    node*root = NULL;
    buildLevelOrder(root);
    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    //4 2 5 7 1 2 3 -1 -1 6 -1 -1 -1 -1 -1 -1 -1
    // 5 2 -1 3 4 -1 -1 -1 -1 
// ============ THIS CODE IS NOT WORKING ======================
// K Sum Paths =====================================
        int count = 0;
        int k = 5;
        vector<int> path;
        solve(root,k,count,path);
    cout<< "number of paths in the tree which have their sum equal to K are -> "<<count<<endl;
return 0;
}