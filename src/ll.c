#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../includes/ll.h"



size_t __SIZE(List *self) {
    return self->__size;
}

bool __PUSH(List *self, void *data) {
    Node *n = malloc(sizeof(*n));
    if (n == NULL) {
        fprintf(stderr, "Memory allocation failed for node: %s:%d\n", __FILE__, __LINE__);
        return false;
    }
    
    n->data = data;
    n->next = self->head;
    self->head = n;
    self->__size++;

    return true;
}


void *__PEAK(List *self) {
    if (self->is_empty(self)) {
        return NULL;
    }
    return self->head->data;
}

void *__POP(List *self) {
    if (self->is_empty(self)) {
        return NULL;
    }
    Node *temp = self->head;
    void *data = temp->data;
    self->head = temp->next;
    self->__size--;
    free(temp);
    return data;
}

bool __IS_EMPTY(List *self) {
    return (self->__size == 0);
}

void *__DESTROY(List *self) {
    Node *next = NULL;

    while(self->head != NULL) {
        free(self->head->data);
        next = self->head->next;
        free(self->head);
        self->head = next;
    }
    free(self);
    return NULL;
}


List *create_list(void) {
    List *p = malloc(sizeof(*p));
    
    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed for list: %s:%d", __FILE__, __LINE__);
        return NULL;
    }

    p->__size   =    0;
    p->head     =    NULL;
    p->size     =    &__SIZE;
    p->push     =    &__PUSH;
    p->destroy  =    &__DESTROY;
    p->peek     =    &__PEAK;
    p->pop      =    &__POP;
    p->is_empty =    &__IS_EMPTY;

    return p;

}



