#include "push_swap.h"

void	freedom(char *s, char **res, int i)
{
	free(s);
	while (i-- > 0)
		free(res[i]);
	free(res);
}

void	error_mf(void)
{
	write(2, "Error\n", 6);
	exit(2);
}

char	*ft_strjoin_space(char *s1, char *s2)
{
	char	*res;
	int		s1len;
	int		s2len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	res = (char *)malloc(s1len + s2len + 2);
	if (!res)
		return (free(s1), NULL);
	while (i < s1len)
	{
		res[i] = s1[i];
		i++;
	}
	if (i > 0)
		res[i++] = 32;
	while (i <= s1len + s2len)
		res[(i++)] = s2[j++];
	res[i] = 0;
	return (free(s1), res);
}
