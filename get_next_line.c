/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:37:56 by brouane           #+#    #+#             */
/*   Updated: 2025/11/21 19:37:57 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(int fd, char *working_line)
{
	char	*temp;
	ssize_t	bytes_readen;

	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	bytes_readen = 1;
	while (!ft_strchr(working_line, '\n') && bytes_readen > 0)
	{
		bytes_readen = read(fd, temp, BUFFER_SIZE);
		if (bytes_readen == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[bytes_readen] = '\0';
		working_line = ft_strjoin(working_line, temp);
	}
	free(temp);
	return (working_line);
}

char	*new_working_line(char *working_line)
{
	int		i;
	int		j;
	char	*new_working_line;

	i = 0;
	while (working_line[i] && working_line[i] != '\n')
		i++;
	if (!working_line[i])
	{
		free(working_line);
		return (NULL);
	}
	new_working_line = (char *)malloc(sizeof(char) * (ft_strlen(working_line) - i + 1));
	if (!new_working_line)
		return (NULL);
	i++;
	j = 0;
	while (working_line[i])
		new_working_line[j++] = working_line[i++];
	new_working_line[j] = '\0';
	free(working_line);
	return (new_working_line);
}

char	*ft_get_next_line(char *working_line)
{
	int		i;
	char	*next_line;

	i = 0;
	if (!working_line[i])
		return (NULL);
	while (working_line[i] && working_line[i] != '\n')
		i++;
	next_line = (char *)malloc(i + 2);
	if (!next_line)
		return (NULL);
	i = 0;
	while (working_line[i] && working_line[i] != '\n')
	{
		next_line[i] = working_line[i];
		i++;
	}
	if (working_line[i] == '\n')
	{
		next_line[i] = working_line[i];
		i++;
	}
	next_line[i] = '\0';
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char			*working_line;
	char				*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	working_line = ft_get_line(fd, working_line);
	if (!working_line)
		return (NULL);
	next_line = ft_get_next_line(working_line);
	working_line = new_working_line(working_line);
	return (next_line);
}