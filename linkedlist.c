#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Head pointer (global for simplicity)
struct Node* head = NULL;

// Function to insert a node at the end
void insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Function to delete a node by value
void deleteValue(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // If the head node itself holds the value
    if (head->data == value) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Value not found in the list.\n");
        return;
    }

    prev->next = current->next;
    free(current);
}

// Function to traverse and display the list
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function (example usage)
int main() {
    insert(10);
    insert(20);
    insert(30);

    printf("Linked List after insertion:\n");
    display();

    deleteValue(20);
    printf("Linked List after deleting 20:\n");
    display();

    return 0;
}
