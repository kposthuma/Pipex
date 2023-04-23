/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 11:41:48 by kposthum      #+#    #+#                 */
/*   Updated: 2023/01/12 10:35:21 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*get_next_line(int fd)
{
	char		*nextline;
	static char	*string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (string != NULL)
		string = ft_circumcise(string);
	string = ft_make_string(string, fd);
	if (!string)
		return (NULL);
	nextline = ft_nextline(string);
	if (!nextline)
		return (NULL);
	return (nextline);
}

char	*ft_circumcise(char *string)
{
	char	*newstring;
	size_t	i;
	size_t	j;

	i = ft_strchrgnl(string, '\n');
	if (i == 0)
		return (free(string), NULL);
	newstring = malloc((ft_strlengnl(string) - i + 1));
	if (!newstring)
		return (free(string), NULL);
	j = 0;
	while (i < ft_strlengnl(string))
		newstring[j++] = string[i++];
	newstring[j] = 0;
	return (free(string), newstring);
}

char	*ft_make_string(char *string, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		check;

	check = BUFFER_SIZE;
	while (!ft_strchrgnl(string, '\n') && check == BUFFER_SIZE)
	{
		check = read(fd, buff, BUFFER_SIZE);
		if (check == -1 || (check == 0 && ft_strlengnl(string) == 0))
			return (free(string), NULL);
		buff[check] = 0;
		string = ft_strjoingnl(string, buff);
		if (!string)
			return (NULL);
	}
	return (string);
}

char	*ft_nextline(char *string)
{
	size_t	i;
	char	*nextline;

	i = ft_strchrgnl(string, '\n');
	if (i == 0)
		i = ft_strlengnl(string);
	nextline = malloc(i + 1);
	if (!nextline)
		return (free(string), NULL);
	nextline[i] = 0;
	while (i--)
		nextline[i] = string[i];
	return (nextline);
}

// #include<fcntl.h>
// # include<stdio.h>

// int	main(void)
// {
// 	char	*nl;
// 	int		fd;

// 	fd = open ("numbers.txt", O_RDONLY);
// 	for (int i = 0; i < 10; i++)
// 	{
// 		nl = get_next_line(fd);
// 		printf("newline: %s loop: %i\n\n", nl, i);
// 		if (nl != NULL)
// 			free (nl);
// 	}
// 	close(fd);
// 	return (0);
// }