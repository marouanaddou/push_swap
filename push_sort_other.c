/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:12:13 by maddou            #+#    #+#             */
/*   Updated: 2023/01/19 20:11:10 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort2(int argc, int *stack_a)
{
	if (stack_a[0] > stack_a[1])
		return ;
	else
		swap(argc, stack_a, 'a');
}

void ft_sort4(int argc, int size_b , int *stack_a, int *stack_b)
{
    int j;

    j = minnumber(argc, stack_a);
    if (stack_a[0] > stack_a[1] && stack_a[1] > stack_a[2] && stack_a[2] > stack_a[3])
        return;
    if (j == 0)
        rev_rotate(argc, stack_a);
    else if (j == 1)
    {
        rev_rotate(argc, stack_a);
        rev_rotate(argc, stack_a);
    }
    else if (j == 2)
        rotate(argc, stack_a);
    push_b(&argc, &size_b, stack_a, stack_b);
    ft_sort3(argc, stack_a);
    push_a(&argc, &size_b, stack_a, stack_b);
}

void    ft_sort5(int argc, int size_b, int *stack_a, int *stack_b)
{
    int j;
    int x;

    x = 0;
    if (stack_a[0] > stack_a[1] && stack_a[1] > stack_a[2] && stack_a[2] > stack_a[3] && stack_a[3] > stack_a[4])
        return;
    while (x < 2)
    {
        //j = minnumber(argc, stack_a);   
        chek_min
        if (j == 0)
            rev_rotate(argc, stack_a, 'a');
        else if (j == 1)
        {
            rev_rotate(argc, stack_a, 'a');
            rev_rotate(argc, stack_a, 'a');
        }
        else if (j == 2 && argc == 5)
        {
            rotate(argc, stack_a, 'a');
            rotate(argc, stack_a, 'a');
        }
        else if (j == 2 && argc == 4)
            rotate(argc, stack_a, 'a');
        else if (j == 3 && argc == 5)
            rotate(argc, stack_a, 'a');
        push_b(&argc, &size_b, stack_a, stack_b);
            x++;
    }
    ft_sort3(argc, stack_a, 'a');
    push_a(&argc, &size_b, stack_a, stack_b);
    push_a(&argc, &size_b, stack_a, stack_b);
}

void	ft_sort3(int argc, int *stack_a)
{
	if (argc == 2)
		ft_sort2(argc, stack_a);
	else if (argc == 3)
	{
		if (stack_a[0] > stack_a[1] && stack_a[1] > stack_a[2])
			return ;
		else if (stack_a[0] > stack_a[2] && stack_a[2] > stack_a[1])
			swap(argc, stack_a,'a');
		else if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2]
				&& stack_a[2] > stack_a[0])
			rotate(argc, stack_a,'a');
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
	}
}