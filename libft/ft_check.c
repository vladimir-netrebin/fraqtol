/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:46:31 by ivalenti          #+#    #+#             */
/*   Updated: 2020/01/25 15:29:27 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(char c)
{
	if (c == '\r' || c == '\n' || c == '\t' || c == '\v')
		return (1);
	if (c == '\f' || c == '\0' || c == ' ')
		return (1);
	return (0);
}