/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 12:59:53 by kposthum      #+#    #+#                 */
/*   Updated: 2022/10/19 12:23:34 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static void	ft_putnbr(int n, int fd)
{
	if (n < 10)
		ft_putchar_fd((n + 48), fd);
	else
	{
		ft_putnbr(n / 10, fd);
		ft_putnbr(n % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
		ft_putnbr(n, fd);
	}
	else
		ft_putnbr(n, fd);
}
