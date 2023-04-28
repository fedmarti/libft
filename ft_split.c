/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:52:29 by fedmarti          #+#    #+#             */
/*   Updated: 2022/10/10 14:25:24 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_wc(char const *s, char c)
{
	size_t	wc;
	int		check;

	check = 1;
	wc = 0;
	while (*s)
	{
		if (*s == c)
			check = 1;
		else
		{
			if (check)
				wc++;
			check = 0;
		}
		s++;
	}
	return (wc);
}

static char	*initialize_c(const char *s, char c, size_t *skip_c)
{
	char	*str;
	size_t	wl;

	wl = 0;
	*skip_c = 0;
	while (*s == c)
	{
		*skip_c = *skip_c + 1;
		s++;
	}
	while (s[wl] != c && s[wl] != 0)
		wl++;
	str = (char *)malloc((wl + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*s != c && *s != '\0')
		*str++ = *s++;
	*str = 0;
	str -= wl;
	*skip_c += wl;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	skip_c;
	size_t	wc;
	size_t	i;

	i = 0;
	wc = get_wc(s, c);
	split = (char **)malloc((wc + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (i < wc)
	{
		split[i] = initialize_c(s, c, &skip_c);
		s += skip_c;
		i++;
	}
	split[i] = 0;
	return (split);
}
