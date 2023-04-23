/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_of_strlen.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/14 13:36:33 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/14 13:36:57 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	strofstrlen(char **chars)
{
	size_t	i;

	i = 0;
	while (chars[i])
		i++;
	return (i);
}
