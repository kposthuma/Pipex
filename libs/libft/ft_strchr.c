/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:59:20 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/26 14:23:12 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*s_cpy;
	unsigned char	x;
	size_t			i;
	size_t			j;

	s_cpy = (char *)s;
	x = c;
	i = 0;
	j = ft_strlen(s_cpy) + 1;
	while (i < j)
	{
		if (s_cpy[i] == x)
			return (&s_cpy[i]);
		i++;
	}
	return (NULL);
}
