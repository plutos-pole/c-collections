#ifndef LL_H
#define LL_H

#include <stddef.h>
#include <stdbool.h>





typedef struct Node {
    void* data;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    size_t __size;
    /*  Methods  */
    size_t (*size) (struct List *self);
    bool   (*push) (struct List *self, void *pointer);
    void*  (*peek) (struct List *self);
    void*  (*pop)  (struct List *self);
    void*  (*destroy)(struct List *self);
    bool   (*is_empty)(struct List *self);
    void   (*remove)(struct List *self, size_t index);
    void*  (*extract)(struct List *self, size_t index);
    int    (*index_of)(struct List *self, void *query, bool (*callback)(void *data, void *query));
} List;



size_t __SIZE(List *self);
List *create_list(void);
bool __PUSH(List *self, void *data);
void *__PEAK(List *self);
void *__POP(List *self);
bool  __IS_EMPTY(List *self);
void *__DESTROY(List *self);
void __REMOVE(List *self, size_t index);
void *__EXTRACT(List *self, size_t index);
int __INDEX_OF(List *self, void *query, bool (*callback)(void *data, void *query));

#endif
