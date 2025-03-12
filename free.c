/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 06:00:03 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/12 17:01:36 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_free(t_node	*node_a, t_node	*node_b)
{
	t_node	*aux;

	while (node_a != 0)
	{
		aux = node_a;
		node_a = node_a->next;
		free(aux);
	}
	while (node_b != 0)
	{
		aux = node_b;
		node_b = node_b->next;
		free(aux);
	}
	exit (EXIT_SUCCESS);
}

void	str_node_cleaner(char	**str, int size, t_node	**a, t_node	**b)
{
	while (size-- > 0)
		free(str[size]);
	free(str);
	ft_putstr_fd("Error\n", 2);
	exit_free(*a, *b);
}

void	exit_write(int code)
{
	ft_putstr_fd("Error\n", 2);
	exit(code);
}
