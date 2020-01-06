/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 00:32:06 by hkchikec          #+#    #+#             */
/*   Updated: 2019/04/20 15:59:36 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*foo;

	if (s && f)
	{
		i = 0;
		if (!(foo = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1))))
			return (NULL);
		while (s[i] && f)
		{
			foo[i] = (f(s[i]));
			i++;
		}
		foo[i] = '\0';
		return (foo);
	}
	return (NULL);
}
