/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 13:01:07 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/26 17:20:18 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_size(char *b, size_t start, size_t len)
{
	size_t	j;

	j = 0;
	while (b[start++] && j < len)
		j++;
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*s_cpy;
	size_t	j;

	s_cpy = (char *)s;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	j = ft_size(s_cpy, start, len);
	substr = ft_calloc((j + 1), sizeof(char));
	if (!substr)
		return (NULL);
	j = 0;
	while (j < len && s_cpy[start])
		substr[j++] = s_cpy[start++];
	return (substr);
}
