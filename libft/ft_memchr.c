/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 03:48:36 by hkchikec          #+#    #+#             */
/*   Updated: 2019/04/08 02:41:10 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new;
	unsigned char	c2;
	int				i;

	i = 0;
	c2 = (unsigned char)c;
	new = (unsigned char *)s;
	while (n--)
	{
		if (new[i] == c2)
			return (new + i);
		i++;
	}
	return (NULL);
}
