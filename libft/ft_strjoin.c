/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:39:45 by hkchikec          #+#    #+#             */
/*   Updated: 2019/04/15 00:04:51 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*t;

	if (s1 && s2)
	{
		if (!(t = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		t = ft_strcat(t, (char *)s1);
		t = ft_strcat(t, (char *)s2);
		return (t);
	}
	return (NULL);
}
