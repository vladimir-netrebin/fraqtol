/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:51:54 by ivalenti          #+#    #+#             */
/*   Updated: 2019/09/24 17:53:08 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*s1;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	s1 = (char*)malloc(i + 1);
	if (!s1)
		return (NULL);
	s1[i] = '\0';
	while (i > 0)
	{
		i--;
		s1[i] = f(i, s[i]);
	}
	return (s1);
}
