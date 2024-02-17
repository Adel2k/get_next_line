/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:26:55 by aeminian          #+#    #+#             */
/*   Updated: 2024/02/17 16:22:41 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_new_line(char *line)
{
	while (1)
	{
		if (*line == '\n')
			return (1);
		if (*line == '\0')
			break ;
		line++;
	}
	return (0);
}
/*
int	new_line_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' || line[i] != 0)
		i++;
	return (i);
}
char	*left_side(char *line)
{
	char	*str;
	char	*buf;
	int		len;

	str = line;
	len = new_line_len(str);
	while (*str != '\n')
		*str++;
	buf = malloc(len);
	if (!buf)
		return (NULL);
	read(fd, buf, len);

}*/

char	*ft_strchr(const char *str, const int c)
{
	char	*ptr;

	ptr = (char *)str;
	while (1)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		if (*ptr == '\0')
			break ;
		ptr++;
	}
	return (NULL);
}
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*strjoin(char const *s1, char const *s2)
{
	char	*memory;
	char	*result;
	size_t	size;

	if (!s1 || !s2)
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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*(src + i))
		i++;
	if (!size)
		return (i);
	while (--size && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (i);
}





/*
int main ()
{
	char *str = "hello wprld \n alo???";
	printf("%s\n", found_new_line(str));
}*/
