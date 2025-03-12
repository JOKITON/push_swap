/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:16:01 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/12 16:49:54 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char	**args)
{
	t_node	*a;
	t_node	*b;
	int		size;

	a = 0;
	b = 0;
	size = get_args(&a, &b, args);
	if (dup_numbers(a) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit_free(a, b);
	}
	lst_index(&a, size);
	if (lst_ordered(&a) == 1)
		exit_free(a, b);
	ord_index(size, &a, &b);
	exit_free(a, b);
}

int	main(int ac, char	**ar)
{
	if (ac == 1)
		return (EXIT_FAILURE);
	push_swap(ar);
}
