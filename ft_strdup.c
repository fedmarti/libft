/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:11:59 by fedmarti          #+#    #+#             */
/*   Updated: 2022/10/10 15:45:00 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup_str;

	dup_str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dup_str)
		return (NULL);
	i = 0;
	while (*s)
	{
		dup_str[i] = *s;
		s++;
		i++;
	}
	dup_str[i] = 0;
	return (dup_str);
}
