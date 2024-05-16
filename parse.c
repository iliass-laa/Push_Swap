#include "push_swap.h"

// int stack_len;

int ft_strlen(char *s)
{
    int i = 0;
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
	int		i;
	int		sign;
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

char *ft_strjoin_space(char *s1, char *s2)
{
    char *res;
    int s1len;
    int s2len;
    int reslen;
    int i, j;

    i = 0;
    j = 0;
    s1len = ft_strlen(s1);
    s2len = ft_strlen(s2);
    res = (char *)malloc(s1len + s2len + 2);
    if (!res)
        return (free(s1),NULL);
    while (i < s1len)
    {
        res[i] = s1[i];
        i++;
    }
    if (i > 0)
        res[i ++] = 32;
    while (i <= s1len + s2len)
        res[(i ++)] = s2[j++];
    res[i] = 0;
    return (free(s1), res);
}

char *args_tg(char **av, int n_arg)
{
    char *res;
    int i = 1;

    res = NULL;
    while (i < n_arg)
        res = ft_strjoin_space(res, av[i++]);
    return(res);
}

int is_it_valid_arg(char *s)
{
    int i;

    i = 0;
    if (ft_strlen(s) == 0)
        return (0);
    if (s)
    {
        while (s[i] && ((s[i] <= 57 && s[i] >= 48) || s[i] == 45 || s[i] == 43 || s[i] == 32))
        {
            if ((s[i] == 43 || s[i] == 45) && (s[i + 1] < 48 || s[i + 1] >  57))
                return(0);
            i++;
        }
        if (i == ft_strlen(s))
            return (1);
    }
    return(0);
}

int  fill_stack_a(char **s, int *stack_a, int slen, int *v)
{
    int i;

    i = 0;
    while(slen-- > 0)
    {
        stack_a[i ++] = ft_atoi(s[slen], v);
        free(s[slen]);
    } 
    return(free(s), i);
}

int *parse_nd_fill(int ac, char **av, int *i)
{
    int stack_len;
    char *arg_str;
    int *stack_a;
    char **args_sep;
    int v;

    v = 1;
    stack_a = NULL;
    arg_str = args_tg(av, ac);
    stack_len = count_nbrs_str(arg_str);
    *i = stack_len;
    if (is_it_valid_arg(arg_str) != 1)
        return (NULL);
    args_sep = split_nbr(arg_str);
    stack_a = (int *)malloc(sizeof(int) * stack_len);
    if (NULL == stack_a)
        return (NULL);
    fill_stack_a(args_sep, stack_a, stack_len, &v);
    if (v == -1)
        return (NULL);
    return(stack_a);
}

void error_mf()
{
    write(2, R"Error\n", 11);
    exit(2);
}

int main(int ac, char **av)
{
    int *a = NULL;
    int *b = NULL;
    int size_a, i, j;

    if (ac > 1)
    {
       
        a = parse_nd_fill(ac, av, &i);
        if (!a)
            return( error_mf(),0);
        // if (i)
        j = 0;
        if (is_it_rev_sorted(a, i) == 1)
            rev_sort_handler(&a,&b, &i, &j);
		else if (is_it_sorted(a, i) != 1)
        {
            if (i == 2)
                sort_two(a);
            // if (i==3)
            //     sort_tree(&a,&b,&i, &j);
            // if (i==4)
            //     sort_four(&a, &b, &i, &j);
            // if (i == 5)
            //     sort_five(&a, &b, &i, &j);
            else
                algo_nd_stuff(&a, &b, &i, &j);
        }
        // while (i--> 0)
        //     printf("a[%d] = %d\n", i, a[i]);
        free(a);
    }
}