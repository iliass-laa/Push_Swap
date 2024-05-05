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

int b_to_a(int *stack_a, int *stack_b, int *size_a,int *size_b)
{
	int tot;

	tot = 0;
	while (*size_b >= 0)
	{
		tot += pa(stack_a, stack_b, size_a, size_b);
	}
	return (tot);
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

int smallB(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int i ,x, y, tot;

	i = 0;
	tot = 0;
	while (*size_a > 0)
	{
		// x = jibsghira(stack_a, *size_a);
		// y = x;
		// while ((*size_a - x) != 0)
		// 	{
		// 		tot += ra(stack_a, *size_a);
		// 		x ++;
		// 	}
		if (x >= *size_a / 2)
		{
			while ((*size_a - x) != 0)
			{
				tot += ra(stack_a, *size_a);
				x ++;
			}
		}
		else
		{
			while ( x > 0)
			{
				rra(stack_a, *size_a);
				tot++;
				x --;
			}
			rra(stack_a, *size_a);
			tot++;
		}
		tot += pb (stack_a, stack_b, size_a, size_b);
	}
	// tot += last_three(stack_a, &size_a);
	tot += b_to_a(stack_a, stack_b, size_a, size_b);
	return(tot);
}

// int push_swap(int *stack_a, int *stack_b, int *size_a, int *size_b)
// {
// 	int i, j, sa, sb, p;


	
// 	sa = *size_a;
// 	i = sa;
// 	// printf("II<<%d\n", i);
// 	while (i > 0)
// 	{
// 		j = i - 1;
// 		while (j >= 0)
// 		{
// 			// printf("i>>%d,v %d,  j>> %d,v %d\n", i, stack_a[i], j, stack_a[j]);
// 			if (stack_a[i] > stack_a[j])
// 			{
// 				p = *size_a;
// 				l3iba_dlkhncha_dskar(stack_a, stack_b, size_a, size_b);
				
// 				// printf("ana hna f i <%d <<stack %d ,j %d, stack<J> %d\n", i , stack_a[i], j , stack_a[j]);
// 				return(0);
// 			}
// 			j--;
// 		}
// 		i--;
// 	}
// 	return (1);
// }

// int main(int ac, char **av)
// {
// 	if (ac <= 1)
// 		return (0);
// 	int size_a = ac - 2;
// 	int size_b = -1;
// 	int sos;
// 	int i = 0;
// 	int stack_a[size_a];
// 	int	stack_b[size_a];
// 	valid_a(stack_a, size_a + 1 , av);
// 	sos = is_dub(stack_a, size_a);
// 	if (sos != 1)
// 	{
// 		printf("there is a dublicated number ! >> %d\n", sos);
// 		return (0);
// 	}
	
// 	// pb(stack_a, stack_b, &size_a, &size_b);
// 	// pb(stack_a, stack_b, &size_a, &size_b);
// 	// pb(stack_a, stack_b, &size_a, &size_b);
	

// 	int x,y;
// 	x = size_a;
// 	y = size_b; 
// 	// while (x >= 0)
// 	// {
// 	// 	printf("A>>%d,index>> %d \n", stack_a[x], x);
// 	// 	x --;
// 	// }
// 	int z =  smallB(stack_a, stack_b, &size_a, &size_b);
// 	x = size_a;
// 	// while (x >= 0)
// 	// {
// 	// 	printf("A>>%d,index>> %d \n", stack_a[x], x);
// 	// 	x --;
// 	// }
// 	// printf("number of moves >>%d\n", z);


// 	3
// 	// printf("-------------\n");
// 	// while (y >= 0)
// 	// {
// 	// 	printf("B>>%d , index>>%d\n", stack_b[y], y);
// 	// 	y --;
// 	// }
// 	// // rr(stack_a, stack_b, size_a, size_b);
// 	// x = size_a;
// 	// y = size_b; 
// 	// while (x >= 0)
// 	// {
// 	// 	printf("A>>%d,index>> %d \n", stack_a[x], x);
// 	// 	x --;
// 	// }
// 	// printf("-------------\n");
// 	// while (y >= 0)
// 	// {
// 	// 	printf("B>>%d , index>>%d\n", stack_b[y], y);
// 	// 	y --;
// 	// }
// }
