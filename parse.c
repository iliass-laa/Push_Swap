/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:43:18 by ilaasri           #+#    #+#             */
/*   Updated: 2024/05/17 17:43:19 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_there_a_num(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 48 && s[i] <= 57)
			return (1);
		i++;
	}
	return (0);
}

char	*args_tg(char **av, int n_arg)
{
	char	*res;
	int		i;

	i = 1;
	res = NULL;
	while (i < n_arg)
	{
		if (is_there_a_num(av[i]) == 0)
			return (NULL);
		res = ft_strjoin_space(res, av[i++]);
	}
	return (res);
}

int	is_it_valid_arg(char *s)
{
	int	i;

	i = 0;
	if (ft_strlen(s) == 0)
		return (0);
	if (s)
	{
		while (s[i] && ((s[i] <= 57 && s[i] >= 48) || s[i] == 45 || s[i] == 43
				|| s[i] == 32))
		{
			if ((s[i] == 43 || s[i] == 45) && (s[i + 1] < 48 || s[i + 1] > 57))
				return (0);
			if (s[i] == 43 || s[i] == 45)
			{
				if (i > 0)
					if (s[i - 1] >= 48 && s[i - 1] <= 57)
						return (0);
			}
			i++;
		}
		if (i == ft_strlen(s))
			return (1);
	}
	return (0);
}

int	fill_stack_a(char **s, int *stack_a, int slen, int *v)
{
	int	i;
	int	len;

	i = 0;
	len = slen;
	while (len-- > 0)
	{
		stack_a[i++] = ft_atoi(s[len], v);
		free(s[len]);
	}
	return (free(s), i);
}

int	*parse_nd_fill(int ac, char **av, int *i)
{
	char	*arg_str;
	int		*stack_a;
	char	**args_sep;
	int		v;

	v = 1;
	stack_a = NULL;
	arg_str = args_tg(av, ac);
	*i = count_nbrs_str(arg_str);
	if (is_it_valid_arg(arg_str) != 1)
		return (NULL);
	args_sep = split_nbr(arg_str);
	stack_a = (int *)malloc(sizeof(int) * (*i));
	if (NULL == stack_a)
		return (NULL);
	fill_stack_a(args_sep, stack_a, *i, &v);
	if (v == -1)
		return (NULL);
	return (stack_a);
}
