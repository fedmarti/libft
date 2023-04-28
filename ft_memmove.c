/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:18:29 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/04 22:46:16 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	char	*d;
	char	*s;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	d = (char *)dest;
	s = (char *)src;
	if (d > s)
	{
		sign = -1;
		i = n - 1;
	}
	while (n-- && (src || dest))
	{
		d[i] = s[i];
		i += sign;
	}
	return (dest);
}
