#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // malloc in C++ (C-style)
    if (newNode == NULL) {
        cout << "Memory allocation failed\n";
        exit(0);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* createLinkedList(int n) {
    Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;
    if (n <= 0) {
        cout << "Invalid size of list.\n";
        return NULL;
    }
    cout << "Enter elements of linked list:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> value;
        newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

void insertnewnode(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // same concept as createNode
    
    newNode->data = value;
    newNode->next = NULL;

    Node* temp = head;
    while (temp->next != NULL) {  // traverse to last node
        temp = temp->next;
    }
    temp->next = newNode;  // attach at last
}

void displayLinkedList(Node* head) {
    Node* temp = head;
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void DeleteEndNode(Node* head) {
    Node* temp = head;
    Node* prev=NULL;
    int pos = 1;
     while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
   
        
    }
    prev->next=NULL;
    free(temp);

}

void freeLinkedList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int n, val;
    string y,x;
    cout << "Enter number of nodes: ";
    cin >> n;
    head = createLinkedList(n);
    displayLinkedList(head);

    cout<<"do you want to delte the last node yes or no\n";
    cin>>x;
    if(x=="yes"){
         DeleteEndNode(head);

    }
   
    cout<<"do you want to add new node at the end yes or no\n";
    cin>>y;
    if(y=="yes")
    {
        cout << "Enter new value to insert at end: ";
        cin >> val;
        insertnewnode(head, val);   // call the new function
    }
    
    displayLinkedList(head);

    freeLinkedList(head);
    return 0;
}
