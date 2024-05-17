/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:44:00 by ilaasri           #+#    #+#             */
/*   Updated: 2024/05/17 17:44:02 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	int	*new_b;
	int	i;
	int	j;

	i = *size_a - 1;
	j = *size_b;
	if (*size_a)
	{
		new_b = (int *)malloc(sizeof(int) * (j + 1));
		if (j > 0)
		{
			clone_it(*stack_b, new_b, j);
			free(*stack_b);
		}
		new_b[j] = (*stack_a)[i];
		*stack_b = (int *)malloc(sizeof(int) * (j + 1));
		*size_b += 1;
		clone_it(new_b, *stack_b, j + 1);
		*size_a = i;
		free(new_b);
		push_helper(stack_a, i);
		write(1, "pb\n", 3);
	}
}

void	pa(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	int	*new_a;
	int	i;
	int	j;

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
		*size_a += 1;
		clone_it(new_a, *stack_a, j + 1);
		*size_b = i;
		free(new_a);
		push_helper(stack_b, i);
		write(1, "pa\n", 3);
	}
}

void	push_helper(int **stack, int new_size)
{
	int	*tmp;

	if (new_size == 0)
	{
		free(*stack);
		return ;
	}
	tmp = (int *)malloc(sizeof(int) * new_size);
	clone_it(*stack, tmp, new_size);
	free(*stack);
	*stack = (int *)malloc(sizeof(int) * new_size);
	clone_it(tmp, *stack, new_size);
	free(tmp);
}

void	rra(int **stack_a, int size_a)
{
	int	i;
	int	chber;

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

void	rrb(int **stack_b, int size_b)
{
	int	i;
	int	chber;

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
