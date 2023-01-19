#include "push_swap.h"

void test_function(int *stack_a, int *stack_b, int argc, int size_b)
{
    int i = 4;
    printf ("******************************\n");
    while (i >= 0)
    {
        printf ("%d| ----------+%d | --------+%d |\n", i, stack_a[i], stack_b[i]);
        i--;
    }
    printf ("******************************\n");
}