// reverse  linkedlist============================================
#include <iostream>
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
// =============================================================
void insertAtHead(Node* &head,int data){
    Node*node = new Node(data);
    node->next = head;
    head = node;
}
//============================================
void print(Node*head){
    Node*ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    }cout<<" NULL"<<endl;
}
//==========================================================
Node*recursionReverse(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node*newHead = recursionReverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}
//============================================================
void reverseList(Node* &head){
    if(head == NULL || head->next == NULL){
        return ;
    }
    Node*pre =NULL;
    Node*crr = head;
    Node*forward = NULL;
    while(crr != NULL){
        forward = crr->next;
        crr->next = pre;
        pre = crr;
        crr = forward;
    }
    head = pre;
}
//============================================================
Node*reverseKth(Node*head,int k){
    //base case
    if(head == NULL ){
        return NULL;
    }

    Node*forward =  NULL;
    Node*crr = head;
    Node*pre = NULL;
    int count = 0;
    
    while(crr != NULL && count<k){
        forward = crr->next;
        crr->next = pre;
        pre = crr;
        crr = forward;
        count++;
    }
    if(forward != NULL){
        head ->next = reverseKth(forward,k);
    }

    return pre;
}
void insertAtTail(Node* &tail,int data){
    Node*node = new Node(data);
    tail->next = node;
    tail = node;
}

Node* kReverse(Node* head, int k) {
    //base call
    if(head == NULL) {
        return NULL;
    }
    
    //step1: reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count= 0;
    
    while( curr != NULL && count < k ) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    //step2: Recursion dekhlega aage ka 
    if(next != NULL) {
        head -> next = kReverse(next,k);
    }
    
    //step3: return head of reversed list
    return prev;
}

Node*removeDuplicated(Node*head){
    if(head == NULL){
        return NULL;
    }

    Node*crr = head;

    while(crr != NULL){
        if((crr->next != NULL) && crr->data == crr->next->data){
            Node* next_next = crr->next->next;
            Node*nodeToDelete =   crr->next;
            delete (nodeToDelete);
            crr->next = next_next;
        }else{
            crr = crr->next;
        }
    }

    return head;
}
int main(){
    Node*head = NULL;
    Node*tail = NULL;
    Node*node = new Node(4); // starting node

    head = node;   // head pointing to starting node 
    tail = node;
    // insertion at head------------------------------------------
    // insertAtHead(head,5);
    // insertAtHead(head,4);
    // insertAtHead(head,3);
    // insertAtHead(head,2);
    // insertAtHead(head,1);
    insertAtTail(tail,5);
    insertAtTail(tail,7);
    insertAtTail(tail,7);
    insertAtTail(tail,7);
    insertAtTail(tail,9);
    insertAtTail(tail,9);
    insertAtTail(tail,19);
    insertAtTail(tail,29);
    insertAtTail(tail,39);
    insertAtTail(tail,39);
    print(head);

    // reverseList(head);
    // print(head);
//reverse using recursion=======================
    // Node* temp = recursionReverse(head);
    // print(temp);

    // int k = 2;
    // kReverse(head,k);
    // print(head);

    Node*temp = removeDuplicated(head);
    print(head);
return 0;
}