#include <stdlib.h>
#include "../lib/tlib.h"
#include "../includes/ll.h"
#include "../includes/iterator.h"



void test_has_next_empty() {
    List *l = create_list();
    Iterator *iter = create_list_iterator(l);
    TEST_ASSERT(iter->has_next(iter) == false);
    free(iter);
    l->destroy(l);

}
void test_has_next() {
    List *l = create_list();
    Iterator *iter = create_list_iterator(l);
    int *i = malloc(sizeof(int));
    *i = 1;
    l->push(l, i);
    TEST_ASSERT(iter->has_next(iter) == true);
    free(iter);
    l->destroy(l);

}

void test_returns_next() {
    List *l = create_list();
    Iterator *iter = create_list_iterator(l);
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    *a = 1;
    *b = 2;
    l->push(l, a);
    l->push(l, b);
        
    int *result = iter->next(iter);
    TEST_ASSERT(*result == 2);
    result = iter->next(iter);
    TEST_ASSERT(*result == 1);
    result = iter->next(iter);
    TEST_ASSERT(result == NULL);

    free(iter);
    l->destroy(l);


}



int main() {
    RUN_TEST(test_has_next_empty);
    RUN_TEST(test_has_next);
    RUN_TEST(test_returns_next);
    return 0;
}
