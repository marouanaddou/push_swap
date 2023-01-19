/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:47:29 by maddou            #+#    #+#             */
/*   Updated: 2023/01/19 20:11:20 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void free_split(char **split, char *sjoin)
{
    int i;

    i = 0;
    while(split[i])
    {
        free(split[i]);
        i++;
    }
    free(sjoin);
    free(split);
}
int main (int argc, char *argv[])
{
    int number_argument;
    int i;
    int *stack_a;
    int *stack_b;
    int size_b;
    
    i = 0;
    size_b = 0;
    stack_a = chek(argc, argv, &number_argument);
    stack_b = malloc((number_argument - 1) * sizeof(int));
    if (!stack_b)
        return (0);
    if (number_argument == 3 || number_argument == 2 )
        ft_sort3(number_argument, stack_a);
    
    ft_swap(number_argument, size_b, stack_a, stack_b);
}