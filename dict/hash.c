// Compiling: gcc -std=gnu99 -Wall hash.c
#include <stdio.h>
#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct HashMap {
    struct HashMap *next;
    char *value;
    int key;
} HashTable;

HashTable *table[MAX_SIZE];

void init_table();
int hash(char *);
void insert(char *, int);
HashTable * new_entry(int,char *);
void lookup(char *);
void delete(char *value, int key);


void init_table() {
    for(int i = 0; i < MAX_SIZE; i++) {
        table[i] = NULL;
    }
}
// simple hashing algorithm
int hash(char *str) {
    int key = 0;
    for (int i = 0; i < strlen(str); i++) {
        key+=str[i];
    }
    return key % MAX_SIZE;
}

HashTable * new_entry(int key,char *value) {
    HashTable *entry = NULL;
    entry = malloc(sizeof(HashTable));
    if(entry == NULL) {
        return NULL;
    }
    // set the values
    entry->key = key;
    // strdup allows for cleaner code, same as mallocing then strcpy
    entry->value = strdup(value);
    entry->next = NULL;
    return entry;
}

void insert(char *value, int key) {
    if(table[key] != NULL) {
        HashTable *temp = table[key];
        // iterate to end of list then append
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_entry(key,value);
        return;
    }
    table[key] = new_entry(key,value);
}

void delete(char *value, int key) {
    // two pointers following from head previous and tmp (current)
    HashTable *tmp = table[key];
    HashTable *prev = table[key];
    // if key does not match value
    if(hash(value) != key) {
        printf("Invalid Key\n");
    }
    if(table[key]->next == NULL) {
        free(table[key]);
        free(table[key]->value);
        table[key] = NULL; 
        return;
    }
    if(table[key]->next != NULL && strcmp(value,table[key]->value) == 0) {
        table[key] = table[key]->next;
        free(tmp->value);
        free(tmp);
        return;
    }
    
    while (tmp != NULL)
    {
        tmp = tmp->next;
        if(strcmp(tmp->value,value) == 0) {
                prev->next = tmp->next;
                free(tmp->value);
                free(tmp);
                tmp = NULL;
                return;
        }
        prev = prev->next;
    }

}

void print_table(HashTable *table) {
    HashTable *tmp = table;
    if(tmp == NULL) {
        printf("Empty\n");
    }
    while(tmp != NULL) {
        printf("key = %d, value = %s\n",tmp->key,tmp->value);
        tmp = tmp->next;
    }
}

void lookup(char *value) {
    int key = hash(value);
    HashTable *tmp = table[key];
    int iter = 0;
    while(tmp != NULL) {
        if(strcmp(tmp->value,value) == 0) {
            printf("%s found on table index - %d at position %d\n",value,key,iter);
            return;
        }
        iter++;
        tmp = tmp->next;
    }
    printf("Value not found.../n");
}
