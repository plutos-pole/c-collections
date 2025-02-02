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
    int *i = malloc(sizeof(int));
    *i = 1;
    l->push(l, i);

    int *result = iter->next(iter);
    TEST_ASSERT(*result == 1);

    free(iter);
    l->destroy(l);


}



int main() {
    RUN_TEST(test_has_next_empty);
    RUN_TEST(test_has_next);
  //  RUN_TEST(test_returns_next);
    return 0;
}
