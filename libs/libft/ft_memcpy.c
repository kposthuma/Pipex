/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:59:28 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/16 15:51:45 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*a;
	char	*x;

	i = 0;
	a = (char *)dst;
	x = (char *)src;
	if (a == NULL && x == NULL && n > 0)
		return (NULL);
	while (i < n)
	{
		a[i] = x[i];
		i++;
	}
	return (dst);
}
