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

/*char *get_next_line(int fd)
{
	static char	*line;
	char	*saved;

	saved = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, BUFFER_SIZE))
		return(NULL);
	line = malloc(BUFFER_SIZE);
	if (!line)
		return (NULL);
	read(fd , line, BUFFER_SIZE);
	if (!found_new_line(line))
	{
		saved = strjoin (saved, line);
	}
	else
	{
		while (*line != '\n')
			line++;
		saved = strjoin (saved, line);
	}
	return (saved);

}
*/
char *get_next_line(int fd)
{
    static char *line = NULL;
    char *saved = NULL;
    char buffer[BUFFER_SIZE + 1];
    ssize_t bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read <= 0)
        return NULL;

    buffer[bytes_read] = '\0';

    line = malloc(BUFFER_SIZE + 1);
    if (!line)
        return NULL;

    line = strcpy(line, buffer);

    if (!found_new_line(line))
    {
        saved = strjoin(saved, line);
    }
    else
    {
        char *newline_pos = strchr(line, '\n');
        *newline_pos = '\0'; 
		saved = strjoin(saved, line);
        line = newline_pos + 1;
    }

    return saved;
}
/*
int main(void)
{
    int file_descriptor = open("example.txt", O_RDONLY);
    char* line = get_next_line(file_descriptor);
	free(line);

    close(file_descriptor);
    return (0);
}
*/
