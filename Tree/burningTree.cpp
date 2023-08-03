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
//Burning Tree ---------------------------------------------------------------------------------------------------------------
// function for creating mapping of child node to parent node and also finding target node -----------------------
node* createMapping(node*root,int target,map<node*,node*>&nodeToParent){
    
    node* res = NULL;
    queue<node*> q;
    
    q.push(root);
    nodeToParent[root] = NULL;
    
    while(!q.empty()){
        node* front = q.front();
        q.pop();
        if(front->data == target){
            res = front;
        }
        if(front->left){
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if(front->right){
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}
//function to burn the tree ----------------------------------------
int burnTree(node*target,map<node*,node*> nodeToParent){
    map<node*,bool> visited;
    queue<node*>q;
    
    q.push(target);
    visited[target] = true;
    
    int ans = 0;
    
    while(!q.empty()){
        
        bool flag = 0;
        int size = q.size();
        
        for(int i = 0;i<size;i++){

            node* fornt = q.front();
            q.pop();
            
            if(fornt->left && !visited[fornt->left]){
                flag = 1;
                q.push(fornt->left);
                visited[fornt->left] = 1;
            }
            if(fornt->right && !visited[fornt->right]){
                flag = 1;
                q.push(fornt->right);
                visited[fornt->right] = 1;
            }
            if(nodeToParent[fornt] && !visited[nodeToParent[fornt]]){
                flag = 1;
                q.push(nodeToParent[fornt]);
                visited[nodeToParent[fornt]] = 1;
            }
        }
        if(flag == 1){
            ans++;
        }
    }
    return ans;
}
int main(){

    node*root = NULL;
    buildLevelOrder(root);
    // 1 2 3 4 5 -1 6 -1 -1 7 8 -1 9 10 11 -1 -1 -1 12 -1 -1 -1 13 -1 -1 -1 -1

// Burning Tree =============================================================
    int target = 8;
    map<node*,node*> nodeToParent;
    node* targetNode = createMapping(root,target,nodeToParent);
    int ans = burnTree(targetNode,nodeToParent);
    cout<<endl<<"total time required to burn tree is ->"<<ans<<endl;

return 0;
}