/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_write.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 12:15:35 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/16 11:40:37 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_printf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_printf_putstr("(null)"), 6);
	while (s[i])
		i += ft_printf_putchar(s[i]);
	return (i);
}

int	ft_printf_putnbr(unsigned int n)
{
	int				len;
	unsigned int	t;

	len = 0;
	t = n;
	if (n == 0)
		len = 1;
	while (t)
	{
		t = t / 10;
		len++;
	}	
	if (n < 10)
		ft_printf_putchar(n + 48);
	else
	{
		ft_printf_putnbr(n / 10);
		ft_printf_putnbr(n % 10);
	}
	return (len);
}

int	ft_printf_printnbr(int n)
{
	if (n == -2147483648)
		return (ft_printf_putstr("-2147483648"));
	if (n < 0)
	{
		n = -n;
		ft_printf_putchar('-');
		return (ft_printf_putnbr((unsigned int)n) + 1);
	}
	else
		return (ft_printf_putnbr((unsigned int)n));
}
