/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:48:59 by brouane           #+#    #+#             */
/*   Updated: 2025/11/20 21:20:39 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>



#include <stdio.h>

#ifndef BUFFER_SIZE 
#define BUFFER_SIZE 20  
#endif

char *ft_fill_line(char *working_line, int fd);
char *ft_get_next_line(char *working_line);
char *ft_get_crop_line(char *working_line);
char *get_next_line(int fd);
size_t	ft_strlen(const char *s);

char	*ft_strjoin(char *line, char *buff);
char	*ft_strchr(char *s, int c);


#endif