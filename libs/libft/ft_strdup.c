/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:59:18 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/26 14:24:04 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*s1_cpy;
	size_t	i;

	s1_cpy = (char *)s1;
	i = 0;
	dup = (char *)ft_calloc((ft_strlen(s1_cpy) + 1), sizeof(char));
	if (!dup)
		return (NULL);
	while (s1_cpy[i])
	{
		dup[i] = s1_cpy[i];
		i++;
	}
	return (dup);
}
