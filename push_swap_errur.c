/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errur.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:06:34 by maddou            #+#    #+#             */
/*   Updated: 2023/01/18 17:47:02 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chec_space_null(int argc, char *argv[])
{
	int	i;
	int	j;

	if (chek_plus(argc, argv) == 0)
		return (0);
	i = 1;
	while (i <= argc)
	{
		j = 0;
		while (argv[i][j] == ' ' || argv[i][j] == '+' || argv[i][j] == '-')
		{
			if (argv[i][j + 1] == '\0' ||
				(argv[i][j] == '-' && argv[i][j + 1] == '-') ||
				(argv[i][j] == '+' && argv[i][j + 1] == '+') ||
				(argv[i][j] == '+' && argv[i][j + 1] == '+') ||
				(argv[i][j] == '-' && argv[i][j + 1] == '-'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	errur(void)
{
	write(2, "ERRUR", 5);
	exit(1);
}

void	ft_free(char **split, int *stack_a, char *sjoin, int number)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < number)
	{
		free(split[i]);
		i++;
	}
	free(split);
	free(stack_a);
	free(sjoin);
	errur();
}

char	*join(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*join;

	i = 1;
	j = 0;
	if (chec_space_null(argc, argv) == 0)
		return (0);
	join = malloc(1);
	if (!join)
		return (0);
	join[0] = '\0';
	while (i <= argc)
	{
		join = ft_strjoin(join, argv[i]);
		if (argc != i)
			join = ft_strjoin(join, " ");
		i++;
	}
	return (join);
}

int	*chek(int argc, char *argv[], int *number_argument)
{
	char	*sjoin;
	int		i;
	char	**split;
	int		*stack_a;

	i = 0;
	sjoin = join(argc - 1, argv);
	if (sjoin == 0 || chek_digit(sjoin) == 0)
		errur();
	*number_argument = number(sjoin) + 1;
	split = ft_split(sjoin, ' ');
	stack_a = malloc(*number_argument * sizeof(int));
	if (!stack_a)
		return (0);
	while (i < *number_argument)
	{
		stack_a[i] = ft_atoi(split[i]);
		i++;
	}
	if (chek_dobble(stack_a, *number_argument) == 0)
		ft_free(split, stack_a, sjoin, *number_argument);
	return (stack_a);
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