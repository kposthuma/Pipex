/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 13:00:33 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/26 14:16:56 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1_cpy;
	char	*s2_cpy;
	char	*joined;
	int		i;

	i = ft_strlen(s1) + ft_strlen(s2);
	s1_cpy = (char *)s1;
	s2_cpy = (char *)s2;
	joined = ft_calloc((i + 1), sizeof(char));
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, s1_cpy, (ft_strlen(s1) + 1));
	ft_strlcat(joined, s2_cpy, (i + 1));
	return (joined);
}
