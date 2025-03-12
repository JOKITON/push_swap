/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:41:59 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/16 11:35:42 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a)
{
	t_node	*aux;

	if (*a == 0 || (*a)->next == 0)
		return ;
	aux = (*a);
	aux = s_bottom(aux);
	aux->next = (*a);
	aux = (*a)->next;
	(*a)->next = 0;
	(*a) = aux;
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	t_node	*aux;

	if (*b == 0 || (*b)->next == 0)
		return ;
	aux = (t_node *)malloc(sizeof(t_node));
	aux = (*b);
	aux = s_bottom(aux);
	aux->next = (*b);
	aux = (*b)->next;
	(*b)->next = 0;
	(*b) = aux;
	write(1, "rb\n", 3);
}

void	rr(t_node	**a, t_node **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}

t_node	*s_bottom(t_node	*node)
{
	while (node && (node)->next != NULL)
		(node) = (node)->next;
	return (node);
}
