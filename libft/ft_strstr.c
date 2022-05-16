/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:45:46 by ivalenti          #+#    #+#             */
/*   Updated: 2019/09/24 19:10:19 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *haystack, const char *needle)
{
	char	*in;
	char	*what;

	if (!ft_strlen(needle))
		return ((char*)haystack);
	in = (char*)haystack;
	what = (char*)needle;
	while (*in != '\0')
	{
		if (ft_in(in, what))
			return (in);
		in++;
	}
	return (NULL);
}
