#ifndef LINKEDLIST_H

#include "../includes/linkedlist.hpp"
#include <cstdlib>
#include <cstdio>

#define LINKEDLIST_H

void insert_front(float value, linkedlist_t **head) {
    linkedlist_t *newhead = (linkedlist_t*) malloc(sizeof (linkedlist_t));
    newhead->value = value;
    newhead->next = *head;
    *head = newhead;
}

void push_back(float value, linkedlist_t *head) {
    linkedlist_t *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    /* now we can add a new variable */
    current->next = (linkedlist_t*) malloc(sizeof (linkedlist_t));
    current->next->value = value;
    current->next->next = NULL;
}

void free_linkedlist(linkedlist_t *list) {
    linkedlist_t *next, *current = list;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void print_linkedlist(linkedlist_t *list) {
    linkedlist_t *current = list;
    while (current != NULL) {
        printf("%f -> ", current->value);
        current = current->next;
    }
    printf("null");
}

float pop(linkedlist_t **head) {
    int retval = -1;
    linkedlist_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->value;
    free(*head);
    *head = next_node;

    return retval;
}
#endif
