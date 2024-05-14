#include "push_swap.h"


void clone_it(int *stack_a, int *stack_tmp, int size)
{
    int i = 0;
    
    while (i < size)
    {
        // printf("ALO >>%d\n", stack_a[i]);
        stack_tmp[i] = stack_a[i];
        i++;
    }
}

void ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort_tmp(int *stack_a, int *stack_tmp, int size)
{
    int i = 0;
    int j;

    clone_it(stack_a, stack_tmp, size);
    while ( is_it_sorted(stack_tmp, size) != 1)
    {
        while(i < size - 1)
        {
            j = i + 1;
            while (j < size)
            {
                if (stack_tmp[i] < stack_tmp[j])
                    ft_swap(&stack_tmp[i], &stack_tmp[j]);
                j++;
            }
            j = 0;
            i++;
        }
        i = 0;
    }
}

int get_index_sort(int nbr, int *stack_tmp, int size)
{
    int i = 0;
    while (size-- > 0)
    {
        if (stack_tmp[size] == nbr)
            return (size);
    }
    return(-1);
}

void a_to_b(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
    int i,  size ;
    int start;
    int max;
    int index_sorted;
    int stack_tmp[*size_a];

    start = 0;
    if (*size_a < 40 && *size_a > 10)
        max = 7;
    if(*size_a < 100 && *size_a >= 40)
        max = 15;
    else if (*size_a >= 100)
        max = 30;
    else
        max = 3;

    
    size = *size_a;
    i = *size_a - 1;
    sort_tmp(*stack_a, stack_tmp, *size_a);
    // int j;
    // j = *size_a;
    // while (j-->0)
    //     printf("stack_tmp[%d]=%d\n", j, stack_tmp[j]);
    while (*size_a > 0)
    {
        
        // i = *size_a - 1;
        index_sorted = get_index_sort((*stack_a)[*size_a - 1], stack_tmp, size);
        // printf("i >> %d, Value>> %d, sorted index %d\n", *size_a - 1, (*stack_a)[*size_a - 1], index_sorted);
        // printf("start >> %d, max>> %d\n", start, max);
        if (index_sorted >= 0)
        {
            if (index_sorted >= start && index_sorted <= max)
            {
                pb(stack_a, stack_b, size_a, size_b);
                max ++;
                start ++;
            }
            else if (index_sorted < start)
            { 
                pb(stack_a, stack_b, size_a, size_b);
                rb(*stack_b, *size_b);
                max ++;
                start ++;
            }
            else if (index_sorted > max)
            {
                ra(*stack_a, *size_a );
            }
        }
        
    }

}

int get_bigone_index(int *stack, int size)
{
    int i;
    int tmp;
    int res;

    tmp = 0;
    i = 0; 
    res = 0;
    if (size > 0)
    {
        while (i < size )
        {
            if (tmp < stack[i ])
            {
                tmp = stack[i];
                res = i;
            }
            i++;
        }
    }
    return (res);
}

void b_back_to_a(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
    int moy, i;

//    printf("B back to A\n");
    while (*size_b > 0)
    {
        moy = *size_b / 2;
        i = get_bigone_index(*stack_b,*size_b);
        // printf("stack_b[%d]=%d|||| moy = %dm size_b = %d\n" ,i, (*stack_b)[i], moy, *size_b);
        if (moy == 0)
            pa(stack_a, stack_b, size_a, size_b);
        else if (i >= moy)
        {
            while (i < *size_b - 1)
            {
                rb(*stack_b, *size_b);
                i++;
            }
            // printf("rb i am pushing to a in pos %d >> %d\n", *size_b - 1, (*stack_b)[*size_b - 1]);
            pa(stack_a, stack_b, size_a, size_b);

        }
        else
        {
            while (i >= 0)
            {
                rrb(stack_b, *size_b);
                i--;
            }
            // printf("rrb i am pushing to a in pos %d >> %d\n", *size_b - 1, (*stack_b)[*size_b - 1]);
            pa(stack_a, stack_b, size_a, size_b);
        }
    }
}

void algo_nd_stuff(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
    a_to_b(stack_a, stack_b, size_a, size_b);
    // printf(">>b size :%d<<size_a : %d\n", *size_b, *size_a);
    b_back_to_a(stack_a, stack_b, size_a, size_b);
    // printf(">>b size :%d<<size_a : %d\n", *size_b, *size_a);

}
