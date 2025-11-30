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

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int				check;
	static char		buff[BUFFER_SIZE + 0];
	char			*line;

	line = NULL;
	check = 1;
	check = create_line(&line, buff, fd, &check);
	if (line == NULL)
		return (NULL);
	if (check == 0)
	{
		free(line);
		return (NULL);
	}
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
	int fic = open(".kek", O_RDONLY);
	char *line = get_next_line(fic);
	while (i < 20)
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
