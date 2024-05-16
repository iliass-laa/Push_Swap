#include "push_swap.h"

// int     pa(int	*stack_a, int *stack_b, int *size_a, int *size_b)
// {
//     if (*size_b >= 0)
//     {
//         *size_a = *size_a + 1;
//         stack_a[*size_a] = stack_b[*size_b];
//         *size_b = *size_b - 1;
//         write(1, "pa\n", 3);
//         return(1);
//     }
//     return(0);
// }

// int     pb(int *stack_a, int *stack_b, int *size_a, int *size_b)
// {
//     if (*size_a > 0)
//     {

//         int x, y, chber;
//         x = *size_b;
//         *size_b = x + 1;
//         y = *size_a - 1;
//         printf("a>>%d, b>>%d\n", stack_a[y], stack_b[y]);

//         chber = stack_a[*size_a - 1];
//         stack_b[y] = chber;
//         *size_a -= 1;
//         printf("a>>%d, b>>%d\n", stack_a[y], stack_b[y]);
//         write(1, "pb\n", 3);
//         return (1);
//     }
//     // if (*size_a >= 0)
//     // {
//     //     int x, y;
//     //     x = *size_b + 1;
//     //     *size_b = x;
//     //     y = *size_a;
//     //     stack_b[x] = stack_a[y];   
//     //     *size_a = y - 1;
//     //     write(1, "pb\n", 3);
//     //     return (1);
//     // }
//     return(0);
// }

// int     pb(int *stack_a, int *stack_b, int *size_a, int *size_b)
// {
//     int i,j;
//     int *new_b;
//     i = *size_a - 1;
//     j = *size_b;
//     printf("JJJJJ>>>%d\n", j);
//     if (*size_a)
//     {
//         new_b = (int *)malloc(sizeof(int) * (j + 1));
//         if (j > 0)
//         {
//             clone_it(stack_b, new_b, j); 
//         }
//         free(stack_b);
//         new_b[j] = stack_a[i];
//         printf(">>>>>>>%d<<<<>>>%d><<<\n", stack_a[i], new_b[j]);
//         printf("before malloc >>b_add %p>>i>>\n", &(*stack_b));

//         stack_b = (int *)malloc(sizeof(int) * (j + 1));
//         printf("after malloc>>b_add %p>>i>>\n", &(*stack_b));

//         *size_b  = j +1;
//         clone_it(new_b, stack_b, *size_b);
//         printf(">>b_add %p>>i>>\n", &(*stack_b));

//         printf("stacckk_bbb>>>%d, jjj>>>>%d\n", stack_b[j], j);
//         *size_a = i;
//         free(new_b);
//         printf(">>69666b_add %p>>i>>\n", &(*stack_b));

//         // push_helper(stack_a, i);
//         // while ((j + 1)>0)
//         //     printf("new stack_b values >>%d\n", stack_b[j--]);
//         write(1, "pb\n", 3);
//     }
// }

void     pb(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
    int i,j;
    int *new_b;
    i = *size_a - 1;
    j = *size_b;
    if (*size_a)
    {
        new_b = (int *)malloc(sizeof(int) * (j + 1));
        if (j > 0)
        {
            // printf("I am cloning b to new one !\n");
            clone_it(*stack_b, new_b, j);
            free(*stack_b);
        }
        new_b[j] = (*stack_a)[i];
        *stack_b = (int *)malloc(sizeof(int) * (j + 1));
        *size_b  += 1;
        clone_it(new_b, *stack_b, j + 1);
        *size_a = i;
        free(new_b);
        push_helper(stack_a, i);
        write(1, "pb\n", 3);
    }
}

void     pa(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
    int i,j;
    int *new_a;
    i = *size_b - 1;
    j = *size_a;
    if (*size_b)
    {
        new_a = (int *)malloc(sizeof(int) * (j + 1));
        if (j > 0)
        {
            clone_it(*stack_a, new_a, j);
            free(*stack_a);
        }
        new_a[j] = (*stack_b)[i];
        *stack_a = (int *)malloc(sizeof(int) * (j + 1));
        *size_a  += 1;
        clone_it(new_a, *stack_a, j + 1);
        *size_b = i;
        free(new_a);
        push_helper(stack_b, i);
        write(1, "pa\n", 3);
    }
}


void push_helper(int **stack, int new_size)
{
    int *tmp;
    if (new_size == 0)
    {
        free(*stack);
        return;
    }
    tmp = (int *)malloc(sizeof(int) * new_size);
    clone_it(*stack, tmp, new_size);
    free(*stack);
    *stack = (int *)malloc(sizeof(int) * new_size);
    clone_it(tmp, *stack, new_size);
    free(tmp);
}


void    rra(int **stack_a, int size_a)
{
    int i;
    int chber;

    i = 0;
    chber = (*stack_a)[0];
    if (size_a > 0)
    {
        while (i < size_a - 1)
        {
            (*stack_a)[i] = (*stack_a)[i + 1];
            i++;   
        }
        (*stack_a)[size_a - 1] = chber;
        write(1, "rra\n", 4);

    }
}

void    rrb(int **stack_b, int size_b)
{
    int i;
    int chber;

    i = 0;
    chber = (*stack_b)[0];
    if (size_b > 0)
    {
        while (i < size_b - 1)
        {
            (*stack_b)[i] = (*stack_b)[i + 1];
            i++;   
        }
        (*stack_b)[size_b - 1] = chber;
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





// void pull_helper(int *stack, int new_size)
// {
//     int *tmp;

//     tmp = (int *)malloc(sizeof(int) * new_size);
//     clone_it(stack, tmp, new_size);
//     free(stack);
//     stack = (int *)malloc(sizeof(int) * new_size);
//     clone_it(tmp, stack, new_size);
//     free(tmp);
// }