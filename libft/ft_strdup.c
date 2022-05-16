/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:03:41 by ivalenti          #+#    #+#             */
/*   Updated: 2019/09/23 17:38:54 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *s;

	s = (char*)malloc(ft_strlen(s1) + 1);
	if (s == NULL)
		return (NULL);
	ft_strcpy(s, s1);
	return (s);
}
