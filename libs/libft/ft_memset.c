/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:59:23 by kposthum      #+#    #+#                 */
/*   Updated: 2022/10/11 16:10:30 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;
	unsigned char	x;
	size_t			i;

	a = (unsigned char *)b;
	x = c;
	i = 0;
	while (i < len)
	{
		a[i] = x;
		i++;
	}
	return (b);
}
