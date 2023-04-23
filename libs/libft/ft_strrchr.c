/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:59:00 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/26 14:07:17 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*s_cpy;
	unsigned char	x;
	int				i;

	s_cpy = (char *)s;
	x = c;
	i = 0;
	while (s_cpy[i])
		i++;
	while (i >= 0)
	{
		if (s_cpy[i] == x)
			return (&s_cpy[i]);
		i--;
	}
	return (NULL);
}
