/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:34:43 by ivalenti          #+#    #+#             */
/*   Updated: 2019/09/24 18:47:32 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	unsigned long long	num;
	char				*s;
	long				pos;

	pos = 1;
	num = 0;
	s = (char*)str;
	while (ft_check(*s))
		s++;
	if (*s == '-')
		pos = -1;
	if (*s == '+' || *s == '-')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		num = num * 10 + (long long int)(*s - '0');
		s++;
	}
	if (num >= 9223372036854775807)
	{
		if (pos == -1)
			return (0);
		return (-1);
	}
	return (pos * num);
}
