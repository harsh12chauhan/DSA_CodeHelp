#include<iostream>
#include<bits/stdc++.h>
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

// top view of the  tree -------------------------------------
 vector<int> topView(node *root)
    {
        map<int,int> m;
        queue<pair<node*,int> >q;
        
        vector<int> ans;
        
        if(root == NULL){
            return ans;
        }
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            
            pair<node*,int> temp =q.front();
            q.pop();
            
            node*frontNode = temp.first;
            int hd = temp.second;
            
            if(m.find(hd) == m.end()){
                m[hd] = frontNode->data;
            }
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,hd-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,hd+1));
            }
        }
        
        for(auto i:m){
            ans.push_back(i.second);
        }
        
        return ans;
    }
int main(){
    
    node*root = NULL;
    buildLevelOrder(root); //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

// top view of the  tree===================================
    vector<int> tp = topView(root);

    cout<<endl<<"top view of the tree is  -> "<<endl;
    for(int i = 0;i<tp.size();i++){
        cout<<tp[i]<<" ";
    }
    cout<<endl;
return 0;
}