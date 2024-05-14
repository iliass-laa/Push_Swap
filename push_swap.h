#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int ft_strlen(char *s);
char *ft_strjoin_space(char *s1, char *s2);
char *args_tg(char **av, int n_arg);
int is_it_valid_arg(char *s);


void ft_swap(int *a, int *b);
int is_it_sorted(int *stack, int size);
void clone_it(int *stack_a, int *stack_tmp, int size);
// void push_helper(int *stack, int new_size);
void push_helper(int **stack, int new_size);
// void clone_it(int **stack_a, int **stack_tmp, int size);


int count_nbrs_str(char *s);
char    *ft_strdup(char *s, int start, int len);
int find_start(char *s, int i);
int find_end(char *s, int i);
char **split_nbr(char *s);
int get_bigone_index(int *stack, int size);

int is_dub(int *stack_a , int size);
int jibsghira(int *stack_a, int size_a);
void sort_tmp(int *stack_a, int *stack_tmp, int size);
int get_index_sort(int nbr, int *stack_tmp, int size);
int next_smallest(int *stack_a, int size, int nbr);
void a_to_b(int **stack_a, int **stack_b, int *size_a, int *size_b);

// int     pa(int	*stack_a, int *stack_b, int *size_a, int *size_b);
int     pb(int  **stack_a, int **stack_b, int *size_a, int *size_b);
int     pa(int	**stack_a, int **stack_b, int *size_a, int *size_b);
// int     pb(int  *stack_a, int *stack_b, int *size_a, int *size_b);
void    sa(int  *stack_a, int size);
void    sb(int  *stack_b, int size);
void    ss(int  *stack_a, int *stack_b , int size_a, int size_b);
int     ra(int  *stack_a, int size_a);
void    rb(int  *stack_b, int size_b);
void    rr(int	*stack_a, int *stack_b, int size_a, int size_b);
// void    rra(int *stack_a, int size_a);
void    rra(int **stack_a, int size_a);
void    rrb(int **stack_b, int size_b);
void    rrr(int *stack_a, int *stack_b, int size_a, int size_b);
void algo_nd_stuff(int **stack_a, int **stack_b, int *size_a, int *size_b);



# endif
