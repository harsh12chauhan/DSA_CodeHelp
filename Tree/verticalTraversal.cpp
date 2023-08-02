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
// vertial traversal in tree --------------------------------------
vector<int> verticalTraversal(node *root)
{
    map<int, map<int, vector<int> > > mapsNode;
    queue<pair<node*,pair<int,int> > > q;
    
    vector<int> ans;
    
    if(root == NULL ){
        return ans;
    }
    
    q.push(make_pair(root,make_pair(0,0)));
    
    while(!q.empty()){
        
        pair<node*,pair<int,int> > temp = q.front();
        q.pop();
        node*frontnode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;
        
        mapsNode[hd][lvl].push_back(frontnode->data);
        
        if(frontnode->left){
            q.push(make_pair(frontnode->left,make_pair(hd-1,lvl+1)));
        }
        if(frontnode->right){
            q.push(make_pair(frontnode->right,make_pair(hd+1,lvl+1)));
        }
    }
    for(auto i:mapsNode){
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main(){
    
    node*root = NULL;
    buildLevelOrder(root); //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

// vertial traversal in tree===================================
    vector<int> v = verticalTraversal(root);

    cout<<endl<<"vertical traversal -> "<<endl;
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;


return 0;
}