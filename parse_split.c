#include "push_swap.h"

int count_nbrs_str(char *s)
{
    int i,res;

    i = 0;
    res = 0;
    if (s)
    {
        while (s[i])
        {
            if ((s[i] >= 48 && s[i] <= 57) && (s[i + 1] == 32 || s[i + 1] == 0))
                res ++;
            i++;
        }
    }
    return (res);
}

char    *ft_strdup(char *s, int start, int len)
{
    int reslen;
    int slen;
    int i;
    char *res;

    reslen = len;
    i = 0;
    slen = ft_strlen(s);
    if (start + len >= slen)
        reslen = slen - start;
    if (start == slen)
        return(NULL);
    res = (char *)malloc(reslen + 1);
    if (!res)
        return(NULL);
    while(i < reslen)
        res[i++] = s[start ++];
    res[i] = 0;
    return(res);
}

int find_start(char *s, int i)
{
    while (s[i])
    {
        if (s[i] && ((s[i] >= 48 && s[i] <= 57) || s[i] == 45 || s[i] == 43 ))
            return(i);
        i++;
    }
    return(i);
}

int find_end(char *s, int i)
{ 
    while (s[i] && ((s[i] >= 48 && s[i] <= 57) || s[i] == 45  || s[i] == 43 ))
        i++;
    return(i);
}

char **split_nbr(char *s)
{ 
    int i;
    int nbr_str;
    int start;
    int end;
    char **res;

    i = 0;
    nbr_str = count_nbrs_str(s);
    res = (char **)malloc(sizeof(char *) * (nbr_str + 1));
    if (!res)
        return(free(s),NULL);
    end = 0;
    while(i < nbr_str)
    {
        start =  find_start(s, end);
        end = find_end(s, start);          
        res[i] = ft_strdup(s, start, (end - start));
        i++;
    }
    res[i] = 0;
    return(free(s), res);
}