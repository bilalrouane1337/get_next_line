/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:47:30 by brouane           #+#    #+#             */
/*   Updated: 2025/11/19 23:24:48 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_fill_line(char *working_line, int fd)
{
    size_t bytes;
    
    bytes = read(fd, working_line, BUFFER_SIZE);
    if (bytes == -1)
        return (NULL);
    return (working_line);
}

char *ft_get_next_line(char *working_line)
{
    char* next_line;
    int i;
    int j;

    i = 0;
    while (working_line[i] && working_line[i] != '\n')
        i++;
    next_line = (char*)malloc(i + 2);
    j = 0;
    while (j <= i)
    {
        next_line[j] = working_line[j];
        j++;
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
    if(!working_line[i])
        return (NULL);
    crop_line = (char*)malloc(ft_strlen(working_line) - i);
    j = 0;
    while (working_line[++i])
        crop_line[j++] = working_line[i];
    crop_line[i] = 0;
    return (crop_line);
}

char *get_next_line(int fd)
{
    static char* working_line;
    char* next_line;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if(!working_line)
        working_line = (char*)malloc(BUFFER_SIZE + 1);
    if (!working_line)
        return (NULL);
    working_line = ft_fill_line(working_line, fd);
    next_line = ft_get_next_line(working_line);
    working_line = ft_get_crop_line(working_line);
    // printf("%s\n", working_line);
    // printf("ffff\n");
    return(next_line);
}

int main()
{
    int fd = open("text.txt", O_RDONLY);

    char *holder = get_next_line(fd);
    printf("%s\n", holder);

    holder = get_next_line(fd);
    printf("%s\n", holder);

    holder = get_next_line(fd);
    printf("%s\n", holder);

    holder = get_next_line(fd);
    printf("%s\n", holder);
  
    // char *holder;
    // while ((holder = get_next_line(fd)) != NULL)
    // {
    //     printf("%s\n", holder);
    // }

    close(fd);
}