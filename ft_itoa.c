/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:07:05 by fedmarti          #+#    #+#             */
/*   Updated: 2022/10/10 12:30:22 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*initialize(size_t *pow, size_t *len, int n)
{
	char	*str;

	*pow = 1;
	*len = 1;
	if (n < 0)
	{
		if (n == INT_MIN)
			n = -2147483647;
		n = -n;
		*len = 2;
	}
	while (*pow <= (size_t)n / 10)
	{
		*pow = *pow * 10;
		*len = *len + 1;
	}
	str = (char *)malloc((*len + 1) * sizeof(char));
	return (str);
}

static int	ft_check(int *n, char *str, size_t *pow)
{
	int	offset;

	offset = 0;
	if (*n == INT_MIN)
	{
		str[1] = '2';
		*n = -147483648;
		*pow = *pow / 10;
		offset++;
	}
	if (*n < 0)
	{
		*str = '-';
		*n = -*n;
		offset++;
	}
	return (offset);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	pow;
	size_t	len;

	str = initialize(&pow, &len, n);
	if (!str)
		return (NULL);
	str += ft_check(&n, str, &pow);
	while (pow)
	{
		*str++ = (n / pow) + '0';
		n %= pow;
		pow /= 10;
	}
	*str = 0;
	str -= len;
	return (str);
}
