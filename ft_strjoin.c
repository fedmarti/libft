/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:53:47 by fedmarti          #+#    #+#             */
/*   Updated: 2022/10/10 14:44:21 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2);
	joint = (char *)malloc(((len + 1) * sizeof(char)));
	if (!joint)
		return (NULL);
	i = 0;
	while (len-- && *s1)
	{
		joint[i] = *s1;
		s1++;
		i++;
	}
	len++;
	while (len-- && *s2)
	{
		joint[i] = *s2;
		s2++;
		i++;
	}
	joint[i] = 0;
	return (joint);
}
