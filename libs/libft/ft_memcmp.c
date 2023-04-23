/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:59:30 by kposthum      #+#    #+#                 */
/*   Updated: 2022/10/11 13:53:26 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			j;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	j = 0;
	while (j < n)
	{
		if (a[j] != b[j])
			return (a[j] - b[j]);
		j++;
	}
	return (0);
}
