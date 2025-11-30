/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:24:35 by abenabde          #+#    #+#             */
/*   Updated: 2025/11/24 16:24:35 by abenabde         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	move_buff(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < BUFFER_SIZE + 1)
	{
		dest[i] = '\0';
		i++;
	}
}

void	ft_strcpy_plus(char *dest, char *src, int start, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		dest[start + i] = src[i];
		i++;
	}
	dest[start + i] = '\0';
}

char	*incr_line(char **old, char *add, int len)
{
	int		start;
	char	*new;

	start = 0;
	if (*old != NULL)
	{
		while (old[0][start])
			start++;
	}
	new = malloc(sizeof(char) * (len + start + 1));
	if (new == NULL)
	{
		free(*old);
		return (NULL);
	}
	ft_strcpy_plus(new, *old, 0, start);
	ft_strcpy_plus(new, add, start, len);
	free(*old);
	*old = new;
	return (*old);
}

int	get_line(char **line, char *buff, int fd, int *check)
{
	int	i;

	while (1)
	{
		if (*check < 1)
			return (0);
		i = 0;
		while (buff[i] && buff[i] != '\n')
			i++;
		if (buff[i] == '\n')
		{
			incr_line(line, buff, i + 1);
			if (*line == NULL)
				return (0);
			move_buff(buff, (buff + i + 1));
			return (1);
		}
		incr_line(line, buff, i + 1);
		if (*line == NULL)
			return (0);
		*check = read(fd, buff, BUFFER_SIZE);
		buff[*check] = '\0';
	}
	return (0);
}
