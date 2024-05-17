/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:42:58 by ilaasri           #+#    #+#             */
/*   Updated: 2024/05/17 17:43:00 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *stack_a, int size)
{
	if (size > 1)
	{
		ft_swap(&stack_a[size - 2], &stack_a[size - 1]);
		write(1, "sa\n", 3);
	}
}

void	sb(int *stack_b, int size)
{
	if (size > 1)
	{
		ft_swap(&stack_b[size - 2], &stack_b[size - 1]);
		write(1, "sb\n", 3);
	}
}

void	ss(int *stack_a, int *stack_b, int size_a, int size_b)
{
	if (size_b > 1 && size_a > 1)
	{
		ft_swap(&stack_a[size_a - 2], &stack_a[size_a - 1]);
		ft_swap(&stack_b[size_b - 2], &stack_b[size_b - 1]);
		write(1, "ss\n", 3);
	}
}

int	ra(int *stack_a, int size_a)
{
	int	s;
	int	i;

	i = size_a - 1;
	s = stack_a[i];
	if (i >= 0)
	{
		while (i > 0)
		{
			stack_a[i] = stack_a[i - 1];
			i--;
		}
		stack_a[i] = s;
		write(1, "ra\n", 3);
		return (1);
	}
	return (0);
}

void	rb(int *stack_b, int size_b)
{
	int	s;
	int	i;

	i = size_b - 1;
	s = stack_b[i];
	if (i >= 0)
	{
		while (i > 0)
		{
			stack_b[i] = stack_b[i - 1];
			i--;
		}
		stack_b[i] = s;
		write(1, "rb\n", 3);
	}
}
