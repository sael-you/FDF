/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 01:18:14 by hkchikec          #+#    #+#             */
/*   Updated: 2019/04/20 15:58:05 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	char	*temp;
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	if (src)
	{
		if (!(temp = (char*)malloc(len + 1)))
			return (NULL);
		i = 0;
		while (i < len)
		{
			temp[i] = src[i];
			i++;
		}
		temp[i] = '\0';
		return (temp);
	}
	return (NULL);
}
