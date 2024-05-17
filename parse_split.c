/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:44:21 by ilaasri           #+#    #+#             */
/*   Updated: 2024/05/17 17:44:23 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_nbrs_str(char *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (s)
	{
		while (s[i])
		{
			if ((s[i] >= 48 && s[i] <= 57) && (s[i + 1] < 48 || s[i + 1] > 57))
				res++;
			i++;
		}
	}
	return (res);
}

char	*ft_strdup(char *s, int start, int len)
{
	int		reslen;
	int		slen;
	int		i;
	char	*res;

	reslen = len;
	i = 0;
	slen = ft_strlen(s);
	if (start + len >= slen)
		reslen = slen - start;
	if (start >= slen)
		return (NULL);
	res = (char *)malloc(reslen + 1);
	if (!res)
		return (NULL);
	while (i < reslen)
		res[i++] = s[start++];
	res[i] = 0;
	return (res);
}

int	find_start(char *s, int i)
{
	while (s[i])
	{
		if ((s[i] >= 48 && s[i] <= 57) || ((s[i] == 45 || s[i] == 43) && (s[i
					+ 1] >= 48 && s[i + 1] <= 57)))
			return (i);
		i++;
	}
	return (i);
}

int	find_end(char *s, int i)
{
	while (s[i] && ((s[i] >= 48 && s[i] <= 57) || ((s[i] == 45 || s[i] == 43)
				&& (s[i + 1] >= 48 && s[i + 1] <= 57))))
		i++;
	return (i);
}

char	**split_nbr(char *s)
{
	int		i;
	int		nbr_str;
	int		start;
	int		end;
	char	**res;

	i = 0;
	nbr_str = count_nbrs_str(s);
	res = (char **)malloc(sizeof(char *) * (nbr_str + 1));
	if (!res)
		return (free(s), NULL);
	end = 0;
	while (i < nbr_str)
	{
		start = find_start(s, end);
		end = find_end(s, start);
		res[i] = ft_strdup(s, start, (end - start));
		if (res[i] == NULL)
			return (freedom(s, res, i), NULL);
		i++;
	}
	res[i] = NULL;
	return (free(s), res);
}
