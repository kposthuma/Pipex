/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 13:01:01 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/28 13:12:43 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1_cpy;
	char	*s2;
	size_t	i;
	size_t	j;

	s1_cpy = (char *)s1;
	if (!s1_cpy && !set)
		return (NULL);
	if (ft_strlen(s1_cpy) == 0)
		return ((char *)ft_calloc(1, sizeof(char)));
	i = 0;
	j = ft_strlen(s1_cpy) - 1;
	while (ft_strchr(set, s1_cpy[i]) != 0)
		i++;
	while (ft_strchr(set, s1_cpy[j]) != 0)
		j--;
	s2 = ft_substr(s1_cpy, i, (1 + j - i));
	return (s2);
}
