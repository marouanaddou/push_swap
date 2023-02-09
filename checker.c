/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:03:57 by maddou            #+#    #+#             */
/*   Updated: 2023/02/09 21:59:15 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_split(char **split, char *sjoin, char x)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	if (x != 'f')
		free(sjoin);
	free(split);
}

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

int	number_instruction(char *str)
{
	int	i;
	int	n_instruction;

	i = 0;
	n_instruction = 0;
	while (str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] != '\n')
			n_instruction += 1;
		else if (str[i] != '\n' && str[i + 1] == '\0')
			n_instruction += 1;
		i++;
	}
	return (n_instruction);
}

void	execut(t_stack *s)
{
	s->n_instraction = number_instruction(s->s_join);
	(s)->resulting = ft_split((s)->s_join, '\n', (s)->n_instraction);
	s->i = 0;
	s->size_b = 0;
	while (s->i < s->n_instraction)
	{
		(s)->rule = execut_instraction(s, s->i);
		if ((s)->rule == 0)
		{
			free_split((s)->resulting, (s)->s_join, 'f');
			free_join(s);
			free(s->stack_a);
			errur();
		}
		s->i++;
	}
	if (chek_order((s)->stack_a, s->n_arg) == 1 && s->size_b == 0)
		write(1, "OK\n", 3);
	else
	{
		write(1, "KO\n", 3);
		free((s)->stack_a);
	}
	free_split((s)->resulting, (s)->s_join, 'f');
	free_join(s);
}

int	main(int argc, char *argv[])
{
	t_stack	s;

	if (argc > 1)
	{
		(s).s_join = malloc(1);
		if (!(s).s_join)
			return (0);
		(s).stack_a = chek(argc, argv, &s.n_arg);
		(s).stack_b = malloc((s).n_arg);
		if (!(s).stack_b)
			return (0);
		while (1)
		{
			(s).line = get_next_line(0);
			if (!(s).line)
				break ;
			(s).s_join = ft_strjoin((s).s_join, (s).line);
			chek_free(&s);
		}
		execut(&s);
	}
	return (0);
}
