#include "push_swap.h"


// void sort_c(int *stack_a, int *stack_sorted, int size)
// {
//     int i = 0;
//     int tmp;

//     tmp = stack_a[i];
//     while (is_it_sorted(stack_sorted, size) == 0)
//     {
//         tmp = jibsghira(stack_a, size);
//         while (i < size)
//         {
//             if ()
//             i++;
//         }
//     }
//     // if (is_it_sorted(stack_a, size) == 1)
//         return;


// }


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

// int main()
// {
//     int stack[6] = {99, 54, 3,2 ,1, 96 };
//     printf("%d, %d\n", jibsghira(stack, 5), stack[5]);
// }