#include "push_swap.h"

int     pa(int	*stack_a, int *stack_b, int *size_a, int *size_b)
{
    if (*size_b >= 0)
    {
        *size_a = *size_a + 1;
        stack_a[*size_a] = stack_b[*size_b];
        *size_b = *size_b - 1;
        write(1, "pa\n", 3);
        return(1);
    }
    return(0);
}

int     pb(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
    if (*size_a >= 0)
    {
        int x, y;
        x = *size_b + 1;
        *size_b = x;
        y = *size_a;
        stack_b[x] = stack_a[y];   
        *size_a = y - 1;
        write(1, "pb\n", 3);
        return (1);
    }
    return(0);
}

void    rra(int *stack_a, int size_a)
{
    int i;
    int chber;

    i = 0;
    chber = stack_a[0];
    if (size_a > 0)
    {
        while (i < size_a)
        {
            stack_a[i] = stack_a[i + 1];
            i++;   
        }
        stack_a[size_a] = chber;
        write(1, "rra\n", 4);

    }
}

void    rrb(int *stack_b, int size_b)
{
    int i;
    int chber;

    i = 0;
    chber = stack_b[0];
    if (size_b > 0)
    {
        while (i < size_b)
        {
            stack_b[i] = stack_b[i + 1];
            i++;   
        }
        stack_b[size_b] = chber;
        write(1, "rrb\n", 4);

    }
}

void    rrr(int *stack_a, int *stack_b, int size_a, int size_b)
{
     int i;
    int chber;

    if (size_b > 0 && size_a > 0)
    {
        i = 0;
        chber = stack_b[0];
        while (i < size_b)
        {
            stack_b[i] = stack_b[i + 1];
            i++;   
        }
        stack_b[size_b] = chber;
        i = 0;
        chber = stack_a[0];
        while (i < size_a)
        {
            stack_a[i] = stack_a[i + 1];
            i++;   
        }
        stack_a[size_a] = chber;
        write(1, "rrr\n", 4);
    }
}
