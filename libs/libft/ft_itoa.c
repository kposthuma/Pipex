/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 12:59:01 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/16 15:50:20 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*ft_itoapos(int i, int n)
{
	char	*a;

	a = (char *)ft_calloc((i + 1), sizeof(char));
	if (!a)
		return (NULL);
	while (i > 0)
	{
		a[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	return (a);
}

static char	*ft_itoaneg(int i, int n)
{
	char	*a;

	a = (char *)ft_calloc((i + 1), sizeof(char));
	if (!a)
		return (NULL);
	if (n == -2147483648)
	{
		n = 214748364;
		a[i - 1] = 56;
		i--;
	}
	else
		n = -n;
	while (i > 1)
	{
		a[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	a[0] = 45;
	return (a);
}

char	*ft_itoa(int n)
{
	int		i;
	int		t;

	t = n;
	i = 0;
	if (t <= 0)
		i++;
	while (t != 0)
	{
		t = t / 10;
		i++;
	}
	if (n < 0)
		return (ft_itoaneg(i, n));
	else
		return (ft_itoapos(i, n));
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(120));
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(-1234567890));
// 	printf("%s\n", ft_itoa(2034067));
// 	return (0);
// }