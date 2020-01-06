/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:47:59 by hkchikec          #+#    #+#             */
/*   Updated: 2019/04/08 03:04:59 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*t;
	size_t	i;

	i = ft_strlen(s) + 1;
	t = (char *)s;
	while (t && i--)
	{
		if (c == *(t + i))
			return (t + i);
	}
	return (0);
}
