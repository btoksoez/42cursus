#include <stdio.h>
#include "push_swap.h"

// Function to create a new node for the linked list
t_stack *create_node(int value) {
    t_stack *newNode = (t_stack *)malloc(sizeof(t_stack));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->index = 0;  // Initialize index to 0
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Create a linked list in the main
    t_stack *stack_a = create_node(90);
    stack_a->next = create_node(0);
    stack_a->next->next = create_node(-4);
    stack_a->next->next->next = create_node(12);

    // Print the original linked list
    printf("Original Linked List:\n");
    t_stack *current = stack_a;
    while (current) {
        printf("Value: %d\n", current->value);
        current = current->next;
    }

    // Get and print the index information
    get_index(stack_a);

    // Print the modified linked list with index information
    printf("\nLinked List with Index:\n");
    current = stack_a;
    while (current) {
        printf("Value: %d, Index: %d\n", current->value, current->index);
        current = current->next;
    }

    // Cleanup: Free the memory for the linked list
    current = stack_a;
    while (current) {
        t_stack *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
