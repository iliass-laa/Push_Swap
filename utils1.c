#include "push_swap.h"

void    sa(int *stack_a, int size)
{
	int s;
	s = stack_a[size ];
	stack_a[size] = stack_a[size - 1];
	stack_a[size - 1] = s;
    write(1, "sa\n", 3);
}

void    sb(int *stack_b, int size)
{
	int s;
	s = stack_b[size];
    if (size > 0)
    {
        stack_b[size]  = stack_b[size - 1];
    	stack_b[size - 1] = s;
        write(1, "sb\n", 3);
    }
}

void    ss(int *stack_a , int *stack_b , int size_a, int size_b)
{
	int s;
	
	if (size_b > 0 && size_a > 0)
    {
        s = stack_a[size_a];
        stack_a[size_a] = stack_a[size_a - 1];
        stack_a[size_a - 1] = s;
        s = stack_a[size_b];
        stack_b[size_b]  = stack_b[size_b - 1];
    	stack_b[size_b - 1] = s;
        write(1, "ss\n", 3);
    }
}

int    ra(int	*stack_a, int size_a)
{
    int s;
    int i = size_a;
    s = stack_a[i];
    if (i > 0)
    {
        while (i > 0)
        {
            stack_a[i] = stack_a[i - 1];
            i --; 
        }
        stack_a[i] = s;
        write(1,"ra\n", 3);
        return(1);
    }
    else
        printf("u need at least two elements in the stack !\n");
    return(0);
}

void    rb(int	*stack_b, int size_b)
{
    int s;
    int i = size_b;
    s = stack_b[i];
    if (i > 0)
    {
         while (i > 0)
        {
            stack_b[i] = stack_b[i - 1];
            i --; 
        }
        stack_b[i] = s;
        write(1, "rb\n", 3);
    }
    // else
    //     printf("u need at least two elements in the stack !\n");
}

void    rr(int	*stack_a, int *stack_b, int size_a, int size_b)
{
    int s;
    int i = size_b;
    int j = size_a;
    s = stack_b[i];
    if (i > 0 && j > 0)
    {
         while (i > 0)
        {
            stack_b[i] = stack_b[i - 1];
            i --; 
        }
        stack_b[i] = s;
        s = stack_a[j];
         while (j > 0)
        {
            stack_a[j] = stack_a[j - 1];
            j --; 
        }
        stack_a[j] = s;
        write(1,"rr\n", 3);
    }
}