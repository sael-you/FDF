/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:40:49 by hkchikec          #+#    #+#             */
/*   Updated: 2019/04/07 10:39:41 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = (char *)str;
	i = 0;
	if (*to_find == '\0')
		return (tmp);
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
			{
				return (&tmp[i]);
			}
			j++;
		}
		i++;
	}
	return (0);
}
