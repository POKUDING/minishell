/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:05:01 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/03 16:30:30 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**build_argv_box(char **box, char *s)
{
	int		i;
	char	*tmp;
	char	**rtn;

	i = 0;
	rtn = NULL;
	if (!box || s[i] == ' ')
		rtn = cpy_argv_box(box, s);
	else
	{
		i = ft_strlen(s) - 1;
		if ((s[0] == '"' || s[0] == '\'') && s[0] == s[i])
		{
			tmp = ft_substr(s, 1, i - 1);
			free(s);
			s = tmp;
		}
		rtn = join_argv(box, s);
	}
	free(s);
	return (rtn);
}

char	**cpy_argv_box(char **box, char *s)
{
	int		i;
	char	**rtn;

	while (*s == ' ')
		s++;
	if (!*s)
		return (box);
	i = 0;
	while (box && box[i])
		i++;
	rtn = (char **)malloc(sizeof(char *) * (i + 2));
	rtn[i + 1] = NULL;
	if ((*s == '"' || *s == '\'') && *s == s[ft_strlen(s) - 1])
		rtn[i] = ft_substr(s, 1, ft_strlen(s) - 2);
	else
		rtn[i] = ft_strdup(s);
	while (--i >= 0)
		rtn[i] = box[i];
	if (box)
		free(box);
	return (rtn);
}

char	**join_argv(char **argv, char *new)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (argv && argv[i])
		i++;
	tmp = ft_strjoin(argv[i - 1], new);
	free(argv[i - 1]);
	argv[i - 1] = tmp;
	return (argv);
}

char	**parse_argv(char *cmd)
{
	int		i;
	char	flag;
	char	**rtn;

	rtn = NULL;
	while (cmd && *cmd)
	{
		i = 0;
		while (cmd[i] == ' ')
			i++;
		flag = 0;
		if ((cmd[i] == '"' || cmd[i] == '\''))
			flag = cmd[i++];
		while (cmd[i] && ((flag && flag != cmd[i]) || \
			(cmd[i] != '\'' && cmd[i] != '"' && cmd[i] != ' ')))
			i++;
		if (flag && flag == cmd[i])
			i++;
		rtn = build_argv_box(rtn, ft_substr(cmd, 0, i));
		cmd = cmd + i;
	}
	return (rtn);
}
