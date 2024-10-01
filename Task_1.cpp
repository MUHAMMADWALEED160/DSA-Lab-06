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

//Function to perform the deletion
void deleteNode(Node** head, int key){
    //if the linked list is empty
    if(head == NULL){
        cout<<"list is empty"<<endl;
    }
    Node* temp = *head;
    Node* prev = NULL;
    //if the head node holds the key to be deleted
    if (temp != NULL && temp->data == key){
        *head = temp->next; // Changed head
        delete temp;       // free old head
        return;
    }
    //search for the key to be deleted
    while(temp != NULL&& temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    //if key was not present in the list
    if (temp == NULL){
        cout<<"Key not found in the list"<<endl;
        return;
    }
    //Unlink the node from the linked list
    prev->next = temp->next;
    //free memory of the node
    delete temp;
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
    int deleteValue,searchValue;
    cout<<"Enter number you want to be deleted:  ";
    cin>>deleteValue;
    //Delete the node with the specified value
    deleteNode(&head, deleteValue);
    printList(head); 

    cout<<"Enter number you want to search: ";
    cin>>searchValue;
    if (search(head, searchValue)) {
        cout << searchValue << " is found in the linked list." << endl;
    } else {
        cout << searchValue << " is not found in the linked list." << endl;
    }

    search(head,searchValue) ;
    
    //print the linked list
    cout<<"Linked List: ";
    printList(head); 
    return 0;
}