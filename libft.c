/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:18:11 by maddou            #+#    #+#             */
/*   Updated: 2023/01/18 16:53:57 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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
	{
		write(2, "ERROR\n", 5);
		exit(1);
	}
	return ((int)nb * sign);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*p;
	int		len;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (s1[i])
		p[j++] = s1[i++];
	i = 0;
	while (s2[i])
		p[j++] = s2[i++];
	p[i + j] = '\0';
	free(s1);
	return (p);
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

char	**ft_split(char *str, char c)
{
	int		i;
	int		j;
	int		start;
	char	**result;

	i = 0;
	j = 0;
	result = (char **)malloc((number(str) + 1 + 1) * sizeof(char *));
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
