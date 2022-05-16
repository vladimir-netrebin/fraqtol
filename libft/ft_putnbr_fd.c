/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:13:05 by ivalenti          #+#    #+#             */
/*   Updated: 2019/09/23 17:16:27 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		return ((void)write(fd, "-2147483648", 11));
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		return (ft_putnbr_fd(n * (-1), fd));
	}
	if ((n > 0) && (n <= 9))
		return (ft_putchar_fd(n + '0', fd));
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}
