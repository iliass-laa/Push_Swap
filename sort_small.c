/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:56:33 by ilaasri           #+#    #+#             */
/*   Updated: 2024/05/18 13:56:34 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(int *stack_a)
{
	if (is_it_sorted(stack_a, 2) != 1)
		sa(stack_a, 2);
}

int	tree_sort(int **a, int **b, int *i, int *j)
{
	int	x;

	x = jibsghira(*a, 3);
	if (is_it_rev_sorted(*a, 3) == 1 || (x == 1 && ((*a)[0] > (*a)[2])))
	{
		sa(*a, 3);
		if (x == 1)
			return (0);
		rra(a, 3);
	}
	else
	{
		if (x == 0)
			return (rra(a, 3), 0);
		else if (x == 1)
			return (ra(*a, 3), 0);
		pb(a, b, i, j);
		sort_two(*a);
		pa(a, b, i, j);
	}
	return (0);
}

void	sort_four(int **a, int **b, int *i, int *j)
{
	int	x;

	x = jibsghira(*a, 4);
	if (x == 2)
		ra(*a, 4);
	else if (x < 2)
	{
		while (x >= 0)
		{
			rra(a, 4);
			x--;
		}
	}
	pb(a, b, i, j);
	tree_sort(a, b, i, j);
	pa(a, b, i, j);
}

void	sort_five(int **a, int **b, int *i, int *j)
{
	int	x;

	x = jibsghira(*a, 5);
	if (x < 2)
	{
		while (x >= 0)
		{
			rra(a, 5);
			x--;
		}
	}
	else
	{
		while (x < 4)
		{
			ra(*a, 5);
			x++;
		}
	}
	pb(a, b, i, j);
	sort_four(a, b, i, j);
	pa(a, b, i, j);
}

void	treat_small(int **a, int **b, int *i, int *j)
{
	if (is_it_sorted(*a, *i) != 1)
	{
		if (*i == 2)
			sort_two(*a);
		else if (*i == 3)
			tree_sort(a, b, i, j);
		else if (*i == 4)
			sort_four(a, b, i, j);
		else if (*i == 5)
			sort_five(a, b, i, j);
	}
	return ;
}
