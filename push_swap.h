/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:43:41 by ilaasri           #+#    #+#             */
/*   Updated: 2024/05/17 17:43:43 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	i;
	int	j;
}		t_stacks;
typedef struct s_tap
{
	int	size;
	int	start;
	int	max;
	int	index_sorted;
	int	*stack_tmp;
}		t_tap;

int		ft_strlen(char *s);
char	*ft_strjoin_space(char *s1, char *s2);
char	*args_tg(char **av, int n_arg);
int		is_it_valid_arg(char *s);
int		ft_atoi(const char *str, int *v);

void	ft_swap(int *a, int *b);
int		is_it_sorted(int *stack, int size);
int		is_it_rev_sorted(int *stack, int size);
void	rev_sort_handler(int **stack_a, int **stack_b, int *size_a,
			int *size_b);
void	clone_it(int *stack_a, int *stack_tmp, int size);
void	push_helper(int **stack, int new_size);

void	treat_small(int **a, int **b, int *i, int *j);
void	sort_two(int *stack_a);
int		tree_sort(int **a, int **b, int *i, int *j);
void	sort_four(int **a, int **b, int *i, int *j);
void	sort_five(int **a, int **b, int *i, int *j);

int		count_nbrs_str(char *s);
char	*ft_strdup(char *s, int start, int len);
int		find_start(char *s, int i);
int		find_end(char *s, int i);
char	**split_nbr(char *s);
int		get_bigone_index(int *stack, int size);

int		is_dub(int *stack_a, int size);
int		jibsghira(int *stack_a, int size_a);
void	sort_tmp(int *stack_a, int *stack_tmp, int size);
int		get_index_sort(int nbr, int *stack_tmp, int size);
void	a_to_b(t_stacks *y);
void	a_to_b_season_two(t_stacks *y, t_tap *x);
void	algo_nd_stuff(t_stacks *y);

int		*parse_nd_fill(int ac, char **av, int *i);
void	error_mf(void);
void	freedom(char *s, char **res, int i);

void	pb(int **stack_a, int **stack_b, int *size_a, int *size_b);
void	pa(int **stack_a, int **stack_b, int *size_a, int *size_b);
void	sa(int *stack_a, int size);
void	sb(int *stack_b, int size);
void	ss(int *stack_a, int *stack_b, int size_a, int size_b);
int		ra(int *stack_a, int size_a);
void	rb(int *stack_b, int size_b);
void	rr(int *stack_a, int *stack_b, int size_a, int size_b);
void	rra(int **stack_a, int size_a);
void	rrb(int **stack_b, int size_b);
void	rrr(int *stack_a, int *stack_b, int size_a, int size_b);

#endif
