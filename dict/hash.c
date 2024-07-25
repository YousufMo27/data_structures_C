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


void init_table() {
    for(int i = 0; i < MAX_SIZE; i++) {
        table[i] = NULL;
    }
}

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
    entry->key = key;
    entry->value = strdup(value);
    entry->next = NULL;
    return entry;
}

void insert(char *value, int key) {
    if(table[key] != NULL) {
        printf("Not Empty\n");
        HashTable *temp = table[key];
        printf("temp = %s\n",temp->value);
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_entry(key,value);
        return;
    }
    table[key] = new_entry(key,value);
}

void print_table(HashTable *table) {
    HashTable *tmp = table;
    while(tmp != NULL) {
        printf("key = %d, value = %s\n",tmp->key,tmp->value);
        tmp = tmp->next;
    }
}
