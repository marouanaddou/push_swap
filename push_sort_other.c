/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:12:13 by maddou            #+#    #+#             */
/*   Updated: 2023/01/20 19:37:57 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort2(int argc, int *stack_a, int *stack_b)
{
	if (stack_a[0] > stack_a[1])
		return ;
	else
		swap(argc, stack_a, 'a');
	free_stack(stack_a, stack_b);
}

void	ft_sort4(int argc, int size_b, int *stack_a, int *stack_b)
{
	int	j;
	int	conta;

	chek_min(stack_a, argc - 1, &j);
	conta = opera_a(stack_a, argc - 1, j, 'o');
	move_othersa(stack_a, argc, j, conta);
	push_b(&argc, &size_b, stack_a, stack_b);
	ft_sort3(argc, stack_a, stack_b, 'a');
	push_a(&argc, &size_b, stack_a, stack_b);
	free_stack(stack_a, stack_b);
}

void	ft_sort5(int argc, int size_b, int *stack_a, int *stack_b)
{
	int	j;
	int	x;
	int	conta;

	x = 0;
	while (x < 2)
	{
		chek_min(stack_a, argc - 1, &j);
		conta = opera_a(stack_a, argc - 1, j, 'o');
		move_othersa(stack_a, argc, j, conta);
		push_b(&argc, &size_b, stack_a, stack_b);
		x++;
	}
	ft_sort3(argc, stack_a, stack_b, 'a');
	push_a(&argc, &size_b, stack_a, stack_b);
	push_a(&argc, &size_b, stack_a, stack_b);
	free_stack(stack_a, stack_b);
}

void	ft_sort3(int argc, int *stack_a, int *stack_b, char x)
{
	if (stack_a[0] > stack_a[1] && stack_a[1] > stack_a[2])
		return ;
	else if (stack_a[0] > stack_a[2] && stack_a[2] > stack_a[1])
		swap(argc, stack_a, 'a');
	else if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2]
		&& stack_a[2] > stack_a[0])
		rotate(argc, stack_a, 'a');
	else if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2]
		&& stack_a[0] > stack_a[2])
	{
		swap(argc, stack_a, 'a');
		rotate(argc, stack_a, 'a');
	}
	else if (stack_a[0] < stack_a[1] && stack_a[1] < stack_a[2])
	{
		swap(argc, stack_a, 'a');
		rev_rotate(argc, stack_a, 'a');
	}
	else
		rev_rotate(argc, stack_a, 'a');
	if (x == 'f')
		free_stack(stack_a, stack_b);
}
