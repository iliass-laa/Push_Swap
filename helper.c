/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:42:19 by ilaasri           #+#    #+#             */
/*   Updated: 2024/05/17 17:42:21 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_it_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	if (size == 1)
		return (1);
	while (i < size - 1)
	{
		if (stack[i] < stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_it_rev_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	if (size > 1)
	{
		while (i < size - 1)
		{
			if (stack[i] > stack[i + 1])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	clone_it(int *stack_a, int *stack_tmp, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack_tmp[i] = stack_a[i];
		i++;
	}
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_tmp(int *stack_a, int *stack_tmp, int size)
{
	int	i;
	int	j;

	i = 0;
	clone_it(stack_a, stack_tmp, size);
	while (is_it_sorted(stack_tmp, size) != 1)
	{
		while (i < size - 1)
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
