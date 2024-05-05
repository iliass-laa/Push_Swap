#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int ft_strlen(char *s);
char *ft_strjoin_space(char *s1, char *s2);
char *args_tg(char **av, int n_arg);
int is_it_valid_arg(char *s);


int count_nbrs_str(char *s);
char    *ft_strdup(char *s, int start, int len);
int find_start(char *s, int i);
int find_end(char *s, int i);
char **split_nbr(char *s);

int is_dub(int *stack_a , int size);
int jibsghira(int *stack_a, int size_a);

int     pa(int	*stack_a, int *stack_b, int *size_a, int *size_b);
int     pb(int  *stack_a, int *stack_b, int *size_a, int *size_b);
void    sa(int  *stack_a, int size);
void    sb(int  *stack_b, int size);
void    ss(int  *stack_a, int *stack_b , int size_a, int size_b);
int     ra(int  *stack_a, int size_a);
void    rb(int  *stack_b, int size_b);
void    rr(int	*stack_a, int *stack_b, int size_a, int size_b);
void    rra(int *stack_a, int size_a);
void    rrb(int *stack_b, int size_b);
void    rrr(int *stack_a, int *stack_b, int size_a, int size_b);



# endif
