/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:26:07 by junhyupa          #+#    #+#             */
/*   Updated: 2022/07/18 20:21:53 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	char	tmp[11];
	char	*res;

	i = 0;
	j = 0;
	if (n == 0)
		tmp[i++] = '0';
	while (n != 0)
	{
		tmp[i++] = (((n > 0) - (n < 0)) * (n % 10)) + '0';
		if (n / 10 == 0 && n < 0)
			tmp[i++] = '-';
		n /= 10;
	}
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (res == 0)
		return (0);
	while (i > 0)
		res[j++] = tmp[--i];
	res[j] = 0;
	return (res);
}
