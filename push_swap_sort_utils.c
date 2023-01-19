/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:19:29 by maddou            #+#    #+#             */
/*   Updated: 2023/01/19 18:50:47 by maddou           ###   ########.fr       */
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

void	move_min(int *stack_b, int size_b, int best_b, int operation)
{
	int	i;

	i = 0;
	if (best_b > (size_b - 1) / 2)
	{
		while (i < operation)
		{
			rotate(size_b, stack_b, 'b');
			i++;
		}
	}
	else if (best_b <= (size_b - 1) / 2)
	{
		while (i < operation)
		{
			rev_rotate(size_b, stack_b, 'b');
			i++;
		}
	}
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

void	calcul_move(int *stack_a, int *stack_b, int size_b, int argc)
{
    int i;
	int best_a;
	int best_b;
	int conta;
	int contb;

	i = 0;
	best_b = chek_min(stack_b, size_b - 1, &best_a);
	contb = opera_b(stack_b, best_b, size_b - 1, 'o');
	move_min(stack_b, size_b, best_a, contb);
	while (i < size_b + argc)
	{
		push_a(&argc, &size_b, stack_a, stack_b);
		i++;
	}
	//test_function(stack_a, stack_b, size_b, argc);
	free(stack_a);
	free(stack_b);
}
