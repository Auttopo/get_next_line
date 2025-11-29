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

#define BUFFER_SIZE 3

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

unsigned int	no_null_strlen(char *str)
{
	unsigned int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
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
	unsigned int	i;
	unsigned int	start;
	char			*new;

	i = 0;
	start = no_null_strlen(*old);
	new = malloc(sizeof(char) * (len + start + 1));
	if (new == NULL)
	{
//		if (*old != NULL)
			free(*old);
		return (NULL);
	}
	ft_strcpy_plus(new, *old, 0, start);
	ft_strcpy_plus(new, add, start, len);
//	if (*old != NULL)
		free(*old);
	*old = new;
	return (*old);
}

int	is_new(char **line, char *buff)
{
	unsigned int	i;
	unsigned int	end;
	unsigned int	len;

	i = 0;
	*line = NULL;

	while (buff[i] != '\n' && buff[i] && i < BUFFER_SIZE)
		i++;
	if (buff[i] != '\n' || buff[i] == '\n' && i == BUFFER_SIZE - 1)
		return (1);
	i++;
	len = i;
	while (buff[len] != '\n' && buff[len] && len < BUFFER_SIZE)
		len++;
	if (buff[len] == '\n')
		len++;
	*line = malloc(sizeof(char) * (len - i + 1));
	if (*line == NULL)
		return (0);
	ft_strcpy_plus(*line, buff + i, 0, len - i);
	if (buff[len - 1] == '\n')
	{
		move_buff(buff, buff + i);
		return (2);
	}
	move_buff(buff, buff + i);
	return (1);
}

char	*get_next_line(int fd)
{
	unsigned int	i;
	int				check;
	static char		buff[BUFFER_SIZE];
	char			*line;

	check = is_new(&line, buff);
//	__builtin_printf("[%s]BUFF\n", buff);
	if (check == 0)
		return (NULL);
	if (check == 2)
		return (line);
	while (1)
	{
		check = read(fd, buff, BUFFER_SIZE);
		if (check < 1)
		{
//			del_buff(buff, BUFFER_SIZE);
			free (line);
			return (NULL);
		}
		buff[check] = '\0';
		i = 0;
		while (buff[i] && buff[i] != '\n')
			i++;
		if (buff[i] == '\n')
			return (incr_line(&line, buff, i + 1));
		incr_line(&line , buff, check);
		if (line == NULL)
			return (NULL);
	}
	return (NULL);
}



#include <fcntl.h>
#include <stdio.h>
int	main()
{
/*	int fic = open("new", O_RDONLY);
	char *line = get_line(fic);
	char *line2 = get_line(fic);
	printf("\nRESULT:%s|E\n", line);
	printf(":RESUL2:%s|E\n", line2);
	free(line);
	free(line2);

	close(fic);
*/

	int i = 0;
	int fic = open("new", O_RDONLY);
	char *line = get_next_line(fic);
	while (i < 10)
	{
		printf("\nRESULT%s|%d|E\n", line, i);
		free(line);
		line = get_next_line(fic);
		i++;
	}
	free(line);
	close(fic);

/*	char buff[15];
	int i = 0;
	buff[10] = -1;
	buff[11] = -1;
	while (i < 15)
	{
		printf("%d\n", buff[i]);
		i++;
	}*/
}
