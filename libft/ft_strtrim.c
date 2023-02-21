/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:26:26 by junhyupa          #+#    #+#             */
/*   Updated: 2022/11/23 14:55:57 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (s1[i] == 0)
		return (ft_strdup(""));
	while (j > 0 && ft_strchr(set, s1[j]))
		j--;
	if ((j - i) == ft_strlen(s1))
		return (ft_strdup(s1));
	tmp = (char *)malloc(sizeof(char) * ((j - i) + 2));
	if (tmp == 0)
		return (0);
	tmp = ft_memcpy(tmp, &s1[i], (j - i) + 1);
	tmp[(j - i) + 1] = 0;
	return (tmp);
}
