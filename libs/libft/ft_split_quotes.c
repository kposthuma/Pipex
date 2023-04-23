/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_quotes.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/26 16:24:34 by kposthum      #+#    #+#                 */
/*   Updated: 2023/04/06 11:26:25 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	incrementer(char *str, size_t j)
{
	size_t	i;

	i = j;
	if (str[i] == '\'')
	{
		i++;
		while (str[i] != '\'' && str[i])
			i++;
	}
	else if (str[i] == '\"' && str[i])
	{
		i++;
		while (str[i] != '\"' && str[i])
			i++;
	}
	return (i - j);
}

static size_t	ft_length(char *str, char c, size_t i)
{
	size_t	len;

	len = 0;
	while (str[i] != c && str[i])
	{
		len += incrementer(str, i);
		len++;
		i += incrementer(str, i);
		i++;
	}
	return (len);
}

static char	**fillup_split(char **split, char *s_cpy, char c, size_t words)
{
	size_t	j;
	size_t	i;
	size_t	len;

	j = 0;
	i = 0;
	while (j < (words - 1))
	{
		while (s_cpy[i] == c)
			i++;
		len = ft_length(s_cpy, c, i);
		split[j] = ft_substr(s_cpy, i, len);
		if (!split[j])
			return (ft_free(split), NULL);
		i += len;
		j++;
	}
	return (split);
}

static size_t	word_count(char *str, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
			j++;
		i += incrementer(str, i);
		while (str[i] != c && str[i])
			i++;
	}
	return (j);
}

char	**ft_split_quotes(char const *s, char c)
{
	size_t	words;
	char	*s_cpy;
	char	**split;

	s_cpy = (char *)s;
	words = word_count(s_cpy, c);
	split = ft_calloc(words, sizeof(char *));
	if (!split)
		return (NULL);
	return (fillup_split(split, s_cpy, c, words));
}

// int	main(int argc, char **argv)
// {
// 	char	**jemoeder;

// 	jemoeder = ft_split_quotes(argv[1], ' ');
// 	print_charpp(jemoeder);
// 	return (argc);
// }