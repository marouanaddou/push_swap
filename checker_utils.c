/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:23:26 by maddou            #+#    #+#             */
/*   Updated: 2023/02/08 22:41:40 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	chek_join(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\n')
		return (0);
	else
	{
		while (str[i] != '\0')
		{
			if ((str[i] == '\n' && str[i + 1] == '\n') || (str[i] == '\n'
					&& str[i + 1] == '\n' && str[i + 1] == '\0')
				|| (str[i] != '\n' && str[i + 1] == '\0'))
				return (0);
			i++;
		}
	}
	return (1);
}

void	free_join(t_stack *f)
{
	free((f)->line);
	free((f)->s_join);
	free((f)->stack_b);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str1;

	str = (unsigned char *)s1;
	str1 = (unsigned char *)s2;
	i = 0;
	while ((str[i] || str1[i]) && i <= n)
	{
		if (str[i] > str1[i])
			return (str[i] - str1[i]);
		if (str[i] < str1[i])
			return (str[i] - str1[i]);
		i++;
	}
	return (0);
}

int	execut_instraction_utils(t_stack *exu, int i)
{
	if (ft_strncmp(exu->resulting[i], "rrr", ft_strlen(exu->resulting[i])) == 0)
		rrr(exu->n_arg, exu->size_b, exu->stack_a, exu->stack_b);
	else if (ft_strncmp(exu->resulting[i], "sa",
			ft_strlen(exu->resulting[i])) == 0)
		swap(exu->n_arg, exu->stack_a);
	else if (ft_strncmp(exu->resulting[i], "sb",
			ft_strlen(exu->resulting[i])) == 0)
		swap(exu->size_b, exu->stack_b);
	else if (ft_strncmp(exu->resulting[i], "ss",
			ft_strlen(exu->resulting[i])) == 0)
		ss(exu->n_arg, exu->size_b, exu->stack_a, exu->stack_b);
	else if (ft_strncmp(exu->resulting[i], "pa",
			ft_strlen(exu->resulting[i])) == 0)
		push_a(&exu->n_arg, &exu->size_b, exu->stack_a, exu->stack_b);
	else if (ft_strncmp(exu->resulting[i], "pb",
			ft_strlen(exu->resulting[i])) == 0)
		push_b(&exu->n_arg, &exu->size_b, exu->stack_a, exu->stack_b);
	else
		return (0);
	return (1);
}

int	execut_instraction(t_stack *exu, int i)
{
	if (ft_strncmp(exu->resulting[i], "ra", ft_strlen(exu->resulting[i])) == 0)
		rotate(exu->n_arg, exu->stack_a);
	else if (ft_strncmp(exu->resulting[i], "rb",
			ft_strlen(exu->resulting[i])) == 0)
		rotate(exu->size_b, exu->stack_b);
	else if (ft_strncmp(exu->resulting[i], "rr",
			ft_strlen(exu->resulting[i])) == 0)
		rr(exu->n_arg, exu->size_b, exu->stack_a, exu->stack_b);
	else if (ft_strncmp(exu->resulting[i], "rra",
			ft_strlen(exu->resulting[i])) == 0)
		rev_rotate(exu->n_arg, exu->stack_a);
	else if (ft_strncmp(exu->resulting[i], "rrb",
			ft_strlen(exu->resulting[i])) == 0)
		rev_rotate(exu->size_b, exu->stack_b);
	else
		return (execut_instraction_utils(exu, i));
	return (1);
}
