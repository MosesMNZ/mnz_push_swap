/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 08:33:05 by mmuamba           #+#    #+#             */
/*   Updated: 2018/08/07 13:37:12 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# define BUFF_SIZE 32

int		newline(char **stored_buff, char **line);
int		get_next_line(const int fd, char **line);
char	*strings_joining(char *s1, char *s2);

#endif
