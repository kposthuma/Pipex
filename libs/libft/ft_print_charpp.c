/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_charpp.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/26 13:39:37 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/26 17:20:25 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	print_charpp(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		ft_printf("%s\n", strs[i++]);
}
