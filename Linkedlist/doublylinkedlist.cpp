#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node(){
        int value = this->data;
        if(this->next!= NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory is free for the node with value -> "<<value<<endl;

    }
};
//print doubly linkedlist==================================================
void print(Node* head){
    Node*ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    }cout<<" NULL"<<endl;
}
// length of doubly linked list===========================================
int getLength(Node* head){
    Node*ptr = head;
    int len = 0;
    while(ptr != NULL){
        len++;
        ptr = ptr->next;
    }
    return len;
}
//insert at head=====================================================
void insertATHead(Node* &head,Node* &tail,int data){

    if(head == NULL){
        Node*node = new Node(data);
        head = node;
        tail = node;
    }else{
        Node*node = new Node(data);
        node->next = head;
        head->prev = node;
        head = node;
    }
}
//insert at tail======================================================
void insertAtTail(Node* &tail,Node* &head,int data){
     if(tail == NULL){
        Node*node = new Node(data);
        tail = node;
        head = node;
    }else{
    Node*node = new Node(data);
    tail->next = node;
    node->prev = tail;
    tail = node;
    }
}
//insert at position ================================================
void insertAtPosition(Node* &head,Node* &tail,int position,int data){
    //at head
    if(position == 1){
        insertATHead(head,tail,data);
        return ;
    }

    Node*ptr = head;
    int cnt = 1;
    while(cnt < position-1)
    {
        ptr=ptr->next;
        cnt++;
    }

    //at end
    if(ptr->next == NULL){
        insertAtTail(tail,head,data);
        return;
    }

    //at middle
    Node*node = new Node(data);
    node->next = ptr->next;
    ptr->next->prev = node;
    ptr->next = node;
    node->prev = ptr;
}

//deletion =======================================================
void deletionAtPosition(Node*&head,Node*&tail, int position){

    if(position == 1){
        Node*ptr = head;
        ptr->next->prev = NULL;
        head = ptr->next;

        ptr->next =NULL;
        delete ptr;
    }else{
        Node*crr = head;
        Node*pre = NULL;
        int cnt =1;
        while (cnt < position)
        {
            pre=crr;
            crr= crr->next;
            cnt++;
        }

        if(crr->next == NULL){
            crr->prev = NULL;
            pre->next = NULL;
            crr->next = NULL;
            tail = pre;
            delete crr;
        }else{
        pre->next = crr->next;
        crr->next->prev = pre;
        crr->next = NULL;
        crr->prev = NULL;
        delete crr;
        }
    }
}


int main(){

//insertion in doubly linkedlist=========================================
    // Node* node = new Node(10);
    // Node*head = node;
    // Node*tail = node;
    // print(head);
    // cout<<"length of doubly linkedlist is "<<getLength(head)<<endl;


    // Node*head = NULL;
    // Node*tail = NULL;

    // insertATHead(head,tail,9);
    // insertATHead(head,tail,8);
    // insertATHead(head,tail,7);
    // insertATHead(head,tail,6);
    // insertATHead(head,tail,5);
    // print(head);
    // insertAtTail(tail,head,11);
    // print(head);

    // insertAtPosition(head,tail,4,99);
    // print(head);

    // insertAtPosition(head,tail,8,82);
    // print(head);
    // delete node;

//deletion in doubly linkedlist============================================
    // deletionAtPosition(head,tail,1);
    // print(head);
    // deletionAtPosition(head,tail,4);
    // print(head);
    // deletionAtPosition(head,tail,6);
    // print(head);


    // cout<<"head : "<<head->data<<endl;
    // cout<<"tail : "<<tail->data<<endl;
    // cout<<"length of doubly linkedlist is "<<getLength(head)<<endl;
return 0;
}