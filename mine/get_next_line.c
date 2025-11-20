/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:47:30 by brouane           #+#    #+#             */
/*   Updated: 2025/11/20 23:23:50 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_fill_line(char *working_line, int fd)
{
    // int bytes;
    
    // bytes = read(fd, working_line, BUFFER_SIZE);
    // if (bytes == -1)
    //     return (NULL);
    // working_line[bytes] = '\0';
    // return (working_line);


    char	*buffer;
	int	read_bytes;
    buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
    read_bytes = 1;
    printf("read_bytes: %d\n", read_bytes);

	while (!ft_strchr(working_line, '\n') && read_bytes > 0)
	{
        printf("read_bytes after: %d\n", read_bytes);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
        printf("read_bytes after after: %d\n", read_bytes);
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

char *ft_get_next_line(char *working_line)
{
    char* next_line;
    int i;

    i = 0;
    if (!working_line[i])
		return (NULL);
    while (working_line[i] && working_line[i] != '\n')
        i++;
    next_line = (char*)malloc(i + 2);
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

char *ft_get_crop_line(char *working_line)
{
    char* crop_line;
    int i;
    int j;

    i = 0;
    while (working_line[i] && working_line[i] != '\n')
        i++;
    if (!working_line[i])
	{
		free(working_line);
		return (NULL);
	}
    crop_line = (char*)malloc(ft_strlen(working_line) - i + 1);
    if (!crop_line)
        return (NULL);
    j = 0;
    while (working_line[++i])
        crop_line[j++] = working_line[i];
    crop_line[j] = 0;
    free(working_line);
    return (crop_line);
}

char *get_next_line(int fd)
{
    static char* working_line;
    char* next_line;
    // static int bool;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    // bool = 1;
    // if(!working_line && bool)
    // {
    //     printf("@");
    //     if (!(working_line = (char*)malloc(BUFFER_SIZE + 1)))
    //     return (NULL);
    //     bool = 0;
    //     printf("#\n");
    // }
            
    working_line = ft_fill_line(working_line, fd);
    if (!working_line)
		return (NULL);
    next_line = ft_get_next_line(working_line);
    
    // printf("HHHHH:%s|\n", next_line);
    working_line = ft_get_crop_line(working_line);
    // printf("TTTTTTTTT:%s|\n", next_line);
    
    return(next_line);
}

// int main()
// {
//     int fd = open("text.txt", O_RDONLY);

//     // char *holder = get_next_line(fd);
//     // printf("%s\n", holder);

//     // holder = get_next_line(fd);
//     // printf("%s\n", holder);

//     // holder = get_next_line(fd);
//     // printf("%s\n", holder);

//     // holder = get_next_line(fd);
//     // printf("%s\n", holder);
  
//     char *holder;
//     while ((holder = get_next_line(fd)) != NULL)
//     {
//         printf("%s------------", holder);
//     }

//     close(fd);
// }