/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:47:13 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/12 16:26:42 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_patoi(const char *str)
{
	int				loop;
	long			box;
	long			negative;

	box = 0;
	loop = 0;
	negative = 1;
	while (str[loop] == '\n' || str[loop] == '\t' || str[loop] == '\v'
		|| str[loop] == ' ' || str[loop] == '\f' || str[loop] == '\r')
			loop++;
	if (str[loop] == '-' || str[loop] == '+')
	{
		if (str[loop++] == '-')
			negative = -negative;
		if (str[loop] == '-')
			exit_write(EXIT_FAILURE);
	}
	while (str[loop] >= '0' && str[loop] <= '9')
		box = (box * 10) + str[loop++] - '0';
	return ((long)(box * negative));
}

int	arg_row(t_node	**a, t_node	**b, char	*row)
{
	char	**s;
	int		i;
	int		count;
	long	n;

	i = 0;
	count = 0;
	s = ft_split(row, ' ');
	while (s[i])
		i++;
	while (i-- > 0)
	{
		count++;
		n = ft_patoi(s[i]);
		free(s[i]);
		if (n > (long)INT_MAX || n < (long)INT_MIN)
			str_node_cleaner(s, i, a, b);
		push(a, n);
	}
	free(s);
	return (count);
}

int	arg_chain(t_node	**a, t_node	**b, char	*chain)
{
	long	n;

	n = ft_patoi(chain);
	if (n > (long)INT_MAX || n < (long)INT_MIN)
	{
		ft_putstr_fd("Error\n", 2);
		exit_free(*a, *b);
	}
	push(a, n);
	return (1);
}

int	dup_numbers(t_node	*node)
{
	t_node	*aux1;
	t_node	*aux2;

	aux1 = node;
	while (aux1)
	{
		aux2 = node;
		while (aux2)
		{
			if (aux1->n == aux2->n && aux1 != aux2)
				return (1);
			aux2 = aux2->next;
		}
		aux1 = aux1->next;
	}
	return (0);
}

int	lst_ordered(t_node	**head)
{
	int		i;
	t_node	*ref;

	ref = (*head);
	i = (*head)->index;
	while ((ref)->next)
	{
		ref = ref->next;
		if (i > (ref)->index)
		{
			return (0);
		}
		i = (ref)->index;
	}
	return (1);
}
