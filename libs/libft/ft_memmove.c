/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:59:25 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/16 15:51:33 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static void	moveplus(char *a, char *x, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		a[i] = x[i];
		i++;
	}
}

static void	moveminus(char *a, char *x, size_t len)
{
	size_t	i;

	i = len;
	while (i > 0)
	{
		a[i - 1] = x[i - 1];
		i--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*des;
	char	*sou;

	des = (char *)dst;
	sou = (char *)src;
	if (des == NULL && sou == NULL && len > 0)
		return (NULL);
	if (des < sou)
		moveplus(des, sou, len);
	else
		moveminus(des, sou, len);
	return (dst);
}
