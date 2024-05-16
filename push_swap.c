#include "push_swap.h"

// int stack_len = 0;

void	valid_a(int	*stack_a, int size, char **av)
{
	int i;
	i= 0;
	while (size > 0)
	{
		stack_a[i] = atoi(av[size]);
		size --;
		i++;
	}
}

int is_dub(int *stack_a , int size)
{
	int i, j;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j <= size)
		{
			if (stack_a[i] == stack_a[j])
			{
				printf("duplicated nbr >>%d i>>%d, j<<%d\n", stack_a[i],i, j);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}


int jibsghira(int *stack_a, int size_a)
{
	int sghira;
	int i,j;
	sghira = stack_a[size_a];
	i = size_a;
	j = i;
	while (i >= 0)
	{
		if (sghira > stack_a[i])
		{
			sghira = stack_a[i];
			j = i;
		}
		i--;
	}
	return (j);
}



// int main(int ac, char **av)
// {
//     int *a = NULL;
//     int *b = NULL;
//     int size_a, i, x,j;

//     if (ac > 1)
//     {
//         a = parse_nd_fill(ac, av);
		
//         i = stack_len;
//         x = i;
//         j = 0;
// 		// if (is_it_sorted(a, x) != 1)
//         	algo_nd_stuff(&a, &b, &i, &j);
//         free(a);
//         // free(b);
//     }
// }