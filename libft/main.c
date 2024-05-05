#include "libft.h"
#include <stdio.h>

int main()
{
    int i = 0;
    char *s = "--`-8+1025";
    while (s[i])
    {
        if (ft_isdigit(s[i]) != 1)
        {
            printf("nada>>%d\n", i);
            return 0;
        }
        i++;
    }
    printf("cool %d\n", ft_atoi(s));
}