/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:00:46 by maddou            #+#    #+#             */
/*   Updated: 2023/01/18 21:40:34 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chek_number(int *stack_b, int valeurStack_a, int size_b)
{
	int i;
	int min;
	int index_min;

	i = 0;
	min = chek_min(stack_b, size_b, &index_min);
	if (valeurStack_a <= min)
		return (1);
	return (0);
}