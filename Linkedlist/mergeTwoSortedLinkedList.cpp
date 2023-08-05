#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~node(){
        int value = this->data;
        if(this->next!= NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory is free for the node with value -> "<<value<<endl;

    }
};
//
void insertAtTail(node* &tail1,int data){
    node*n = new node(data);
    tail1->next = n;
    tail1 = n;
}
//
void print(node*head1){
    node*ptr = head1;
    while(ptr != NULL){
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    }cout<<" NULL"<<endl;
}
// function to merge two sorted linked list --------------------------------------------
node* solve(node* first, node* second){

    if(first->next == NULL){
        first->next = second;
        return first;
    }

    node* crr1 = first;
    node* next1= first->next;
    node* crr2 = second;
    node* next2= crr2->next;

    while(next1 != NULL && crr2 != NULL){
        if(crr1->data <= crr2->data && next1->data >= crr2->data){
            // inserting the data
            crr1->next = crr2;
            next2 = crr2->next;
            crr2->next = next1;

            //updating pointers
            crr1=crr1->next;
            crr2 = next2;
        }else{
            crr1 = crr1->next;
            next1 = next1->next;

            if(next1 == NULL){
                crr1->next = crr2;
                return first;
            }
        }
    }
    return first;
}
node* sortTwoLists(node* first, node* second)
{
    if( first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }

    if(first->data <= second->data){
        return solve(first,second);
    }else{
       return solve(second,first);
    }

}
int main(){
    node*head1 = NULL;
    node*tail1 = NULL;
    node*n = new node(-1); // starting node

    head1 = n;   // head1 pointing to starting node 
    tail1 = n;
    insertAtTail(tail1,1);
    insertAtTail(tail1,2);
    insertAtTail(tail1,4);
    insertAtTail(tail1,6);
    print(head1);
    cout<<"============================================="<<endl;
    node*head2 = NULL;
    node*tail2 = NULL;
    node*z = new node(-4); // starting node

    head2 = z;   // head1 pointing to starting node 
    tail2 = z;
    insertAtTail(tail2,3);
    insertAtTail(tail2,5);
    insertAtTail(tail2,7);
    insertAtTail(tail2,8);
    insertAtTail(tail2,9);
    print(head2);

// merge two sorted linkedlist =================================
    cout<<"Merged linkedlist ------------------------------> "<<endl;
    node*head = sortTwoLists(head1,head2);
    print(head);

    return 0;
}