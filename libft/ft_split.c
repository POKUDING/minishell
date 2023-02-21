/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:12:58 by junhyupa          #+#    #+#             */
/*   Updated: 2022/07/21 20:16:15 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			cnt++;
		i++;
	}
	return (cnt);
}

static char	**ft_freeall(char **src)
{
	int	i;

	i = 0;
	while (src[i])
		free(src[i++]);
	free(src);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tmp;

	i = 0;
	k = 0;
	tmp = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (tmp == 0)
		return (0);
	while (s[i])
	{
		j = 0;
		while (s[i + j] != c && s[i + j])
			j++;
		if (j > 0)
			tmp[k++] = ft_substr(s, i, j);
		else
			i++;
		if (k != 0 && tmp[k - 1] == 0)
			return (ft_freeall(tmp));
		i += j;
	}
	tmp[k] = 0;
	return (tmp);
}
