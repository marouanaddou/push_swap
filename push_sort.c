/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:15:20 by maddou            #+#    #+#             */
/*   Updated: 2023/01/23 15:26:49 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	opera_a(int *stack_a, int argc, int index, char chek)
{
	int	contab;

	(void)stack_a;
	if (chek == 'i')
		contab = index;
	if (chek == 'o')
	{
		if (index >= argc / 2)
			contab = argc - index;
		else if (index < argc / 2)
			contab = index + 1;
	}
	return (contab);
}

int	find_right_pos(int size_b, int value, int *stack_b, char chek)
{
	int	i;
	int	size;
	int	contb;
	int	j;

	i = 0;
	j = size_b;
	while (value < stack_b[size_b])
		size_b--;
	size = size_b;
	size_b--;
	while (size_b >= 0)
	{
		if (stack_b[size_b] > stack_b[size] && stack_b[size_b] < value)
			size = size_b;
		size_b--;
	}
	contb = opera_a(stack_b, j, size, chek);
	return (contb);
}

int	opera_b(int *stack_b, int value, int size_b, char chek)
{
	int	contb;
	int	index_min;
	int	min;

	min = chek_min(stack_b, size_b, &index_min);
	if (value <= min)
	{
		if (index_min > size_b / 2)
			contb = size_b - index_min + 1;
		else if (index_min <= size_b / 2)
			contb = index_min;
		if (chek == 'i')
			contb = index_min;
	}
	else
		contb = find_right_pos(size_b, value, stack_b, chek);
	return (contb);
}

int	besta_index(int *stack_a, int *stack_b, int argc, int size_b)
{
	int	j;
	int	i;
	int	best_istruction;
	int	current_instruction;

	i = 0;
	best_istruction = INT_MAX;
	while (i < argc)
	{
		current_instruction = opera_a(stack_a, argc - 1, i, 'o')
			+ opera_b(stack_b, stack_a[i], size_b - 1, 'o');
		if (current_instruction < best_istruction)
		{
			best_istruction = current_instruction;
			j = i;
		}
		i++;
	}
	return (j);
}

void	ft_swap(int argc, int size_b, int *stack_a, int *stack_b)
{
	t_stack	t_data;

	t_data.argc = argc;
	t_data.size_b = size_b;
	t_data.stack_a = stack_a;
	t_data.stack_b = stack_b;
	push_b(&((t_data).argc), &((t_data).size_b), (t_data).stack_a,
		(t_data).stack_b);
	push_b(&((t_data).argc), &((t_data).size_b), (t_data).stack_a,
		(t_data).stack_b);
	ft_sorting(&t_data);
	calcul_move(t_data.stack_a, t_data.stack_b, t_data.size_b, t_data.argc);
}
