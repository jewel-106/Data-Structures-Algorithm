/// C++ progam to Implement doubly linked list
#include<bits/stdc++.h>
using namespace std;

// Define a class named Node to represent a node in the doubly linked list
class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data){
            this->data = data;
            this->prev = nullptr;
            this->next = nullptr;
        }
};

// function to insert a node at the beginning of the doubly linked list.
void insertAtBeginning(Node*& head, int data)
{
    Node* newNode = new Node(data);

    if(head == nullptr){
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;

}

// fucntion to insert a node at the end of the doubly linked list
void insertAtEnd(Node*& head, int data)
{
    Node* newNode = new Node(data);

    if(head == nullptr){
        head = nullptr;
        return;
    }


    /// traverse to the last node of the list.
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert a node at a specified position in the doubly linked list
void insertatPosition(Node*& head, int data, int position)
{
    if(position<1){
        cout<<"Position should be >=1."<<endl;
        return;
    }

    if(position == 1){
        insertAtBeginning(head, data);
        return;
    }

    Node* newNode = new Node(data);
    Node* temp = head;

    // Traverse to the node before the specified position
    for(int i=1;temp !=nullptr && i<position -1;i++){
        temp = temp->next;
    }

    if(temp == nullptr){
        cout<<"Position greater than the number of nodes."<<endl;
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// function to delete a node from the beginning of the doubly linked list
void deleteAtBeginning(Node*& head)
{
    if(head == nullptr){
        cout<<"The list is already empty."<<endl;
        return;
    }
    
    Node* temp = head;
    head = head->next;
    if(head!=nullptr){
        head->prev = nullptr;
    }
    delete temp;
}

// Function to delete a node from the end of the doubly linked list
void deleteAtEnd(Node*& head)
{
    if(head == nullptr){
        cout<<"The list is already empty."<<endl;
        return;
    }

    Node* temp = head;
    if(temp->next == nullptr){
        head = nullptr;
        delete temp;
        return;
    }

    // traverse to the last node of the list.
    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    delete temp;
}

// Function to delete a node from a specified position in the doubley linked list
void deleteAtPosition(Node*& head, int position)
{
    if(head == nullptr){
        cout<<"The list is already empty."<<endl;
        return;
    }

    if(position == 1) {
        deleteAtBeginning(head);
        return;
    }

    Node* temp = head;
    // Traverse to the node at the specified position.
    for(int i=1;temp!= nullptr && i<position;i++){
        temp = temp->next;
    }

    if(temp == nullptr){
        cout<<"Position is greater than the number of nodes."<<endl;
        return;
    }

    if(temp->next != nullptr){
        temp->next->prev = temp->prev;
    }
    if(temp->prev!=nullptr){
        temp->prev->next = temp->next;
    }
    delete temp;
}

void printListForward(Node* head)
{
    Node* temp = head;
    cout<<"Forward List: ";
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void printListReverse(Node* head)
{
    Node* temp = head;
    if(temp==nullptr){
        cout<<"the list is empty."<<endl;
        return;
    }

    // Move to the end of the list
    while(temp->next !=nullptr){
        temp=temp->next;
    }

    cout<<"Reverse list: ";
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}

int main()
{
    Node* head = nullptr;

    insertAtBeginning(head,10);
    insertAtEnd(head,20);
    insertAtEnd(head,200);
    insertAtEnd(head,2000);


    insertatPosition(head,30,4);

    cout<<"After insertion: "<<endl;
    printListForward(head);
    printListReverse(head);

    deleteAtBeginning(head);
    deleteAtEnd(head);
    deleteAtPosition(head,2);
    cout<<"After Deletion: "<<endl;
    printListForward(head);

    return 0;
}