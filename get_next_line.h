/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:24:30 by abenabde          #+#    #+#             */
/*   Updated: 2025/11/24 16:24:30 by abenabde         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <unistd.h>

void	del_buff(char *buff);
void	move_buff(char *dest, char *src);
void	ft_strcpy_plus(char *dest, char *src, int start, int max);
int		incr_line(char **old, char *add, int len);
int		create_line(char **line, char *buff, int fd, int *check);
char	*get_next_line(int fd);

#endif
