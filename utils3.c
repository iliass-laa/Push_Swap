/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 22:04:18 by ilaasri           #+#    #+#             */
/*   Updated: 2024/05/17 22:04:23 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	i;
	int	chber;

	if (size_b > 0 && size_a > 0)
	{
		i = 0;
		chber = stack_b[0];
		while (i < size_b)
		{
			stack_b[i] = stack_b[i + 1];
			i++;
		}
		stack_b[size_b] = chber;
		i = 0;
		chber = stack_a[0];
		while (i < size_a)
		{
			stack_a[i] = stack_a[i + 1];
			i++;
		}
		stack_a[size_a] = chber;
		write(1, "rrr\n", 4);
	}
}

void	rr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	s;
	int	i;
	int	j;

	i = size_b;
	j = size_a;
	s = stack_b[i];
	if (i > 0 && j > 0)
	{
		while (i > 0)
		{
			stack_b[i] = stack_b[i - 1];
			i--;
		}
		stack_b[i] = s;
		s = stack_a[j];
		while (j > 0)
		{
			stack_a[j] = stack_a[j - 1];
			j--;
		}
		stack_a[j] = s;
		write(1, "rr\n", 3);
	}
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

int	ft_atoi(const char *str, int *v)
{
	long long	res;
	int			i;
	int			sign;
	long long	tmp;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == 45)
		sign *= -1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		tmp = res;
		res = res * 10 + (str[i++] - 48);
	}
	res *= sign;
	if (res < -2147483648 || res > 2147483647)
		*v = -1;
	return (res);
}
