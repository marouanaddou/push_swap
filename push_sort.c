/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:15:20 by maddou            #+#    #+#             */
/*   Updated: 2023/01/19 11:39:51 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	opera_a(int *stack_a, int argc, int index, char chek)
{
	int	contab;

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
	int	index_max;
	int	size;
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
	int	i;
	int	j;
	int	best_istruction;
	int	current_instruction;

	i = 0;/* argc ==> kif size_b */
	best_istruction = INT_MAX;/* size_b
		- 1 ==> m3a kaykon zayad wahad ohna kana9sooh bach nbdaw b zero tji hiya hadik */
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
	int	i;
	int	best_a;
	int	best_b;
	int	conta;
	int	contb;
	
	push_b(&argc, &size_b, stack_a, stack_b);
	push_b(&argc, &size_b, stack_a, stack_b);
	while ((argc - 1) >= 0)
	{
		best_a = besta_index(stack_a, stack_b, argc, size_b);
		best_b = opera_b(stack_b, stack_a[best_a], size_b - 1, 'i');
		conta = opera_a(stack_a, argc - 1, best_a, 'o');
		contb = opera_b(stack_b, stack_a[best_a], size_b - 1, 'o');
		i = stack_a[best_a];
		move_othersa(stack_a, argc, best_a, conta);
		conta = chek_number(stack_b, i, size_b - 1);
		if (conta == 1)
			move_min(stack_b, size_b, best_b, contb);
		else
			move_othersb(stack_b, size_b, best_b, contb);
		push_b(&argc, &size_b, stack_a, stack_b);
	}
	calcul_move(stack_a, stack_b, size_b, argc);
}

// int main(int argc, char *argv[]) {
//   int *stack_a;
//   char *stack_b;
//   int number_argument;
//   int i;

//   i = 0;
//   stack_a = chek(argc, argv, &number_argument);
//   stack_b = malloc(number_argument * sizeof(int));
//   if (!stack_b)
//     return (0);

//   //printf ("%d", number_argument);
//   //chek_digit(x);
//   return (0);
// }