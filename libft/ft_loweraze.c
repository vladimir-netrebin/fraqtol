/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loweraze.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:56:25 by ivalenti          #+#    #+#             */
/*   Updated: 2019/09/24 19:03:08 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_loweraze(char *s)
{
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	new = ft_strnew(ft_strlen(s));
	if (ft_isalpha(s[0]))
		new[0] = ft_tolower(s[0]);
	i = 0;
	while (*(s + ++i))
	{
		if (ft_isalpha(s[i]))
			new[i] = ft_tolower(s[i]);
		else
			new[i] = s[i];
	}
	return (new);
}
