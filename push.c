/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:17:44 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/12 16:27:20 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node	**head, int number)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->n = number;
	node->index = -1;
	node->next = *(head);
	(*head) = node;
}

void	pa(t_node	**a, t_node	**b)
{
	t_node	*aux;

	if (*b == 0)
		return ;
	aux = (*b);
	(*b) = (*b)->next;
	aux->next = (*a);
	(*a) = aux;
	write(1, "pa\n", 3);
}

void	pb(t_node	**a, t_node	**b)
{
	t_node	*aux;

	if (*a == 0)
		return ;
	aux = (*a);
	(*a) = (*a)->next;
	aux->next = (*b);
	(*b) = aux;
	write(1, "pb\n", 3);
}
