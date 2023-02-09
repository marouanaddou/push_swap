/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:17:02 by maddou            #+#    #+#             */
/*   Updated: 2023/02/08 11:57:49 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	if (!s)
		return (NULL);
	i = 0;
	p = malloc(len + 1);
	if (!p)
		return (0);
	while (start < ft_strlen(s) && s[start + i] != '\0' && i < len)
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	ft_atoi(char *str)
{
	int				i;
	long long int	nb;
	int				sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
		nb = nb * 10 + str[i++] - 48;
	if ((nb * sign) > 2147483647 || (nb * sign) < -2147483648)
		errur();
	return ((int)(nb * sign));
}

char	**ft_split(char *str, char c, int number_argument)
{
	int		i;
	int		j;
	int		start;
	char	**result;

	i = 0;
	j = 0;
	result = (char **)malloc((number_argument + 1) * sizeof(char *));
	if (!result)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		start = i;
		while (str[i] != c && str[i] != '\0')
			i++;
		if ((i - start) > 0)
			result[j++] = ft_substr(str, start, (i - start));
	}
	result[j] = NULL;
	return (result);
}
