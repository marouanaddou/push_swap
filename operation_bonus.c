/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:20:18 by maddou            #+#    #+#             */
/*   Updated: 2023/02/08 21:08:53 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
//#include "push_swap.h"
void	rev_rotate(int argc, int *stack)
{
	int	first;
	int	i;

	first = stack[0];
	i = 0;
	if (argc > 1)
	{
		while (i < (argc - 1))
		{
			stack[i] = stack[i + 1];
			i++;
		}
		stack[i] = first;
	}
}

void	rrr(int argc, int size_b, int *stack_a, int *stack_b)
{
	rev_rotate(argc, stack_a);
	rev_rotate(size_b, stack_b);
}

void	rotate(int argc, int *stack)
{
	int	last;
	int	i;

	i = argc - 1;
	last = stack[i];
	if (argc > 1)
	{
		while (i > 0)
		{
			stack[i] = stack[i - 1];
			i--;
		}
		stack[0] = last;
	}
}

void	rr(int argc, int size_b, int *stack_a, int *stack_b)
{
	rotate(argc, stack_a);
	rotate(size_b, stack_b);
}
