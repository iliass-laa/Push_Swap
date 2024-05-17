/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:43:06 by ilaasri           #+#    #+#             */
/*   Updated: 2024/05/17 17:43:09 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_sort(int nbr, int *stack_tmp, int size)
{
	while (size-- > 0)
	{
		if (stack_tmp[size] == nbr)
			return (size);
	}
	return (-1);
}

void	a_to_b(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	t_tap	x;

	x.start = 0;
	x.stack_tmp = (int *)malloc(sizeof(int) * (*size_a));
	if (*size_a < 40 && *size_a > 10)
		x.max = 7;
	if (*size_a <= 100 && *size_a >= 40)
		x.max = 15;
	else if (*size_a > 100)
		x.max = 30;
	else
		x.max = 3;
	x.size = *size_a;
	sort_tmp(*stack_a, x.stack_tmp, *size_a);
	a_to_b_season_two(stack_a, stack_b, size_a, size_b, &x);
	
}

void	b_back_to_a(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	int	moy;
	int	i;

	while (*size_b > 0)
	{
		moy = *size_b / 2;
		i = get_bigone_index(*stack_b, *size_b);
		if (moy == 0)
			pa(stack_a, stack_b, size_a, size_b);
		else if (i >= moy)
		{
			while (i++ < *size_b - 1)
				rb(*stack_b, *size_b);
			pa(stack_a, stack_b, size_a, size_b);
		}
		else
		{
			while (i-- >= 0)
				rrb(stack_b, *size_b);
			pa(stack_a, stack_b, size_a, size_b);
		}
	}
}

void	algo_nd_stuff(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	if (is_it_sorted(*stack_a, *size_a) != 1)
	{
		a_to_b(stack_a, stack_b, size_a, size_b);
		b_back_to_a(stack_a, stack_b, size_a, size_b);
	}
}

void	a_to_b_season_two(int **stack_a, int **stack_b, int *size_a, int *size_b, t_tap *x)
{
	while (*size_a > 0)
	{
		x->index_sorted = get_index_sort((*stack_a)[*size_a - 1], x->stack_tmp,
				x->size);
		if (x->index_sorted >= 0)
		{
			if (x->index_sorted >= x->start && x->index_sorted <= x->max)
			{
				pb(stack_a, stack_b, size_a, size_b);
				x->max++;
				x->start++;
			}
			else if (x->index_sorted < x->start)
			{
				pb(stack_a, stack_b, size_a, size_b);
				rb(*stack_b, *size_b);
				x->max++;
				x->start++;
			}
			else if (x->index_sorted > x->max)
				ra(*stack_a, *size_a);
		}
	}
	free(x->stack_tmp);
}