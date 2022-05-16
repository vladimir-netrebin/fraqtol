/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:44:59 by ivalenti          #+#    #+#             */
/*   Updated: 2019/09/23 18:56:50 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src1;
	char	*dst1;

	if (dst == NULL && src == NULL)
		return (NULL);
	src1 = (char*)src;
	dst1 = (char*)dst;
	if (src1 >= dst1)
		while (len > 0)
		{
			*dst1 = *src1;
			dst1++;
			src1++;
			len--;
		}
	else
		while (len > 0)
		{
			*(dst1 + len - 1) = *(src1 + len - 1);
			len--;
		}
	return (dst);
}
