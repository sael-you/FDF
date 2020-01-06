/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 23:35:11 by hkchikec          #+#    #+#             */
/*   Updated: 2019/04/20 15:59:51 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*t;

	if (s && f)
	{
		i = 0;
		if (!(t = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1))))
			return (NULL);
		while (s[i] && f)
		{
			t[i] = (f(i, s[i]));
			i++;
		}
		t[i] = '\0';
		return (t);
	}
	return (NULL);
}
