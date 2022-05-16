/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:57:34 by ivalenti          #+#    #+#             */
/*   Updated: 2019/09/20 20:42:48 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s21;

	s11 = (unsigned char*)s1;
	s21 = (unsigned char*)s2;
	while (n > 0)
	{
		if (*s11 != *s21)
			return ((int)(*s11 - *s21));
		s11++;
		s21++;
		n--;
	}
	return (0);
}
