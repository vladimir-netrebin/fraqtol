/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:26:46 by ivalenti          #+#    #+#             */
/*   Updated: 2019/09/23 21:16:31 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*re;

	re = (char*)malloc(size);
	if (!re)
		return (NULL);
	while (size > 0)
	{
		size--;
		re[size] = (char)0;
	}
	return ((void*)re);
}
