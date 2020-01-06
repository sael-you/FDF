/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:24:57 by hkchikec          #+#    #+#             */
/*   Updated: 2019/05/12 00:33:08 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tp;

	tp = (unsigned char *)b;
	while (len--)
	{
		*tp = (unsigned char)c;
		if (len)
			tp++;
	}
	return (b);
}
