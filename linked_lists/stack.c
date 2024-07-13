#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Stack;

Stack *create_node(int value);
void push(Stack **head, int value);
void print_list(Stack *print_node);
void free_list(Stack *head);
void pop(Stack **head);

Stack *create_node(int value) 
{
    Stack *new_node;
    new_node = malloc(sizeof(Stack)); //allocating space for node
    if(new_node == NULL) 
    {
        return NULL;
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Single Pointer - modifies head
// double pointer - modifies where head points to
void push(Stack **head, int value) 
{
    Stack *new_node = malloc(sizeof(Stack));
    new_node->value = value;
    new_node->next = *head;
    *head = new_node;
}

void pop (Stack **head) 
{
    Stack *pop_node;
    pop_node = (*head);
    (*head) = (*head)->next;
    free(pop_node);
}


void print_list(Stack *print_node) 
{
    Stack *temp_node = print_node;
    while (temp_node != NULL) 
    {
        printf("%d - ",temp_node->value);
        temp_node = temp_node->next;
    }
    printf("\n");
}


void free_list(Stack *head) 
{
    Stack *temp_node;
    while (head)
    {
        temp_node = head;
        head = head->next;
        free(temp_node);
    }
}


