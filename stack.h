#include <stdio.h>
#include <stdlib.h>
typedef struct stack {
    int data;
    struct stack *next;
} stack;

stack *push(stack *top, int data) {
    stack *new_node = (stack *) malloc(sizeof(stack));
    if (new_node == NULL) {
        printf("Error: malloc failed\n");
        return NULL;
    }
    if (top == NULL)
        new_node->next = NULL;
    else 
        new_node->next = top;
    new_node->data = data;
    return new_node;
}

stack *pop(stack *top) {
    if (top == NULL) {
        return NULL;
    }
    stack *new_node = top->next;
    free(top);
    return new_node;
}

void print_stack(stack *top) {
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}