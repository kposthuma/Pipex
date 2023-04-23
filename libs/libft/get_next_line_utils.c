/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 11:42:07 by kposthum      #+#    #+#                 */
/*   Updated: 2022/11/17 14:11:02 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlengnl(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strchrgnl(char *string, char c)
{
	size_t			i;

	if (string == NULL)
		return (0);
	i = 1;
	while (string[i - 1])
	{
		if (string[i - 1] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_fillup(char *new, char *src, size_t j)
{
	int	i;

	i = 0;
	if (src)
	{
		while (src[i])
			new[j++] = src[i++];
	}
	new[j] = 0;
	return (new);
}

char	*ft_strjoingnl(char *string, char *buff)
{
	char	*new;
	int		j;

	new = malloc((ft_strlengnl(string) + ft_strlengnl(buff) + 1));
	if (!new)
		return (free (string), NULL);
	new = ft_fillup(new, string, 0);
	j = ft_strlengnl(string);
	new = ft_fillup(new, buff, j);
	free (string);
	return (new);
}
