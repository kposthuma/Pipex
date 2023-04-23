/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 11:58:45 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/26 13:41:09 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdlib.h>
# include<stdarg.h>

int		ft_printf(const char *iets, ...);
int		ft_printf_decider(const char iets, va_list args);
int		ft_printf_putchar(char c);
int		ft_printf_putstr(char *s);
int		ft_printf_printnbr(int n);
int		ft_printf_putnbr(unsigned int n);
int		ft_printf_puthex(unsigned int n, const char A);
int		ft_printf_putptr(size_t n);

void	print_charpp(char **strs);

#endif