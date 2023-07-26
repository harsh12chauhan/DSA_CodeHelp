#include <iostream>
#include <map>
using namespace std;

class Node{
    public:
        int data;
        Node*next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        if(this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"Memory is free :-> "<<value<<endl;
    }
};

void insertion(Node* &tail,int data,int element){
    if(tail == NULL){
        Node*node = new Node(data);
        tail = node;
        node->next = node;
    }else{
        Node*crr = tail;
        while(crr->data != element){
            crr = crr->next;
        }

        Node*node = new Node(data);
        node->next = crr->next;
        crr->next = node;
    }
}

void traverse(Node* tail){
    Node*temp = tail;

    if(tail == NULL){
        cout<<"list is empty "<<endl;
        return ;
        cout<<"Adfsag"<<endl;
    }
    do{
        cout<<tail->data<<" -> ";
        tail = tail->next;
    }while(tail != temp);
    cout<<" firstnode "<<endl;;
}

void deletion(Node* &tail,int element){

    if(tail == NULL){
        cout<<"list is empty "<<endl;
        return;
    }
    else{

        //assuming the value is present in linkedlist
        Node*pre = tail;
        Node*crr = pre->next;

        bool ispresent = false;
        while (crr->data != element && crr != tail )
        {
            pre = crr;
            crr = crr->next;
        }

        pre->next = crr ->next;

        // 1 node deleteion
        if(crr == pre){
            tail = NULL;
        }

        // >=2 node deletion
        else if(tail == crr){
            tail = pre;
        }
            
        crr->next = NULL;
        delete crr; 
    }
}

bool isCircular(Node*tail){
    if(tail == NULL){
        return true;
    }
    Node*temp = tail->next;
    while(temp != tail && temp != NULL ){
        temp = temp->next;
    }

    if(temp == tail){
        return true;
    }
    return false;
}

bool detectLoop(Node*tail){
    if(tail == NULL){
        return false;
    }
    map<Node*,bool> visited;
    Node*temp = tail;
    while(temp != NULL){
        if(visited[temp] == true){
            cout<<"loop is  present at --> "<<temp->data<<endl;
            return true;
        }
        visited[temp] = true;
        temp =temp->next;
    }
    cout<<"loop is not present "<<endl;
    return false;
}

Node* floydDetection(Node*head){
    if(head == NULL){
        return NULL;
    }
    Node*slow = head;
    Node*fast = head;

    while(slow != NULL && fast!= NULL){
        fast = fast->next;
        if(fast != NULL){
            fast =  fast->next;
        }

        slow = slow->next;
        if(slow == fast){
            cout<<" loop is present at : >" <<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}

int main(){
    Node* tail = NULL;
    traverse(tail);

    insertion(tail,3,0);
    traverse(tail);

    insertion(tail,6,3);
    traverse(tail);

    insertion(tail,5,3);
    traverse(tail);

    insertion(tail,8,6);
    traverse(tail);

    // deletion(tail,5);
    // traverse(tail);
    // cout<<"tail -> "<<tail->data<<endl;

    // if(isCircular(tail)){
    //         cout<<"this is a circular linked list"<<endl;
    // }else{
    //         cout<<" this is not a circular linked list"<<endl;
    // }

    detectLoop(tail);
    traverse(tail);

return 0;
}