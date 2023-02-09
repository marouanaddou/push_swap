/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:19:50 by maddou            #+#    #+#             */
/*   Updated: 2023/02/08 21:09:04 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(int argc, int *stack)
{
	int	swap;

	if (argc > 1)
	{
		swap = stack[argc - 1];
		stack[argc - 1] = stack[argc - 2];
		stack[argc - 2] = swap;
	}
}

void	ss(int argc, int size_b, int *stack_a, int *stack_b)
{
	swap(argc, stack_a);
	swap(size_b, stack_b);
}

// or *size_b > 0 ===> (*size_b + *argc)
void	push_a(int *argc, int *size_b, int *stack_a, int *stack_b)
{
	if (*argc < *size_b + *argc)
	{
		stack_a[*argc] = stack_b[*size_b - 1];
		*argc += 1;
		*size_b -= 1;
	}
}

void	push_b(int *argc, int *size_b, int *stack_a, int *stack_b)
{
	if (*argc > 0)
	{
		stack_b[*size_b] = stack_a[*argc - 1];
		*argc -= 1;
		*size_b += 1;
	}
}
