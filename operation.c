/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:49:28 by maddou            #+#    #+#             */
/*   Updated: 2023/01/20 19:31:48 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(int argc, int *stack, char x)
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
		if (x == 'a')
			write(1, "rra\n", 4);
		if (x == 'b')
			write(1, "rrb\n", 4);
	}
}

void	rrr(int argc, int size_b, int *stack_a, int *stack_b)
{
	rev_rotate(argc, stack_a, 'c');
	rev_rotate(size_b, stack_b, 'c');
	write(1, "rrr\n", 4);
}

void	rotate(int argc, int *stack, char x)
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
		if (x == 'a')
			write(1, "ra\n", 3);
		if (x == 'b')
			write(1, "rb\n", 3);
	}
}

void	rr(int argc, int size_b, int *stack_a, int *stack_b)
{
	rotate(argc, stack_a, 'c');
	rotate(size_b, stack_b, 'c');
	write(1, "rr\n", 3);
}
