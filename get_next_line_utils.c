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


size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


size_t	new_line_len(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			i++;
			printf("------\n");
			return (i);
		}
		printf("****\n");
		i++;
	}
	return (i);
}

/*
int main ()
{
	char *str = "";
	char *ptr = "bbbbbbb";
	printf("%s\n", strjoin(str, ptr));
}*/