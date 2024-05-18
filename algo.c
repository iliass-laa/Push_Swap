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

void	a_to_b(t_stacks *y)
{
	t_tap	x;

	x.start = 0;
	x.stack_tmp = (int *)malloc(sizeof(int) * (y->i));
	if (y->i < 40 && y->i > 10)
		x.max = 7;
	if (y->i <= 100 && y->i >= 40)
		x.max = 15;
	else if (y->i > 100)
		x.max = 30;
	else
		x.max = 3;
	x.size = y->i;
	sort_tmp(y->a, x.stack_tmp, y->i);
	a_to_b_season_two(y, &x);
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

void	algo_nd_stuff(t_stacks *y)
{
	if (is_it_sorted(y->a, y->i) != 1)
	{
		a_to_b(y);
		b_back_to_a(&(y->a), &(y->b), &(y->i), &(y->j));
	}
}

void	a_to_b_season_two(t_stacks *y, t_tap *x)
{
	while (y->i > 0)
	{
		x->index_sorted = get_index_sort((y->a)[y->i - 1], x->stack_tmp,
				x->size);
		if (x->index_sorted >= 0)
		{
			if (x->index_sorted >= x->start && x->index_sorted <= x->max)
			{
				pb(&(y->a), &(y->b), &(y->i), &(y->j));
				x->max++;
				x->start++;
			}
			else if (x->index_sorted < x->start)
			{
				pb(&(y->a), &(y->b), &(y->i), &(y->j));
				rb(y->b, y->j);
				x->max++;
				x->start++;
			}
			else if (x->index_sorted > x->max)
				ra(y->a, y->i);
		}
	}
	free(x->stack_tmp);
}
