/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:51:12 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/16 11:35:34 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node	**a)
{
	t_node	*aux;
	t_node	*aux2;

	aux = NULL;
	aux = *a;
	while ((((*a)->next)->next) != 0)
		*a = (*a)->next;
	(*a)->next->next = aux;
	aux2 = (*a)->next;
	(*a)->next = 0;
	*a = aux2;
	write(1, "rra\n", 4);
}

void	rrb(t_node	**b)
{
	t_node	*aux;

	aux = (*b);
	while (((*b)->next)->next != 0)
		(*b) = (*b)->next;
	(*b)->next->next = aux;
	aux = (*b)->next;
	(*b)->next = 0;
	(*b) = aux;
	write(1, "rrb\n", 4);
}

void	rrr(t_node	**a, t_node	**b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
