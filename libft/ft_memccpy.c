/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:36:40 by ivalenti          #+#    #+#             */
/*   Updated: 2019/09/23 17:36:04 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*src1;
	unsigned char	*dst1;

	src1 = (unsigned char*)src;
	dst1 = (unsigned char*)dst;
	while (n > 0)
	{
		*dst1 = *src1;
		if (*dst1 == (unsigned char)c)
			return (dst1 + 1);
		dst1++;
		src1++;
		n--;
	}
	return (NULL);
}
