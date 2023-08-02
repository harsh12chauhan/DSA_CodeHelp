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

// zig zag traversal -----------------------------------
vector <int> zigZagTraversal(node* root)
{
  	vector<int> result;
  	if(root == NULL){
  	    return result;
  	}
  	queue<node*> q;
  	q.push(root);
  	bool leftToRight = true;    	
  	while(!q.empty()){
  	    int size = q.size();
  	    vector<int> ans(size);    	        	    
  	    //level processing
  	    for(int i = 0;i<size;i++){
  	        node*temp = q.front();
  	        q.pop();    	        
  	        //normal insert or reverse insert
  	        int index = leftToRight ? i : size - i - 1;
  	        ans[index] = temp->data;
  	        if(temp->left){
  	            q.push(temp->left);
  	        }
  	        if(temp->right){
  	            q.push(temp->right);
  	        }
  	    } 
  	    //direction change 
  	    leftToRight = !leftToRight;    	
  	    for(auto i:ans){
  	        result.push_back(i);
  	    }    	    
  	}
  	return result;
}

int main(){
    node*root = NULL;
    buildLevelOrder(root);//1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
// zig zag traversal =====================================
    vector<int> zigi = zigZagTraversal(root);
    cout<<endl<<"zig zag traversal -> "<<endl;
    for(int i = 0;i<zigi.size();i++){
        cout<<zigi[i]<<" ";
    }
    cout<<endl;

return 0;
}