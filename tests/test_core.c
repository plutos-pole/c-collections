#include "../lib/tlib.h"
#include "../includes/ll.h"
#include <stdbool.h>
#include <string.h>


void test_create_list() {
    List *list = create_list();
    TEST_ASSERT(list == true);
    list->destroy(list);
}

void test_destroy_list() {
    List *list = create_list();
    list = list->destroy(list);
    TEST_ASSERT((list == NULL));
}

void test_get_size() {
    List *list = create_list();
    int i = (int)list->size(list);
    TEST_ASSERT_INT_EQ(0, i);
    list->destroy(list);
}

void test_push() {
    List *list = create_list();
    int *p_i = malloc(sizeof(int));
    char *p_str = malloc(sizeof(char) * 10);
    int size;
    bool result;
    result = list->push(list, p_i);
    TEST_ASSERT(result == true);
    size = (int)list->size(list);
    TEST_ASSERT_INT_EQ(1, size);
    result = list->push(list, p_str);
    TEST_ASSERT(result == true);
    size = (int)list->size(list);
    TEST_ASSERT_INT_EQ(2, size);

    list->destroy(list);
}

void test_peek() {
    List *list = create_list();
    int *p_i = malloc(sizeof(int));
    char *p_str = malloc(sizeof(char) * 10); 
    strcpy(p_str, "Testing");
    *p_i = 10;
    list->push(list, p_i);
    int *result = list->peek(list);
    TEST_ASSERT_INT_EQ(10, *result);
    list->push(list, p_str);
    char *str_r = (char *)list->peek(list);
    TEST_ASSERT(strcmp(str_r, "Testing") == 0);

    list->destroy(list);
}


void test_pop() {
    List *list = create_list();
    int *p_1 = malloc(sizeof(int));
    int *p_2 = malloc(sizeof(int));
    *p_1 = 1;
    *p_2 = 2;

    list->push(list, p_1);
    list->push(list, p_2);

    int *result = list->pop(list);
    TEST_ASSERT(*result == 2);
    TEST_ASSERT(list->size(list) == 1);
    int *result2 = list->pop(list);
    TEST_ASSERT(*result2 == 1);
    int size = (int)list->size(list);
    TEST_ASSERT(size == 0);
    free(result);
    free(result2);
    list->destroy(list);

}

void test_empty_peek() {
    List *l = create_list();
    TEST_ASSERT((l->peek(l) == NULL));
    l->destroy(l);
}

void test_empty_pop() {
    List *l = create_list();
    TEST_ASSERT((l->pop(l) == NULL));
    l->destroy(l);
}

void test_if_empty() {
    List *l = create_list();
    TEST_ASSERT((l->is_empty(l) == true));
    int *i = malloc(sizeof(int));
    l->push(l, i);
    TEST_ASSERT((l->is_empty(l) == false));
    int *result = (int *)l->pop(l);
    TEST_ASSERT((l->is_empty(l) == true));
    free(result);
    l->destroy(l);
}

int main (void) {

    RUN_TEST(test_create_list); 
    RUN_TEST(test_destroy_list);
    RUN_TEST(test_get_size);
    RUN_TEST(test_push);
    RUN_TEST(test_peek);
    RUN_TEST(test_pop);
    RUN_TEST(test_empty_peek);
    RUN_TEST(test_empty_pop);
    RUN_TEST(test_if_empty);
    return 0;
}
