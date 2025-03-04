#include "../lib/tlib.h"
#include "../includes/ll.h"
#include <stdbool.h>
#include <string.h>

/****** Callback Test Function *******/
bool findStr(void *data, void *query) {
    char *look_for = (char *)query;
    char *got = (char *)data;
    if (strcmp(look_for, got) == 0) {
        return true;
    }
    return false;
}
/*************************************/

void test_create_list() {
    List *list = create_list();
    TEST_ASSERT(list != NULL);
    list->destroy(list);
}

void test_destroy_list() {
    List *list = create_list();
    list = list->destroy(list);
    TEST_ASSERT(list == NULL);
}

void test_get_size() {
    List *list = create_list();
    int i = (int)list->size(list);
    TEST_ASSERT(i == 0);
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
    TEST_ASSERT(1 == size);
    result = list->push(list, p_str);
    TEST_ASSERT(result == true);
    size = (int)list->size(list);
    TEST_ASSERT(2 == size);

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
    TEST_ASSERT(10 == *result);
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
    int *result2 = list->pop(list);
    TEST_ASSERT(*result2 == 1);
    void *result3 = list->pop(list);
    TEST_ASSERT(result3 == NULL);
    free(result);
    free(result2);

    list->destroy(list);

}

void test_empty_peek() {
    List *l = create_list();

    TEST_ASSERT(l->peek(l) == NULL);

    l->destroy(l);
}

void test_empty_pop() {
    List *l = create_list();

    TEST_ASSERT(l->pop(l) == NULL);

    l->destroy(l);
}

void test_if_empty() {
    List *l = create_list();
    TEST_ASSERT(l->is_empty(l) == true);
    int *i = malloc(sizeof(int));
    *i = 1;
    l->push(l, i);
    TEST_ASSERT(l->is_empty(l) == false);
    int *result = (int *)l->pop(l);
    TEST_ASSERT(l->is_empty(l) == true);
    free(result);

    l->destroy(l);
}

void test_remove_at_head() {
    List *l = create_list();
    int *ind_0 = malloc(sizeof(int));
    int *ind_1 = malloc(sizeof(int));
    *ind_0 = 1, *ind_1 = 2;
    l->push(l, ind_0);
    l->push(l, ind_1);
    l->remove(l, 0);
    TEST_ASSERT(l->size(l) == 1);
    int *result = l->pop(l);
    TEST_ASSERT(*result == 1);

    free(result);
    l->destroy(l);
}


void test_remove_at_tail() {
    List *l = create_list();
    int *ind_0 = malloc(sizeof(int));
    int *ind_1 = malloc(sizeof(int));
    *ind_0 = 1, *ind_1 = 2;
    l->push(l, ind_0);
    l->push(l, ind_1);
    l->remove(l, 1);
    TEST_ASSERT(l->size(l) == 1);

    l->destroy(l);
}

void test_remove_out_of_bound() {
    List *l = create_list();

    int *i = malloc(sizeof(int));
    l->push(l, i);
    l->remove(l, -1);
    TEST_ASSERT(l->size(l) == 1);
    l->remove(l, 5);
    TEST_ASSERT(l->size(l) == 1);

    l->destroy(l);

}

void test_find_indexof() {
    List *l = create_list();
    char *s1 = malloc(sizeof(char) * 10);
    char *s2 = malloc(sizeof(char) * 10);
    strcpy(s1, "Hello");
    strcpy(s2, "Testing");
    l->push(l, s1);
    l->push(l, s2);
    size_t index = l->index_of(l, "Testing", &findStr);
    TEST_ASSERT(index == 0);
    index = l->index_of(l, "Hello", &findStr);
    TEST_ASSERT(index == 1);

    l->destroy(l);
}

void test_find_missing() {
    List *l = create_list();
    
    int ind = l->index_of(l, "Test", &findStr);
    TEST_ASSERT(ind == -1);
    char *s1 = malloc(sizeof(char) * 10);
    strcpy(s1, "Hello");
    l->push(l, s1);
    ind = l->index_of(l, "Test", &findStr);
    TEST_ASSERT(ind == -1);

    l->destroy(l);
}

void test_extract() {
    List *l = create_list();

    int *ind_0, *ind_1;
    ind_0 = malloc(sizeof(int));
    ind_1 = malloc(sizeof(int));

    *ind_0 = 1;
    *ind_1 = 2;
    
    l->push(l, ind_1);
    l->push(l, ind_0);

    int *result = l->extract(l, 1);
    TEST_ASSERT(*result == 2);
    free(result);
    result = l->extract(l, 0);
    TEST_ASSERT(*result == 1);
    free(result);

    l->destroy(l);
}

void test_extract_out_of_bounds() {
    List *l = create_list();

    int *result = l->extract(l, 0);
    TEST_ASSERT(result == NULL);

    l->destroy(l);
}

void test_peek_of() {
    List *l = create_list();

    int *ind_0, *ind_1;
    ind_0 = malloc(sizeof(int));
    ind_1 = malloc(sizeof(int));

    *ind_0 = 1;
    *ind_1 = 2;
    
    l->push(l, ind_1);
    l->push(l, ind_0);

    int *result = l->peek_at(l, 0);
    TEST_ASSERT(*result == 1);
    result = l->peek_at(l, 1);
    TEST_ASSERT(*result == 2);
    result = l->peek_at(l, 2);
    TEST_ASSERT(result == NULL);

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
    RUN_TEST(test_remove_at_head);
    RUN_TEST(test_remove_at_tail);
    RUN_TEST(test_remove_out_of_bound);
    RUN_TEST(test_find_indexof);
    RUN_TEST(test_find_missing);
    RUN_TEST(test_extract);
    RUN_TEST(test_extract_out_of_bounds);
    RUN_TEST(test_peek_of);
    return 0;
}
