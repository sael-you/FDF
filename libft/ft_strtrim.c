/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 02:03:39 by hkchikec          #+#    #+#             */
/*   Updated: 2019/04/20 16:00:40 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		left;
	int		right;
	int		n;
	char	*t;

	if (s)
	{
		left = 0;
		right = ft_strlen(s) - 1;
		n = 0;
		while (s[left] == ' ' || s[left] == '\n' || s[left] == '\t')
			left++;
		while (s[right] == ' ' || s[right] == '\n' || s[right] == '\t')
			right--;
		if (right < left)
			return (ft_strnew(ft_strlen(s)));
		if (!(t = (char *)malloc(right - left + 1)))
			return (NULL);
		if (ft_strlen(s) == ft_strlen(t))
			ft_strcpy(t, (char *)s);
		else
			t = ft_strsub(s, left, (right - left + 1));
		return (t);
	}
	return (NULL);
}
