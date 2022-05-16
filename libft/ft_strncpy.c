/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:41:42 by ivalenti          #+#    #+#             */
/*   Updated: 2019/09/15 21:14:28 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*c;
	char	*s;

	s = dst;
	c = (char*)src;
	while (*c != '\0' && len > 0)
	{
		*dst = *c;
		dst++;
		c++;
		len--;
	}
	while (len > 0)
	{
		*dst = '\0';
		len--;
		dst++;
	}
	return (s);
}
