/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:53:03 by junhyupa          #+#    #+#             */
/*   Updated: 2022/07/18 20:47:33 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	tmp[11];

	if (fd < 0)
		return ;
	i = 0;
	if (n == 0)
		tmp[i++] = '0';
	while (n != 0)
	{
		tmp[i++] = ((((n % 10) > 0) - ((n % 10) < 0)) * (n % 10)) + '0';
		if (n / 10 == 0 && n < 0)
			tmp[i++] = '-';
		n /= 10;
	}
	while (--i >= 0)
		ft_putchar_fd(tmp[i], fd);
}