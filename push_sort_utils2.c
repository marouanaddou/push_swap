/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:00:46 by maddou            #+#    #+#             */
/*   Updated: 2023/01/24 12:55:04 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chek_order(int *str, int number)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < number - 1)
	{
		if (str[i] > str[i + 1])
			j++;
		i++;
	}
	if (j == number - 1)
	{
		free(str);
		return (1);
	}
	return (0);
}

int	chek_number(int *stack_b, int valeurStack_a, int size_b)
{
	int	i;
	int	min;
	int	index_min;

	i = 0;
	min = chek_min(stack_b, size_b, &index_min);
	if (valeurStack_a <= min)
		return (1);
	return (0);
}

void	ft_sorting(t_stack *s)
{
	while (((*s).argc - 1) >= 0)
	{
		(*s).best_a = besta_index((s)->stack_a, (s)->stack_b, (*s).argc,
				(*s).size_b);
		(*s).best_b = opera_b((s)->stack_b, (s)->stack_a[(*s).best_a],
				(*s).size_b - 1, 'i');
		(*s).conta = opera_a((s)->stack_a, (*s).argc - 1, (*s).best_a, 'o');
		(*s).contb = opera_b((s)->stack_b, (s)->stack_a[(*s).best_a],
				(*s).size_b - 1, 'o');
		(*s).i = (s)->stack_a[(*s).best_a];
		ft_move(s);
		push_b(&((*s).argc), &((*s).size_b), (s)->stack_a, (s)->stack_b);
	}
}

void	ft_move(t_stack *st)
{
	if ((*st).best_a >= ((*st).argc - 1) / 2 && (*st).best_b >= ((*st).size_b
			- 1) / 2)
		larger((st)->stack_a, (st)->stack_b, (*st).argc, (*st).size_b);
	else if ((*st).best_a < ((*st).argc - 1) / 2 && (*st).best_b < ((*st).size_b
			- 1) / 2)
		smaller((st)->stack_a, (st)->stack_b, (*st).argc, (*st).size_b);
	else if ((((*st).best_a >= ((*st).argc - 1) / 2
				&& (*st).best_b < ((*st).size_b - 1) / 2))
		|| (((*st).best_a < ((*st).argc - 1) / 2
				&& (*st).best_b >= ((*st).size_b - 1) / 2)))
	{
		move_othersa((st)->stack_a, (*st).argc, (*st).best_a, (*st).conta);
		if (chek_number((st)->stack_b, (*st).i, (*st).size_b - 1) == 0)
			move_othersb((st)->stack_b, (*st).size_b, (*st).best_b,
				(*st).contb);
	}
	if (chek_number((st)->stack_b, (*st).i, (*st).size_b - 1) == 1)
		move_min((st)->stack_b, (*st).size_b, (*st).best_b, (*st).contb);
}
