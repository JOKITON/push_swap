/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:50:43 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/11 15:41:54 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node	**a)
{
	if ((*a)->n > ((*a)->next)->n)
		sa(a);
}

void	sort_three(t_node	**a)
{
	if ((*a)->n < ((*a)->next)->n)
	{
		if ((*a)->n < (((*a)->next)->next)->n)
		{
			if (((*a)->next)->n < (((*a)->next)->next)->n)
				return ;
			else
			{
				sa(a);
				ra(a);
			}
		}
		else
			rra(a);
	}
	else
		sort_three2(a);
}

void	sort_five(t_node	**a, t_node	**b)
{
	t_node	**ref;

	ref = a;
	push_min(ref, b, 0);
	aux_push_min(ref, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	sort_radix(t_node **a, t_node **b)
{
	t_node	*ref;
	int		max_bits;
	int		size;
	int		i;
	int		aux;

	ref = (*a);
	i = 0;
	size = lstsize(ref);
	max_bits = get_max_bits(a);
	while (max_bits > i)
	{
		aux = 0;
		while (aux++ < size)
		{
			ref = (*a);
			if (((ref->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (lstsize(*b) != 0)
			pa(a, b);
		++i;
	}
}
