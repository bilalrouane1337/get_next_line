/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:37:45 by brouane           #+#    #+#             */
/*   Updated: 2025/11/21 19:37:46 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(int fd, char *working_line)
{
	char	*buffer;
	ssize_t	read_bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(working_line, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		working_line = ft_strjoin(working_line, buffer);
	}
	free(buffer);
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
	static char			*working_line[OPEN_MAX];
	char				*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	working_line[fd] = ft_get_line(fd, working_line[fd]);
	if (!working_line[fd])
		return (NULL);
	next_line = ft_get_next_line(working_line[fd]);
	working_line[fd] = new_working_line(working_line[fd]);
	return (next_line);
}