/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:37:59 by brouane           #+#    #+#             */
/*   Updated: 2025/11/21 19:38:00 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *working_line, char *temp);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*new_working_line(char *working_line);
char	*ft_get_line(int fd, char *working_line);
char	*ft_get_next_line(char	*working_line);

#endif
