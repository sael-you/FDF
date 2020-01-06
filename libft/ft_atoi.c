/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:10:07 by hkchikec          #+#    #+#             */
/*   Updated: 2019/04/22 01:23:04 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 0;
	i = 0;
	while ((str[i] == ' ') || (str[i] <= 19 && str[i] >= 8))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		if (res > res * 10)
			return (sign == -1 ? 0 : -1);
		res = res * 10;
		res += str[i] - '0';
		i++;
	}
	if (sign == -1)
		return ((int)res * sign);
	return ((int)res);
}
