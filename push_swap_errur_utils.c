/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errur_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:58:17 by maddou            #+#    #+#             */
/*   Updated: 2023/01/24 12:56:14 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	number(char *str)
{
	int	i;
	int	number_space;

	i = 0;
	number_space = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0')
			number_space += 1;
		i++;
	}
	return (number_space);
}

int	ft_isdigit(int c)
{
	if (!((c >= '0' && c <= '9') || c == 32 || c == '+' || c == '-'))
		return (0);
	else
		return (1);
}

int	chek_digit(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
		{
			free(str);
			return (0);
		}
		if ((str[i] >= '0' && str[i] <= '9') && (str[i + 1] == '+' || str[i
					+ 1] == '-'))
		{
			free(str);
			return (0);
		}
		i++;
	}
	return (1);
}
// number -1 mo9arana 1 -- 0 hna ma3ndnach zero kykhrj mn arrray oyjibha mn 3ndo

int	chek_double(int *str, int number)
{
	int	i;
	int	j;

	i = 0;
	if (str == NULL)
		return (0);
	while (i < number)
	{
		j = i + 1;
		while (j < number)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	chek_plus(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i <= argc)
	{
		if (argv[i++][0] == '\0')
			return (0);
	}
	i = 1;
	while (i <= argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '+' || argv[i][j] == '-')
			{
				if (argv[i][j + 1] == ' ' || argv[i][j + 1] == '\0')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
