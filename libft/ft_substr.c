/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:05:31 by junhyupa          #+#    #+#             */
/*   Updated: 2022/07/22 21:29:59 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (len >= s_len)
		tmp = (char *)ft_calloc((s_len + 1), sizeof(char));
	else
		tmp = (char *)ft_calloc((len + 1), sizeof(char));
	if (!tmp)
		return (0);
	if (start >= s_len)
		return (tmp);
	while (i < len && s[i + start])
	{
		tmp[i] = s[i + start];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}
