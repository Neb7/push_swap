/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:45:01 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/18 17:47:23 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/*Get_next_line*/

char	*get_next_line(int fd);
char	*gnl_moinslbuffer(char *buffer, size_t t);
char	*gnl_mettrea0(void);
char	*gnl_substr(char *s, unsigned int start, size_t len);
char	*gnl_suite(char *buffer, int fd, ssize_t *l);

/*Get_next_line_util*/

char	*gnl_strcpycat(char *dest, char *src, char *src2);
char	*gnl_read(int fd, ssize_t *l);
size_t	gnl_strlen(char *str);
ssize_t	gnl_strchar(char *str, int c);
char	*gnl_free_buffer(char *buffer);

#endif
