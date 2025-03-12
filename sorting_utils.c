/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:47:47 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/11 15:41:47 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(t_node	*lst)
{
	int	num;

	if (!lst)
		return (0);
	num = 0;
	while (lst)
	{
		lst = lst->next;
		num++;
	}
	return (num);
}

int	get_max_bits(t_node **a)
{
	t_node	*ref;
	int		max_index;
	int		max_bits;

	max_bits = 0;
	max_index = 0;
	ref = (*a);
	while (ref != 0)
	{
		if (ref->index > max_index)
			max_index = ref->index;
		ref = ref->next;
	}
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	push_min(t_node	**a, t_node	**b, int n)
{
	t_node	**ref;

	ref = (a);
	if (((*ref)->next)->index == n)
		ra(ref);
	else if ((((*ref)->next)->next)->index == n)
	{
		ra(ref);
		ra(ref);
	}
	else if (((((*ref)->next)->next)->next)->index == n)
	{
		rra(ref);
		rra(ref);
	}
	else if ((((((*ref)->next)->next)->next)->next)->index == n)
		rra(ref);
	pb((ref), b);
}

void	aux_push_min(t_node	**a, t_node	**b)
{
	while ((*a)->index != 1)
		ra(a);
	pb(a, b);
}

void	sort_three2(t_node	**a)
{
	if (((*a)->next)->n < (((*a)->next)->next)->n)
	{
		if ((*a)->n < (((*a)->next)->next)->n)
			sa(a);
		else
			ra(a);
	}
	else
	{
		sa(a);
		rra(a);
	}
}
