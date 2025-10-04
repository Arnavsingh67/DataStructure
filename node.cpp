#include<iostream>
#include<stdlib.h>

using namespace std;

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *start = NULL;
    struct node *n1 = (struct node*)malloc(sizeof(struct node));
    n1->data = 10;
    n1->next = NULL;
    start = n1;

    struct node *n2 = (struct node*)malloc(sizeof(struct node));
    n2->data = 20;
    n2->next = NULL;
    n1->next = n2; // Link n1 to n2

    struct node *n3 = (struct node*)malloc(sizeof(struct node));
    n3->data = 30;
    n3->next = NULL;
    n2->next = n3; // Link n2 to n3

    struct node *ptr = start;
    while(ptr != NULL) {
        cout << ptr->data << " ";
        cout<<ptr->next<<" ";
        ptr = ptr->next;
    }

    // Freeing memory correctly
    free(n1);
    free(n2);
    free(n3);

    return 0;
}