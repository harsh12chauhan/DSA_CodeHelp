#include <iostream>
#include <map>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(int data){
        this->data = data;
        this->next=NULL;
    }
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with value -> "<<value<<endl;
    }
};
//insert at head ===================================================
void insertAtHead(Node* &head,int data){
    Node*node = new Node(data);
    node->next = head;
    head = node;
}

//insert at tail ==================================================
// void insertAtTailwithloop(Node* &head,int data){
//     Node*node = new Node(data);
//     Node*ptr = head;
//     while (ptr->next != NULL)
//     {
//        ptr = ptr->next;
//     }
//     ptr->next = node;
// }
//without traversing ===================
void insertAtTail(Node* &tail,int data){
    Node*node = new Node(data);
    tail->next = node;
    tail = node;
}
//inserting at given position======================================
void insertAtPosition(Node* &tail ,Node* &head,int data, int position ){

    if(position == 1){
        insertAtHead(head,data);
        return;
    }
    Node*ptr = head;
    int i = 1;
    while (i < position-1)
    {
        ptr = ptr->next;
        i++;
    }

    if(ptr->next == NULL){
        insertAtTail(tail,data);
        return;
    }
    Node*node = new Node(data);
    node->next = ptr->next;
    ptr->next = node;
}
// deleting an node from linkedlist================================
void deleteAtPosition(Node* &head,Node* &tail,int position){
    if(position == 1){
        Node*temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }else{
    //method 1-----------------------
        // Node*ptr = head;
        // int i = 1;
        // while(i < position-1){
        //     ptr = ptr->next;
        //     i++;
        // }
        // Node*temp = ptr->next;
        // ptr->next = ptr->next->next;
        
        // temp->next = NULL;
        // delete temp;
    //method 2-----------------------
        Node*current = head;
        Node*prev = NULL;
        int count = 1;
        while(count < position){
            prev = current;
            current = current->next;
            count++;
        }
        if(current->next == NULL){
            Node*temp = current;
            prev->next = current->next;
            tail = prev;
        }
        Node*temp = current;
        prev->next = current->next;

        temp->next = NULL;
        delete temp;
    }
}

//printing a linkedlist=============================================
void print(Node*head){
    Node*ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    }cout<<" NULL"<<endl;
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
    cout<<"no loop is present "<<endl;
    return NULL;
}
Node*getstartingNode(Node*head){
    if(head ==NULL){
        return NULL;
    }
    Node*intersection = floydDetection(head);
    if(intersection == NULL){
        return NULL;
    }
    Node*slow = head;

    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    cout<<" the begining node of the loop is -> "<<slow->data<<endl;
    return slow;
}
Node* removeLoop(Node*head){
    Node*startNode = getstartingNode(head);
    if(startNode == NULL){
        return head;
    }
    Node*temp = startNode;

    while (temp->next != startNode)
    {
        temp = temp->next;
    }

    temp->next = NULL;
    return head;
}
int main(){

//Singlly linkedList=========================================================================
    // Node*node = new Node(10);
    // cout<<node->data<<endl;
    // cout<<node->next<<endl;
    // delete node;

    Node*head = NULL;
    Node*tail = NULL;
    Node*node = new Node(10); // starting node

    head = node;   // head pointing to starting node 

    tail = node;  // tail pointing to starting node for inserting
                  // at tail  without traversing

    //insertion at head------------------------------------------
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAtHead(head,40);
    insertAtHead(head,50);
    insertAtHead(head,60);
    print(head);
    tail->next = head->next->next; // testing the detect loop function
    
    //insertion at tail by looping ---------------------------
    // insertAtTail(tail,5);
    // print(head);

    //insertion at tail with(tail)node by taking address of last node----
    // insertAtTailwithloop(head,5);
    // print(head);

    //insertion at position -----------------------------------
    // insertAtPosition(tail,head,9,3);
    // print(head);
    // cout<<"head "<<head->data<<endl;
    // cout<<"tail "<<tail->data<<endl;
    // insertAtPosition(head,0,0);
    // print(head);

    //deletion at position--------------------------------------
    // deleteAtPosition(head,tail,6);

// loop detection =================================================================
    // detectLoop(tail);
    floydDetection(head);
    // print(head);

    // finding begining node of loop--------------------
    Node*startNode = getstartingNode(head);
    //remove the loop------------------------
    removeLoop(head);    
    floydDetection(head);


    // cout<<"head "<<head->data<<endl;
    // cout<<"tail "<<tail->data<<endl;
    // delete node;

return 0;
}