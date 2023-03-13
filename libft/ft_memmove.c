/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:26:41 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/05 18:22:58 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_tmp;
	const char	*src_tmp;
	size_t		i;

	i = 0;
	dst_tmp = (char *)dst;
	src_tmp = (const char *)src;
	if (!dst && !src)
		return (0);
	if (dst <= src)
		dst_tmp = ft_memcpy(dst_tmp, src_tmp, len);
	else if (dst > src)
	{
		while (i < len)
		{
			dst_tmp[len - i - 1] = src_tmp[len - i - 1];
			i++;
		}
	}
	return (dst_tmp);
}
