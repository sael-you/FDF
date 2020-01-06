/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 04:29:30 by hkchikec          #+#    #+#             */
/*   Updated: 2019/05/19 01:00:40 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*new_src;
	char	*new_dst;
	size_t	i;

	new_src = (char *)src;
	new_dst = (char *)dst;
	i = 0;
	while (n--)
	{
		new_dst[i] = new_src[i];
		if (new_dst[i] == (char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
