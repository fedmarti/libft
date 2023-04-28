/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:12:05 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/05 00:56:30 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	while (len-- && *big && little[i])
	{
		if (*big == little[i])
			i++;
		else if (i)
		{
			len += i;
			big -= i;
			i = 0;
		}
		big++;
	}
	if (!little[i])
		return ((char *)(big - i));
	return (NULL);
}
