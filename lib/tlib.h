#ifndef TLIB_H
#define TLIB_H
#include <stdio.h>
#include <stdlib.h>
#include "../includes/ll.h"

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define WHITE   "\033[1:37m"

#define RESET   "\033[0m"

#define BG_BLACK "\033[40m" 
#define BG_GREEN "\33[42m"

#define TEST_ASSERT_INT_EQ(expected, got) \
                    do {\
                        if (expected != got) {\
                            printf(BG_BLACK RED "[FAILED]" RESET " %s:%d\tExpected: %d => Got: %d\n", __FILE__, __LINE__, expected, got);\
                            exit(1);\
                         };\
                    } while(0)





#define TEST_ASSERT(cond) \
                    do {\
                        if (!cond) {\
                            printf(BG_BLACK RED "[FAILED]" RESET " %s:%d\tExpected: %d => Got: %d\n", __FILE__, __LINE__, true, false);\
                            exit(1);\
                         };\
                    } while(0)




#define RUN_TEST(test) do {\
                         printf("Running: %-25.25s | ", #test);\
                         test();\
                         printf(BG_GREEN WHITE "[PASSED]" RESET " <%s()>\n", #test);\
                       } while(0)

#endif
