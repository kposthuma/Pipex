/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:59:03 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/26 14:10:38 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	i;
	char	*hay_cpy;

	if (!haystack && len == 0)
		return (0);
	hay_cpy = (char *)haystack;
	x = 0;
	if (*needle == '\0')
		return (hay_cpy);
	while (hay_cpy[x] && x < len)
	{
		i = 0;
		while (hay_cpy[x] == needle[i] && x < len)
		{
			x++;
			i++;
			if (needle[i] == '\0')
				return (&hay_cpy[x - i]);
		}
		x = (x - i);
		x++;
	}
	return (NULL);
}
