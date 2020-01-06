/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:27:25 by hkchikec          #+#    #+#             */
/*   Updated: 2019/04/11 01:38:51 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t len_s;
	size_t len_d;

	len_s = ft_strlen(src);
	len_d = ft_strlen(dest);
	if (size <= len_d)
		return (size + len_s);
	i = 0;
	while (src[i] != '\0' && len_d + i < size - 1)
	{
		dest[len_d + i] = src[i];
		i++;
	}
	dest[len_d + i] = '\0';
	return (len_d + len_s);
}
