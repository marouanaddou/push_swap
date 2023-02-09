/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:47:29 by maddou            #+#    #+#             */
/*   Updated: 2023/02/09 21:34:58 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	larger(int *stack_a, int *stack_b, int argc, int size_b)
{
	int	best_a;
	int	best_b;
	int	conta;
	int	contb;

	best_b = besta_index(stack_a, stack_b, argc, size_b);
	best_a = opera_b(stack_a, stack_b[best_b], argc - 1, 'i');
	contb = opera_a(stack_a, size_b - 1, best_b, 'o');
	conta = opera_b(stack_a, stack_b[best_b], argc - 1, 'o');
	while ((conta > 0 && contb > 0) && (best_a >= (argc - 1) / 2
			&& best_a >= (size_b - 1) / 2))
	{
		rr(argc, size_b, stack_a, stack_b);
		conta--;
		contb--;
	}
	while (conta-- > 0)
		rotate(argc, stack_a, 'a');
	while (contb-- > 0)
		rotate(size_b, stack_b, 'b');
}

void	smaller(int *stack_a, int *stack_b, int argc, int size_b)
{
	int	best_a;
	int	best_b;
	int	conta;
	int	contb;

	best_b = besta_index(stack_a, stack_b, argc, size_b);
	best_a = opera_b(stack_a, stack_b[best_b], argc - 1, 'i');
	contb = opera_a(stack_a, size_b - 1, best_b, 'o');
	conta = opera_b(stack_a, stack_b[best_b], argc - 1, 'o');
	while ((conta > 0 && contb > 0) && (best_a <= (argc - 1) / 2
			&& best_a <= (size_b - 1) / 2))
	{
		rrr(argc, size_b, stack_a, stack_b);
		conta--;
		contb--;
	}
	while (conta-- > 0)
		rev_rotate(argc, stack_a, 'a');
	while (contb-- > 0)
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
	t_stack	s;

	s.size_b = 0;
	if (argc > 1)
	{
		(s).stack_a = chek(argc, argv, &s.n_arg);
		if (chek_order((s).stack_a, s.n_arg) == 1)
			exit(0);
		(s).stack_b = malloc((s.n_arg) * sizeof(int));
		if (!(s).stack_b)
			return (0);
		else if (s.n_arg == 3)
			ft_sort3(s.n_arg, (s).stack_a, (s).stack_b, 'f');
		else if (s.n_arg == 4 || s.n_arg == 2)
			ft_sort4(s.n_arg, (s).size_b, (s).stack_a, (s).stack_b);
		else if (s.n_arg == 5)
			ft_sort5(s.n_arg, (s).size_b, (s).stack_a, (s).stack_b);
		if (s.n_arg > 5)
		{
			copier_stack(&s);
			ft_swap(s.n_arg, s.size_b, s.stack_a, s.stack_b);
		}
	}
}
