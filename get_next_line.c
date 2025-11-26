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

unsigned int	read_len(int fd)
{
	unsigned int	i;
	int				check;
	char			buff[1];

	i = 0;
	check = 1;
	while (buff[0] != '\n' && check == 1)
	{
		check = read(fd, buff, 1);
		i++;
	}
	return (i);
}

void	incr_line(char *old, char *add, unsigned int line)
{
	int		i;
	int		start;
	char	*new;

	i = 0;

	while (old[start])
		start++;

	new = malloc(sizeof(char) * (line + start));
	if (!new)
		return (NULL);

	while (old[i])
	{
		new[i] = old[i];
		i++
	}

	i = 0;
	while (i < line)
	{
		new[start + i] = add[i]
		i++;
	}
	new[start + i] = '\0';
}

char	*get_line(int fd)
{
	unsigned int	i;
	int				check;
	char			buff[1001];
	char			*ary;

	i = 0;
	check = 1;
	while (check == 1)
	{
		check = read(fd, buff, 1000);

		buff[check] = '\0';
		while (buff[i] != '\n' && buff[i])
		{
			if (buff[i] == '\n')
				break ;
			i++;
		}
		incr_line(buff, ary, i):
	}
//	ary = malloc(sizeof(char) * (i + 1));
//	ft_strcpy(buff, ary);
}


char *get_next_line(int fd)
{
	char			*ary;
	unsigned int	i;
	unsigned int	size;

	size = read_len(fd);
	ary = malloc(sizeof(char) * size);
	if (ary == NULL)
		return (NULL);
	//read(fd, ary, size);
	ary[size] = '\0';

	return (ary);
}


#include <fcntl.h>
#include <stdio.h>
int	main()
{
	int fic = open("new", O_RDONLY);
//	printf("%d, %dfd\n", read_len(fic), fic);
	char *line = get_next_line(fic);
	printf("%s\n", line);
	free(line);

	close(fic);
}
