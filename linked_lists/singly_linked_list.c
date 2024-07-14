#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} SLList;

SLList *create_node(int value);
void insert_node(SLList *preNode, SLList *insert_node);
void delete_node(SLList *preNode, SLList *delete_node);
void append(SLList **head, SLList *insert_node);
void free_list(SLList *head);
void print_list(SLList *printNode);


SLList *create_node(int value) {
    SLList *new_node;
    new_node = malloc(sizeof(SLList)); //allocating space for node
    if(new_node == NULL) {
        return NULL;
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void insert_node(SLList * node_before_insert, SLList * node_to_insert) {
    if (node_before_insert == NULL) {
        return;
    }
    node_to_insert->next = node_before_insert->next;
    node_before_insert->next = node_to_insert;
}

void delete_node(SLList * node_before_delete, SLList *node_to_delete) {
    node_before_delete->next = node_to_delete->next;
}

void append(SLList **head, SLList *node_to_append) {
    if(!(*head) && !node_to_append) {
        return;
    }
    if ((*head) == NULL) {
        (*head) = node_to_append;
    }
    SLList *current_node = *head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = node_to_append;
    current_node->next->value = node_to_append->value;
    node_to_append->next = NULL;
}

void free_list(SLList * head) {
    SLList *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void print_list(SLList * head) {
    SLList *tmp = head;
    while (tmp != NULL) {
        printf("%d - ",tmp->value);
        tmp = tmp->next;
    }
    printf("NULL\n");
}
