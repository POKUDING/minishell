/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:39:57 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/03 21:20:40 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*add_token(t_token *token, char	*cmd, t_envp_node *env)
{
	t_token	*new;
	t_token	*tmp;

	new = (t_token *)malloc(sizeof(t_token));
	ft_bzero(new, sizeof(t_token));
	if (ft_strchr("|<>&", cmd[0]))
		new->operator = 1;
	if (!new->operator)
	{
		new->cmd = check_env(cmd, env);
	 	new->argv = parse_argv(new->cmd);
	}
	else
		new->cmd = cmd;
	if (!token)
		return (new);
	tmp = token;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (token);
}

t_token	*parse_token(char *cmd, t_envp_node *env)
{
	size_t	i;
	char	flag;
	t_token	*rtn;

	rtn = NULL;
	flag = 0;
	while (*cmd)
	{
		i = 0;
		while (ft_strchr("|<>&",cmd[i]))
			i++;
		if (i == 0)
		{
			while(cmd[i] && (!ft_strchr("|<>&",cmd[i]) || flag))
			{
				if (!flag && (cmd[i] == '"' || cmd[i] == '\''))
					flag = cmd[i];
				else if (flag && (flag == cmd[i] || flag == cmd[i]))
					flag = 0;
				i++;
			}
		}
		rtn = add_token(rtn, ft_substr(cmd, 0, i), env);
		cmd += i;
	}
	return (rtn);
}
