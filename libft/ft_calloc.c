/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:02:31 by junhyupa          #+#    #+#             */
/*   Updated: 2022/11/23 14:25:38 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*tmp;

	tmp = (void *)malloc(num * size);
	if (tmp == NULL)
		return (NULL);
	ft_bzero(tmp, num * size);
	return (tmp);
}
