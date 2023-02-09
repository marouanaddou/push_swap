/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:19:29 by maddou            #+#    #+#             */
/*   Updated: 2023/02/09 21:29:09 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chek_min(int *stack_b, int size_b, int *index_min)
{
	int	i;
	int	min;

	i = 0;
	min = stack_b[0];
	*index_min = i;
	if (size_b > 0)
	{
		while (i <= size_b)
		{
			if (stack_b[0] >= stack_b[i] && min > stack_b[i])
			{
				min = stack_b[i];
				*index_min = i;
			}
			i++;
		}
	}
	return (min);
}

void	move_othersb(int *stack, int total, int best, int operation)
{
	int	i;

	i = 0;
	if (best >= (total - 1) / 2)
	{
		while (i < operation)
		{
			rotate(total, stack, 'b');
			i++;
		}
	}
	else if (best < (total - 1) / 2)
	{
		while (i < operation)
		{
			rev_rotate(total, stack, 'b');
			i++;
		}
	}
}

void	move_othersa(int *stack, int total, int best, int operation)
{
	int	i;

	i = 0;
	if (best >= (total - 1) / 2)
	{
		while (i < operation)
		{
			rotate(total, stack, 'a');
			i++;
		}
	}
	else if (best < (total - 1) / 2)
	{
		while (i < operation)
		{
			rev_rotate(total, stack, 'a');
			i++;
		}
	}
}

void	calcul_move_min(int *stack_a, int *stack_b, int size_b, int argc)
{
	int	i;
	int	best_a;
	int	best_b;
	int	contb;

	(void)size_b;
	i = 0;
	best_b = chek_min(stack_a, argc - 1, &best_a);
	contb = opera_b(stack_a, best_b, argc - 1, '0');
	move_othersa(stack_a, argc, best_a, contb);
	free_stack(stack_a, stack_b);
}
