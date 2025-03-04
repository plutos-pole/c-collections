#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../includes/ll.h"

/****** Helper function *******/
Node *_remove_head(List *list) {
    Node *tmp = NULL;
    tmp = list->head;
    list->head = list->head->next;
    return tmp;
}

Node *_find_node(List *list, size_t index) {
    Node *tmp = list->head;
    size_t curr_ind = 0;
    while (curr_ind < index - 1) {
        tmp = tmp->next;
        curr_ind++;
    }
    return tmp;
}
/*****************************/


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


void *__PEEK(List *self) {
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

void __REMOVE(List *self, size_t index) {
    if (self->is_empty(self) || index >= self->size(self)) {
        return;    
    } 
    Node *tmp = NULL;
    if (index == 0) {
       tmp = _remove_head(self);
       free(tmp->data);
       free(tmp);
    } else {
        tmp = _find_node(self, index);
        Node *next = tmp->next;
        tmp->next = tmp->next->next;
        free(next->data);
        free(next);
    }
    self->__size--;
}

void *__EXTRACT(List *self, size_t index) {
    if (self->is_empty(self) || index >= self->size(self)) {
        return NULL;
    }
    void *result = NULL;
    Node *tmp = NULL;

     if (index == 0) {
       tmp = _remove_head(self);
       result = tmp->data;
       free(tmp);
    } else {
        tmp = _find_node(self, index);
        Node *next = tmp->next;
        tmp->next = tmp->next->next;
        result = next->data;
        free(next);
    }
    self->__size--;
    return result;
}


void* __PEEK_AT(List *self, size_t index) {
    if (self->is_empty(self) || index >= self->size(self)) {
        return NULL;
    }
    Node *tmp = self->head;
    size_t i = 0;
    while (i < index) {
        tmp = tmp->next;
        i++;
    }
    return tmp->data;
}


int __INDEX_OF(List *self, void *query, bool (*callback)(void *, void *)) {
    if (self->is_empty(self)) {
        return -1;
    }
    Node *tmp = self->head;
    int curr_ind = 0;
    while (tmp != NULL) {
        if (callback(tmp->data, query)) {
            return curr_ind;
        }
        tmp = tmp->next;
        curr_ind++;
    }
    return -1;
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

    p->__size       =    0;
    p->head         =    NULL;
    p->size         =    &__SIZE;
    p->push         =    &__PUSH;
    p->destroy      =    &__DESTROY;
    p->peek         =    &__PEEK;
    p->pop          =    &__POP;
    p->is_empty     =    &__IS_EMPTY;
    p->remove       =    &__REMOVE;
    p->index_of     =    &__INDEX_OF;
    p->peek_at      =    &__PEEK_AT;
    p->extract      =    &__EXTRACT;

    return p;

}



