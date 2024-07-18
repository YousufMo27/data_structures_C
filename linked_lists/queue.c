#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct Queue {
    struct Node *front;
    struct Node *rear;
} Queue;

Node *create_node(int value);
Queue *create_queue();
void enqueue(Queue **head, int value);
void dequeue(Queue **head);
void print_list(Queue *head);
void delete_list(Queue *head);

Node *create_node(int value) {
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL) {
        fprintf(stderr,"malloc\n");
        return NULL;
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

Queue *create_queue() {
    Queue *new_queue = malloc(sizeof(Queue));
    if(new_queue == NULL) {
        fprintf(stderr,"malloc\n");
        return NULL;
    }
    new_queue->front = NULL;
    new_queue->rear = NULL;
    return new_queue;
}

void enqueue(Queue **head, int value) {
    Node *new_node = create_node(value);
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    // checking if the head is the only node in the Queue
    if ((*head)->front == NULL) {
        (*head)->front = new_node;
        (*head)->rear = new_node;
    } else { 
        (*head)->rear->next = new_node;
        (*head)->rear = new_node;
    }
}

void dequeue(Queue **head) {
    if((*head) == NULL) {
        return;
    }
    Node *tmp = (*head)->front;
    (*head)->front = (*head)->front->next;
    free(tmp);
}

void print_list(Queue *head) {
    Node *tmp = head->front;
    while(tmp != NULL) {
        printf("%d - ",tmp->value);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

void free_list(Queue *head) 
{
    Node *temp_node;
    while (head->front)
    {
        temp_node = head->front;
        head->front = head->front->next;
        free(temp_node);
    }
    // freeing queue
    free(head);
}


