#include <stdlib.h>
#include <stdio.h>

#include "../includes/iterator.h"
#include "../includes/ll.h"



Iterator *create_list_iterator(List *list) {
    Iterator *iter = malloc(sizeof(*iter));
    
    if (iter == NULL) {
        fprintf(stderr, "Memlo allocation failed for iterator %s:%d", __FILE__, __LINE__);
    }
    iter->index     = 0;
    iter->list      = list;
    iter->has_next  = &__HAS_NEXT;
    iter->next      = &__NEXT;
    
    return iter;
}

bool __HAS_NEXT(Iterator *self) {
    return self->index < self->list->size(self->list);
}

void *__NEXT(Iterator *self) {
    if (self->index < self->list->size(self->list)) {
        return self->list->peek_at(self->list, self->index++);
    }
    return NULL;
}
