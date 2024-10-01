#include<iostream>
using namespace std;
//Define the structure for a node
struct Node
{
    int data;   //Data to Store
    Node* next; //Pointer to the next node
};
//function to insert a node at the beginning 
void insertAtBeginning(Node** head, int newData){
    //Allocate memory for a new node
    Node* newNode = new Node();
    //Assign data to the new node
    newNode->data = newData;
    //Make next of new Node point to the current head
    newNode->next = *head;
    //Move the head to point to the new node
    *head = newNode;
}
//function ro reverse the current node
    void reverse(Node** head){
        Node* prev = nullptr;
        Node* current = *head;
        Node* next = nullptr;
        while(current!= nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        *head = prev;
    }
//Function to print the linked list
void printList(Node* node){
    while(node!= nullptr){
        cout<<node->data<<" ->";
        node = node->next;
    }
    cout<<"NULL "<<endl;
}
int main()
{
    cout<<"\n\n******************************** Lab 05 Linked List Implementation********************************\n\n"<<endl;
    //Initialize the head as NULL (empty list)
    Node* head = nullptr;
    //Insert node at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    cout<<"Original List"<<endl;
    printList(head);
    //print the linked list
    reverse(&head);
    cout<<"\nTraversed Linked List: ";
    printList(head); 
    return 0;
}