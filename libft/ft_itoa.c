/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:36:01 by hkchikec          #+#    #+#             */
/*   Updated: 2019/05/18 21:47:33 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int num)
{
	char	*str;
	int		digit_count;

	digit_count = 0;
	if (num == 0)
		return (ft_strdup("0"));
	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	if (num < 0)
	{
		num = -1 * num;
		digit_count++;
	}
	digit_count += ft_count_digits(num);
	if (!(str = (char *)malloc(sizeof(char) * (digit_count + 1))))
		return (NULL);
	str[digit_count] = '\0';
	while (num > 0)
	{
		str[digit_count-- - 1] = num % 10 + '0';
		num = num / 10;
	}
	if (digit_count == 1)
		str[0] = '-';
	return (str);
}
