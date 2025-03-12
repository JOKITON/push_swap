/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:50:59 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/12 16:45:30 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chr_finder(char	*haystack)
{
	int	i;
	int	aux;

	i = 0;
	aux = 0;
	if (!ft_strncmp(haystack, " ", 2))
		return (-1);
	while (haystack[i])
	{
		if ((haystack[i] < '0' || haystack[i] > '9') && haystack[i] != ' '
			&& haystack[i] != '+' && haystack[i] != '-')
			return (-1);
		else if ((haystack[i] < '0' || haystack[i] > '9') && haystack[i] == ' ')
			aux = 1;
		i++;
	}
	if (aux == 1)
		return (0);
	return (1);
}

void	lst_index(t_node	**n, int count)
{
	t_node	*ref;
	int		i;
	int		index;

	ref = (*n);
	i = (*n)->n;
	index = 0;
	ref = (*n);
	while (count > index)
	{
		while ((*n) != 0)
		{
			if ((*n)->index == -1 && i > (*n)->n)
				i = (*n)->n;
			(*n) = (*n)->next;
		}
		(*n) = ref;
		while ((*n)->n != i)
			(*n) = (*n)->next;
		(*n)->index = index;
		(*n) = ref;
		i = __INT_MAX__;
		index++;
	}
}

void	ord_index(int size, t_node	**a, t_node	**b)
{
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 5)
		sort_five(a, b);
	else
		sort_radix(a, b);
	return ;
}

int	get_args(t_node	**a, t_node	**b, char	**args)
{
	int	i;
	int	num;
	int	count;

	count = 0;
	i = 1;
	while (args[i])
		i++;
	while (--i >= 1)
	{
		num = chr_finder(args[i]);
		if (num == 1)
			count += arg_chain(a, b, args[i]);
		else if (num == 0)
			count += arg_row(a, b, args[i]);
		else if (num == -1)
		{
			ft_putstr_fd("Error\n", 2);
			exit_free(*a, *b);
		}
	}
	return (count);
}

/*void	print(t_node	*a, t_node	*b)
{
	printf("\n______________________________\n");
	printf("____________STACK_A___________\n");
	while (a)
	{
		printf("A stack n.%d : %d\n", (a->index), a->n);
		a = a->next;
	}
	printf("\n______________________________\n");
	printf("____________STACK_B___________\n");
	while (b)
	{
		printf("B stack n.%d : %d\n", (b->index), b->n);
		b = b->next;
	}
	printf("\n");
}*/
