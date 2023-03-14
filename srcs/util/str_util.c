/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:25:39 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/14 16:07:50 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*str_pop(char *s, size_t start, size_t len)
{
	char	*rtn;
	size_t	i;
	size_t	j;

	i = 0;
	rtn = (char *)malloc(sizeof(char) * (ft_strlen(s) - len + 1));
	while(i < start)
	{
		rtn[i] = s[i];
		i++;
	}
	j = i + len;
	while(s[j])
	{
		rtn[i] = s[j];
		i++;
		j++;
	}
	rtn[i] = 0;
	free(s);
	return (rtn);
}

char	*join_n_free(char *s1, char *s2)
{
	char	*rtn;

	rtn = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (rtn);
}