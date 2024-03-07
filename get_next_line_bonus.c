/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:51:36 by aeminian          #+#    #+#             */
/*   Updated: 2024/03/06 20:08:23 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_new_line(char *line)
{
	char	*next_line;
	size_t	len;
	int		i;

	i = 0;
	if (!line || !*line)
		return (NULL);
	len = new_line_len(line);
	next_line = (char *)malloc(len + 1);
	if (!next_line)
		return (NULL);
	while (line[i] != '\n' && i < (int)len)
	{
		next_line[i] = line[i];
		i++;
	}
	next_line[i] = '\n';
	next_line[len] = 0;
	return (next_line);
}

char	*fetch(char *line)
{
	char	*buf;
	int		i;
	int		j;

	i = 0;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (line[i] != 0 && line[i] != '\n')
		i++;
	if (line[i] == 0)
	{
		free(line);
		free(buf);
		return (NULL);
	}
	if (line[i] == '\n')
		i++;
	j = 0;
	while (line[i] != 0 && j < BUFFER_SIZE)
		buf [j++] = line[i++];
	buf[j] = 0;
	free(line);
	return (buf);
}

char	*read_line(int fd, char *line, char *buffer)
{
	int		read_byte;
	char	*tmp;

	read_byte = 1;
	while (!found_new_line(line) && read_byte != 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_byte] = 0;
		tmp = line;
		line = strjoin(line, buffer);
		free(tmp);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line[fd] = read_line(fd, line[fd], buffer);
	if (line[fd] == NULL)
		return (NULL);
	buffer = get_new_line(line[fd]);
	line[fd] = fetch(line[fd]);
	return (buffer);
}
