/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:58:23 by maddou            #+#    #+#             */
/*   Updated: 2023/02/08 19:52:19 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copier(int *c_stack, int n_arg, int *stack_a)
{
	int	i;

	i = 0;
	i = 0;
	while (i < n_arg)
	{
		c_stack[i] = stack_a[i];
		i++;
	}
	return (c_stack);
}

int	*ft_sort(int *c_stack, int n_arg, int *stack_a)
{
	int	i;
	int	tmp;
	int	j;

	c_stack = copier(c_stack, n_arg, stack_a);
	i = 0;
	while (i < n_arg)
	{
		j = i + 1;
		while (j < n_arg)
		{
			if (c_stack[j] < c_stack[i])
			{
				tmp = c_stack[j];
				c_stack[j] = c_stack[i];
				c_stack[i] = tmp;
			}
			j++;
		}
		i++;
	}
	return (c_stack);
}

void	copier_stack(t_stack *sta)
{
	(sta)->c_stack = malloc((sta)->n_arg * sizeof(int));
	while ((sta)->n_arg - 1 >= 2)
	{
		(sta)->c_stack = ft_sort((sta)->c_stack, (sta)->n_arg, sta->stack_a);
		if ((sta)->stack_a[(sta)->n_arg - 1] <= (sta)->c_stack[((sta)->n_arg
					- 1) / 2])
			push_b(&(sta)->n_arg, &(sta)->size_b, (sta)->stack_a,
				(sta)->stack_b);
		else
			rotate((sta)->n_arg, (sta)->stack_a, 'a');
	}
	free((sta)->c_stack);
}
