/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:07:51 by hkchikec          #+#    #+#             */
/*   Updated: 2019/04/14 23:40:27 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*t;
	int		i;

	i = 0;
	t = (char *)malloc(size + 1);
	if (t == NULL)
		return (NULL);
	while (size--)
	{
		t[i] = '\0';
		i++;
	}
	t[i] = '\0';
	return (t);
}
