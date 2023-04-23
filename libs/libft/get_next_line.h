/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 11:42:23 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/28 13:42:27 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<stdlib.h>
# include<unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200000
# endif

char	*get_next_line(int fd);
char	*ft_make_string(char *string, int fd);
char	*ft_circumcise(char *string);
char	*ft_nextline(char *string);

char	*ft_strjoingnl(char *string, char *buff);
char	*ft_fillup(char *new, char *src, size_t j);
size_t	ft_strchrgnl(char *string, char c);
size_t	ft_strlengnl(char *s);

#endif