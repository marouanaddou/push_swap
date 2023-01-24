/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:47:29 by maddou            #+#    #+#             */
/*   Updated: 2023/01/24 12:03:50 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	larger(int *stack_a, int *stack_b, int argc, int size_b)
{
	int	best_a;
	int	best_b;
	int	conta;
	int	contb;
	int	i;

	best_a = besta_index(stack_a, stack_b, argc, size_b);
	best_b = opera_b(stack_b, stack_a[best_a], size_b - 1, 'i');
	conta = opera_a(stack_a, argc - 1, best_a, 'o');
	contb = opera_b(stack_b, stack_a[best_a], size_b - 1, 'o');
	i = chek_number(stack_b, stack_a[best_a], size_b - 1);
	while ((conta > 0 && contb > 0) && (best_a >= (argc - 1) / 2
			&& best_a >= (size_b - 1) / 2) && i != 1)
	{
		rr(argc, size_b, stack_a, stack_b);
		conta--;
		contb--;
	}
	while (conta-- > 0)
		rotate(argc, stack_a, 'a');
	while (contb-- > 0 && i != 1)
		rotate(size_b, stack_b, 'b');
}

void	smaller(int *stack_a, int *stack_b, int argc, int size_b)
{
	int	best_a;
	int	best_b;
	int	conta;
	int	contb;
	int	i;

	best_a = besta_index(stack_a, stack_b, argc, size_b);
	best_b = opera_b(stack_b, stack_a[best_a], size_b - 1, 'i');
	conta = opera_a(stack_a, argc - 1, best_a, 'o');
	contb = opera_b(stack_b, stack_a[best_a], size_b - 1, 'o');
	i = chek_number(stack_b, stack_a[best_a], size_b - 1);
	while ((conta > 0 && contb > 0) && (best_a <= (argc - 1) / 2
			&& best_a <= (size_b - 1) / 2) && i != 1)
	{
		rrr(argc, size_b, stack_a, stack_b);
		conta--;
		contb--;
	}
	while (conta-- > 0)
		rev_rotate(argc, stack_a, 'a');
	while (contb-- > 0 && i != 1)
		rev_rotate(size_b, stack_b, 'b');
}

void	free_stack(int *stack_a, int *stack_b)
{
	free(stack_a);
	free(stack_b);
}

void	free_split(char **split, char *sjoin)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(sjoin);
	free(split);
}

int	main(int argc, char *argv[])
{
	int	number_argument;
	int	i;
	int	*stack_a;
	int	*stack_b;
	int	size_b;

	i = 0;
	size_b = 0;
	if (argc > 1)
	{
		stack_a = chek(argc, argv, &number_argument);
		if (chek_order(stack_a, number_argument) == 1)
			exit(0);
		stack_b = malloc((number_argument) * sizeof(int));
		if (!stack_b)
			return (0);
		else if (number_argument == 3)
			ft_sort3(number_argument, stack_a, stack_b, 'f');
		else if (number_argument == 4 || number_argument == 2)
			ft_sort4(number_argument, size_b, stack_a, stack_b);
		else if (number_argument == 5)
			ft_sort5(number_argument, size_b, stack_a, stack_b);
		else if (number_argument > 5)
			ft_swap(number_argument, size_b, stack_a, stack_b);
	}
}
