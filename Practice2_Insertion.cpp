#include<iostream>
using namespace std;
//Define the structure for a node
class Node
{
    public:
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
//Function to perform deletion
void deletationAtHead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    free(temp);
}
//Funcy to perform search
bool search(Node* head, int target) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == target) {
            return true; // Value found
        }
        current = current->next; // Move to the next node
    }
    return false; // Value not found
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
    int a,i;
    cout<<"Enter number of value  you want to add "<<endl;
    cin>>a;
    for(i=0;i<a;i++){
        int value;
        cout<<"Enter value "<<i+1<<" : ";
        cin>>value;
        //Insert the value at the beginning of the list
        insertAtBeginning(&head,value);
    }

    //Delete node at the beginning
    deletationAtHead(head);
    
    //print the linked list
    cout<<"Linked List: ";
    printList(head); 
    return 0;
}