/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 10:16:49 by hbespin           #+#    #+#             */
/*   Updated: 2019/09/30 11:20:57 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_cntwords(char const *s, int c)
{
	size_t	cnt;
	size_t	i;

	if (!s)
		return (1);
	cnt = 0;
	i = 0;
	if (s[i] && s[i] != c)
	{
		i++;
		cnt++;
	}
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
			if (s[i] != c && s[i])
				cnt++;
		}
		i++;
	}
	return (cnt + 1);
}
