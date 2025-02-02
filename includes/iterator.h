#include <stdbool.h>
#include "ll.h"





typedef struct Iterator {
    size_t index;
    List *list;
    bool (*has_next)(struct Iterator *self);
    void* (*next)(struct Iterator *self);
} Iterator;


bool __HAS_NEXT(Iterator *self);
void *__NEXT(Iterator *self);
Iterator *create_list_iterator(List *list);


