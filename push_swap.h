/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:54:48 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/12 16:26:49 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				n;
	int				index;
	struct s_node	*next;
}	t_node;

// Allowed operations
void	sa(t_node	**stack_a);
void	sb(t_node	**stack_b);
void	ss(t_node	**stack_a, t_node	**stack_b);

void	pa(t_node	**a, t_node	**b);
void	pb(t_node	**a, t_node	**b);

// _________Rotate functions-> Move _up_ all the stack one position
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node	**a, t_node **b);
t_node	*s_bottom(t_node	*node);

// _________Reverse Rotate Functions -> Move _down_ all the stack one position
void	rra(t_node	**a);
void	rrb(t_node	**b);
void	rrr(t_node	**a, t_node	**b);

void	push(t_node	**head, int number);
// Memory Deallocation
void	str_node_cleaner(char	**str, int size, t_node	**a, t_node	**b);
void	exit_free(t_node	*node_a, t_node	*node_b);
void	exit_write(int code);

char	**clean_args(t_node	**stack_a, t_node	**stack_b, int n, char	**str);
long	ft_patoi(const char *str);
int		dup_numbers(t_node	*node);

// Re-start of Functions
int		chr_finder(char	*haystack);
int		get_args(t_node	**a, t_node	**b, char	**args);
int		arg_row(t_node	**a, t_node	**b, char	*row);
int		arg_chain(t_node	**a, t_node	**b, char	*chain);

// Sorting algorimths

void	ord_index(int size, t_node	**a, t_node	**b);
int		lst_ordered(t_node	**head);

void	sort_two(t_node	**a);
void	sort_three(t_node	**a);
void	sort_three2(t_node	**a);
void	sort_five(t_node	**a, t_node	**b);
void	sort_radix(t_node **a, t_node **b);

void	push_min(t_node	**a, t_node	**b, int n);
void	aux_push_min(t_node	**a, t_node	**b);
int		get_max_bits(t_node **a);
int		lstsize(t_node	*lst);
void	lst_index(t_node	**n, int count);

void	print(t_node	*a, t_node	*b);

#endif
