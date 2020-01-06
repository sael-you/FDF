/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 00:02:57 by hkchikec          #+#    #+#             */
/*   Updated: 2019/04/11 01:19:58 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*t;
	size_t	i;

	i = 0;
	t = ft_strnew(len);
	if (t == NULL)
		return (NULL);
	if (s)
	{
		while (s && i < len)
		{
			*(t + i) = *(s + start);
			start++;
			i++;
		}
		*(t + i) = '\0';
		return (t);
	}
	return (0);
}
