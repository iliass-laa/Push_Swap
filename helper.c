#include "push_swap.h"


int is_it_sorted(int *stack, int size)
{
    int i;

    i= 0;
    while (i < size - 1)
    {
        if (stack[i] < stack[i + 1])
            return(0);
        i++;
    }
    return(1);
}

int is_it_rev_sorted(int *stack, int size)
{
    int i;

    i= 0;
    while (i < size - 1)
    {
        if (stack[i] > stack[i + 1])
            return(0);
        i++;
    }
    return(1);
}

void rev_sort_handler(int **stack_a , int **stack_b, int *size_a, int *size_b)
{
    while (*size_a)
    {
        rra(stack_a, *size_a);
        pb(stack_a, stack_b, size_a, size_b);
    }
    while (*size_b)
        pa(stack_a, stack_b, size_a, size_b);

}