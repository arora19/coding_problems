#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Linked List class
typedef struct LinkedList {
    Node* head;
} LinkedList;

// Initialize an empty linked list
void initialize(LinkedList* list) {
    list->head = NULL;
}

// Search for an element in the linked list
Node* search(LinkedList* list, int value) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Add an element to the linked list
void add(LinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Delete an element from the linked list
void delete(LinkedList* list, int value) {
    if (list->head == NULL) {
        return; // Empty list, nothing to delete
    }

    if (list->head->data == value) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        return;
    }

    Node* current = list->head;
    while (current->next != NULL) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}

// Print the linked list
void printList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

 int main() {
    LinkedList my_list = {NULL};
    int data;
    char choice;
    do {
        printf("Enter an integer: ");
        scanf("%d", &data);
        add(&my_list, data);
        printf("Do you want to add another integer? (y/n) ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    printf("Enter an integer to search for: ");
    scanf("%d", &data);
    if (search(&my_list, data)) {
        printf("%d was found in the linked list.\n", data);
    } else {
        printf("%d was not found in the linked list.\n", data);
    }
    printf("Enter an integer to delete: ");
    scanf("%d", &data);
    delete(&my_list, data);
    printf("The updated linked list is: ");
    Node* curr_node = my_list.head;
    while (curr_node != NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("\n");
    return 0;

}

