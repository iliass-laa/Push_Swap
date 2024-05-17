/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:42:35 by ilaasri           #+#    #+#             */
/*   Updated: 2024/05/17 17:42:37 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bigone_index(int *stack, int size)
{
	int	i;
	int	tmp;
	int	res;

	tmp = stack[0];
	i = 0;
	res = 0;
	if (size > 0)
	{
		if (size == 1)
			return (0);
		while (i < size)
		{
			if (tmp < stack[i])
			{
				tmp = stack[i];
				res = i;
			}
			i++;
		}
	}
	return (res);
}

void	valid_a(int *stack_a, int size, char **av)
{
	int	i;

	i = 0;
	while (size > 0)
	{
		stack_a[i] = atoi(av[size]);
		size--;
		i++;
	}
}

int	is_dub(int *stack_a, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack_a[i] == stack_a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	jibsghira(int *stack_a, int size_a)
{
	int	sghira;
	int	i;
	int	j;

	sghira = stack_a[size_a - 1];
	i = size_a - 1;
	j = i;
	while (i-- > 0)
	{
		if (sghira > stack_a[i])
		{
			sghira = stack_a[i];
			j = i;
		}
	}
	return (j);
}

int	main(int ac, char **av)
{
	int	*a;
	int	*b;
	int	i;
	int	j;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		a = parse_nd_fill(ac, av, &i);
		if (!a)
			error_mf();
		if (is_dub(a, i) == 0)
			error_mf();
		j = 0;
		if (i <= 5)
			treat_small(&a, &b, &i, &j);
		else
			algo_nd_stuff(&a, &b, &i, &j);
		free(a);
	}
}
