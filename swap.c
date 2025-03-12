/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:56:18 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/16 11:35:54 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node	**stack_a)
{
	t_node	*aux;

	if ((*stack_a)->next == 0)
		return ;
	aux = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	aux->next = (*stack_a)->next;
	(*stack_a)->next = aux;
	write(1, "sa\n", 3);
}

void	sb(t_node	**stack_b)
{
	t_node	*aux;

	if ((*stack_b)->next == 0)
		return ;
	aux = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	aux->next = (*stack_b)->next;
	(*stack_b)->next = aux;
	write(1, "sb\n", 3);
}

void	ss(t_node	**stack_a, t_node	**stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
