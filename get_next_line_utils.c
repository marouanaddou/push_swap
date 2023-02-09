/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:04:19 by maddou            #+#    #+#             */
/*   Updated: 2023/02/08 21:07:05 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_calloc(int count, int size)
{
	char	*p;
	int		multi;
	int		i;

	multi = count * size;
	i = 0;
	p = malloc(multi);
	if (!p)
		return (0);
	while (i < multi)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}

char	*ft_strjoin(char *sta, char *buffer)
{
	int		i;
	int		j;
	int		len;
	char	*new_sta;

	i = 0;
	j = 0;
	len = ft_strlen(sta) + ft_strlen(buffer);
	new_sta = ft_calloc(len + 1, 1);
	if (!new_sta)
		return (0);
	while (sta[i])
	{
		new_sta[i] = sta[i];
		i++;
	}
	while (buffer[j])
		new_sta[i++] = buffer[j++];
	free(sta);
	return (new_sta);
}

char	*ft_save_next(char *sta)
{
	int		len;
	char	*c_sta;
	int		j;

	len = 0;
	while (sta[len] != '\0' && sta[len] != '\n')
		len++;
	if (!sta[len])
	{
		free(sta);
		return (0);
	}
	if (sta[len] == '\n')
		len++;
	c_sta = ft_calloc(ft_strlen(sta) - len + 1, 1);
	if (!c_sta)
		return (0);
	j = 0;
	while (sta[len])
		c_sta[j++] = sta[len++];
	free(sta);
	return (c_sta);
}
