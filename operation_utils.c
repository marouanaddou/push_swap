/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:10:00 by maddou            #+#    #+#             */
/*   Updated: 2023/01/20 19:32:20 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int argc, int *stack, char x)
{
	int	swap;

	if (argc > 1)
	{
		swap = stack[argc - 1];
		stack[argc - 1] = stack[argc - 2];
		stack[argc - 2] = swap;
		if (x == 'a')
			write(1, "sa\n", 3);
		if (x == 'b')
			write(1, "sb\n", 4);
	}
}

void	ss(int argc, int size_b, int *stack_a, int *stack_b)
{
	swap(argc, stack_a, 'c');
	swap(size_b, stack_b, 'c');
	write(1, "sa\n", 3);
}

// or *size_b > 0 ===> (*size_b + *argc)
void	push_a(int *argc, int *size_b, int *stack_a, int *stack_b)
{
	if (*argc < *size_b + *argc)
	{
		stack_a[*argc] = stack_b[*size_b - 1];
		*argc += 1;
		*size_b -= 1;
		write(1, "pa\n", 3);
	}
}

void	push_b(int *argc, int *size_b, int *stack_a, int *stack_b)
{
	if (*argc > 0)
	{
		stack_b[*size_b] = stack_a[*argc - 1];
		*argc -= 1;
		*size_b += 1;
		write(1, "pb\n", 3);
	}
}
