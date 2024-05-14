#include "push_swap.h"

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

// int b_to_a(int *stack_a, int *stack_b, int *size_a,int *size_b)
// {
// 	int tot;

// 	tot = 0;
// 	while (*size_b > 0)
// 	{
// 		tot += pa(stack_a, stack_b, size_a, size_b);
// 	}
// 	return (tot);
// }

// int next_smallest(int *stack_a, int size, int nbr)
// {
// 	int res;

// 	res = 0;
// 	if (size > 0)
// 	{
// 		while (size -- > 0)
// 		{
// 			if (stack_a[size] > nbr  && stack_a[size] < stack_a[size - 1])
// 			{
// 				res = stack_a[size];
// 				printf("size>>%d | res >> %d\n	",size, res);
// 			}
// 		}
// 	}
// 	return (res);
// }

// int jibsghira(int *stack_a, int size_a)
// {
// 	int sghira;
// 	int i,j;
// 	sghira = stack_a[size_a];
// 	i = size_a;
// 	j = i;
// 	while (i >= 0)
// 	{
// 		if (sghira > stack_a[i])
// 		{
// 			sghira = stack_a[i];
// 			j = i;
// 		}
// 		i--;
// 	}
// 	return (j);
// }

// int smallB(int *stack_a, int *stack_b, int *size_a, int *size_b)
// {
// 	int i ,x, y, tot;

// 	i = 0;
// 	tot = 0;
// 	while (*size_a > 0)
// 	{
// 		x = jibsghira(stack_a, *size_a);
// 		// y = x;
// 		while ((*size_a - x) != 0)
// 		{
// 			tot += ra(stack_a, *size_a);
// 			x ++;
// 		}
// 		// if (x >= *size_a / 2)
// 		// {
// 		// 	while ((*size_a - x) != 0)
// 		// 	{
// 		// 		tot += ra(stack_a, *size_a);
// 		// 		x ++;
// 		// 	}
// 		// }
// 		// else
// 		// {
// 		// 	while ( x > 0)
// 		// 	{
// 		// 		rra(stack_a, *size_a);
// 		// 		tot++;
// 		// 		x --;
// 		// 	}
// 		// 	rra(stack_a, *size_a);
// 		// 	tot++;
// 		// }
// 		tot += pb (stack_a, stack_b, size_a, size_b);
// 		printf("size_a >>%d, tot>>%d\n", *size_a, tot);

// 	}
// 	printf("alllloooo\n");

// 	// tot += b_to_a(stack_a, stack_b, size_a, size_b);
// 	return(tot);
// }

// int main(int ac, char **av)
// {
// 	if (ac <= 1)
// 		return (0);
// 	int size_a;
	
// 	int size_b;
	
// 	int sos;
// 	int i = 0;
// 	size_a = ac - 1;
// 	size_b = 0;
// 	int stack_a[size_a];
// 	int	stack_b[size_b];
// 	valid_a(stack_a, size_a , av);
// 	sos = is_dub(stack_a, size_a);
// 	if (sos != 1)
// 	{
// 		printf("there is a dublicated number ! >> %d\n", sos);
// 		return (0);
// 	}
	
// 	pb(stack_a, stack_b, &size_a, &size_b);
// 	pb(stack_a, stack_b, &size_a, &size_b);
// 	// pb(stack_a, stack_b, &size_a, &size_b);
	

// 	int x,y;
// 	x = size_a - 1;
// 	y = size_b - 1; 
// 	while (x >= 0)
// 	{
// 		printf("A>>%d,index>> %d \n", stack_a[x], x);
// 		x --;
// 	}
// 	printf("-------\n");
// 	while (y >= 0)
// 	{
// 		printf("B>>%d,index>> %d \n", stack_a[y], y);
// 		y --;
// 	}
// 	// printf("44444>>%d\n", size_a);
// 	// int z =  smallB(stack_a, stack_b, &size_a, &size_b);

	
// 	// while (x >= 0)
// 	// {
// 	// 	printf("A>>%d,index>> %d \n", stack_a[x], x);
// 	// 	x --;
// 	// }
// 	// printf("number of moves >>%d\n", z);
// 	// }
// }
