/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:03:40 by aeminian          #+#    #+#             */
/*   Updated: 2024/02/17 16:23:03 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include <string.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}


char	*strjoin(char const *s1, char const *s2)
{
	char	*memory;
	char	*result;
	size_t	size;

	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	memory = (char *)malloc(size +1);
	if (!memory)
		return (NULL);
	*(memory + size) = 0;
	result = memory;
	while (s1 && *s1)
		*memory++ = *s1++;
	while (*s2)
		*memory++ = *s2++;
	return (result);
}
int	found_new_line(char *line)
{
	if (line == NULL)
		return (0);
	
	while (*line)
	{
		if (*line == '\n')
			return (1);
		line++;
	}
	return (0);
}

size_t	new_line_len(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (0);
	while (line[i])
	{
		if (line[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}


char * read_file(int fd, char *line)
{
	char *buffer;
	int	byte_read;
	static char *new_line;
	new_line = line;
	while (!found_new_line(new_line))
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		new_line = strjoin(new_line, buffer);
	}

	return (new_line);

}
char	*get_new_line(char *line)
{
	char	*next_line;
	size_t		len;
	int i;
	i = 0;
	if(line == NULL)
		return (NULL);
	len = new_line_len(line);
	next_line = (char *)malloc(len);
	if (!next_line)
		return (NULL);
	while (next_line[i] != '\n' && i < (int)len - 1)
	{
		next_line[i] = line[i];
		i++;
	}
	next_line[len] = 0;
	return (next_line);
}
void	fetch(char *line)
{
	char *buf;
	int	i;
	int j;

	i = 0;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return ;
	while (line[i] != 0 && line[i] != '\n')
		i++;
	j = 0;
	while (line[i] != 0 && i++ && j++)
		buf [j] = line[i];
	buf[j + 1] = 0;
}
char *get_next_line(int fd)
{
	static char	*line;
	char	*new_line;

    line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);

	line = read_file(fd, line);
	if(line == NULL)
		return (NULL);
	new_line = get_new_line(line);
	fetch(line);
    return (new_line);

}


int main(void)
{
    int fd;
	fd = open("example.txt", O_RDWR);
    char* line = get_next_line(fd);
	printf("%s\n", line);
    printf("%s\n", line);
	close(fd);
    return (0);

}

