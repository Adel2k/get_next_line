/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:59:36 by aeminian          #+#    #+#             */
/*   Updated: 2024/02/17 14:57:29 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include <string.h>
size_t ft_strlen(const char *str);
char	*get_next_line(int fd);
int		found_new_line(char *line);
int		found_new_line(char *line);
size_t		new_line_len(char *line);
char	*left_side(char *line);
char	*strjoin(char const *s1, char const *s2);
#endif
