/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:24:29 by abenabde          #+#    #+#             */
/*   Updated: 2025/11/24 16:24:29 by abenabde         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

#include <stdio.h>
#define BUFFER_SIZE 6

void	move_buff(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while(src[i])
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

void	ft_strcpy_plus(char *dest, char *src, unsigned int start, unsigned int max)
{
	unsigned int	i;
	
	i = 0;
	while (i < max)
	{
		dest[start + i] = src[i];
		i++;
	}
	dest[start + i] = '\0';
}

char	*incr_line(char **old, char *add, unsigned int len)
{
	unsigned int	start;
	char			*new;

	start = 0;
	if (*old != NULL)
	{
		while (old[0][start])
			start++;
	}
	new = malloc(sizeof(char) * (len + start + 1));
	if (new == NULL)
	{
		if (*old != NULL)
			free(*old);
		return (NULL);
	}
	ft_strcpy_plus(new, *old, 0, start);
	ft_strcpy_plus(new, add, start, len);
	if (*old != NULL)
		free(*old);
	*old = new;
	return (*old);
}

char	*get_line(char **line, char *buff, int fd, int *check)
{
	unsigned int	i;

	*line = NULL;
	*check = 1;
	while (1)
	{
			if (*check < 1)
			{
				return (NULL);
			}
			i = 0;
			while (buff[i] && buff[i] != '\n')
				i++;
			if (buff[i] == '\n')
			{
				incr_line(line, buff, i + 1);
				move_buff(buff, (buff + i + 1));
				return (*line);
			}
			incr_line(line , buff, i + 1);
			if (*line == NULL)
				return (NULL);
		*check = read(fd, buff, BUFFER_SIZE);
		buff[*check] = '\0';
	}
	return (NULL);
}


char	*get_next_line(int fd)
{
	unsigned int	i;
	int				check;
	static char		buff[BUFFER_SIZE + 1];
	char			*line;

	line = NULL;
	check = 1;
	get_line(&line, buff, fd, &check);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}

	return (line);
}


/*
#include <fcntl.h>
#include <stdio.h>
int	main()
{
	
	int i = 0;
	int fic = open(".new", O_RDONLY);
	char *line = get_next_line(fic);
	while (i < 10)
	{
		printf("\nRESULT:%s|%d|E\n", line, i);
		free(line);
		line = get_next_line(fic);
		i++;
	}
	free(line);
	close(fic);
	


}
*/



