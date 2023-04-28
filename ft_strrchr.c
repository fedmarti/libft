/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:40:52 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/05 01:09:49 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	int		check;

	check = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
		{
			temp = (char *) s;
			check = 1;
		}
		s++;
	}
	if (!c)
		return ((char *)s);
	if (!check)
		return (0);
	return (temp);
}
