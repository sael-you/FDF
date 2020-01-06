/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 23:29:15 by hkchikec          #+#    #+#             */
/*   Updated: 2019/05/20 02:24:24 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*new_dest;
	char	*new_src;

	if (!dst && !src)
		return (0);
	new_src = (char *)src;
	new_dest = (char *)dst;
	while (n--)
		*(new_dest++) = *(new_src++);
	return (dst);
}
