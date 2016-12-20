/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:09:34 by marnaud           #+#    #+#             */
/*   Updated: 2016/11/24 16:44:35 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len_w(char const *s, char c, int i)
{
	int len_word;

	len_word = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len_word++;
		i++;
	}
	return (len_word);
}

static int		nb_w(char const *s, char c)
{
	int		n;
	int		nb_words;

	n = 0;
	nb_words = 0;
	while (s[n] != '\0')
	{
		if (s[n] != c && (s[n - 1] == c || n == 0))
			nb_words++;
		n++;
	}
	return (nb_words);
}

static	void	file(char const *s, char c, int *n_str, char *tab)
{
	int		n_word;

	n_word = 0;
	while (s[*n_str] != c && s[*n_str] != '\0')
	{
		tab[n_word] = s[*n_str];
		n_word += 1;
		*n_str += 1;
	}
	tab[n_word] = '\0';
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		n_tab;
	int		n_str;

	if (!s)
		return (0);
	if (!(tab = (char **)malloc(sizeof(char *) * (nb_w(s, c) + 1))))
		return (0);
	n_tab = 0;
	n_str = 0;
	while (n_tab < nb_w(s, c))
	{
		while (s[n_str] == c)
			n_str++;
		if (!(tab[n_tab] = (char *)malloc(sizeof(char) *
						(len_w(s, c, n_str) + 1))))
			return (0);
		file(s, c, &n_str, tab[n_tab]);
		n_tab++;
	}
	tab[n_tab] = 0;
	return (tab);
}
