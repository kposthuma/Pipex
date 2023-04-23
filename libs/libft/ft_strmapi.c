/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 13:00:42 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/26 14:27:12 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s_cpy;
	char			*newstr;

	i = 0;
	s_cpy = (char *)s;
	newstr = (char *)ft_calloc((ft_strlen(s_cpy) + 1), sizeof(char));
	if (!newstr)
		return (NULL);
	while (s_cpy[i])
	{
		newstr[i] = f(i, s_cpy[i]);
		i++;
	}
	return (newstr);
}
