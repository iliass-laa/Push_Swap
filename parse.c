#include "push_swap.h"

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
            if ((s[i] == 43 || s[i] == 45) && (s[i + 1] <= 48 || s[i + 1] >=  57))
                return (0);
            i++;
        }
        if (i == ft_strlen(s))
            return (1);
    }
    return(0);
}

int  fill_stack_a(char **s, int *stack_a)
{
    int i;
    int slen;

    i = 0;
    slen = 0;
    while(s[slen])
        slen++;
    slen -- ;
    while(slen > 0)
    {
        stack_a[i] = atoi(s[slen]);
        printf("stack_a>>%d,  av>>%s<<\n",stack_a[i], s[slen]);
        i++;
        slen --;
    }
    return(i);
}

int *parse_nd_fill(int ac, char **av)
{
    int stack_len;
    char *arg_str;
    int *stack_a;
    char **args_sep;


    stack_a = NULL;
    arg_str = args_tg(av, ac);
    stack_len = count_nbrs_str(arg_str);
    if (is_it_valid_arg(arg_str) == 1)
    {
        args_sep = split_nbr(arg_str);
        stack_a = (int *)malloc(sizeof(int) * stack_len);
        if (NULL == stack_a)
            return (0);
        fill_stack_a(args_sep, stack_a);
    }
    return(stack_a);
}

int main( int ac , char **av)
{
    int *stack_a;
    int i , size_a;
    char *arg_str;

    i = 0;
    if (ac > 1)
    {
        arg_str = args_tg(av, ac);
       
        if (is_it_valid_arg(arg_str) == 1)
        {
             stack_a = parse_nd_fill(ac, av);
             size_a =    count_nbrs_str(arg_str);
            if (is_dub(stack_a, size_a) == 1)
            {
                size_a--;
                while (size_a >= 0)
                    printf("%d\n", stack_a[size_a--]);
            }
            
        }
        else
            printf("Error invalid args!\n");
    }
}
