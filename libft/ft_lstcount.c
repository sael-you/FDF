/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 01:33:27 by hkchikec          #+#    #+#             */
/*   Updated: 2019/05/10 00:13:56 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstcount(t_list *head)
{
	t_list	*foo;
	int		i;

	foo = head;
	i = 0;
	while (foo != NULL)
	{
		i++;
		foo = foo->next;
	}
	return (i);
}
