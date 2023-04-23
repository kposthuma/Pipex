/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:59:06 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/26 14:11:50 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			j;
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;

	s1_cpy = (unsigned char *)s1;
	s2_cpy = (unsigned char *)s2;
	j = 0;
	while (j < n && (s1_cpy[j] || s2_cpy[j]))
	{
		if (s1_cpy[j] != s2_cpy[j])
			return (s1_cpy[j] - s2_cpy[j]);
		j++;
	}
	return (0);
}
