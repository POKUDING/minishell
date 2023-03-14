/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:39:57 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/14 16:10:17 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	check_redirection(t_token	*new)
{
	size_t	i;

	i = 0;
	while(new->cmd && new->cmd[i])
	{
		while(new->cmd[i] == ' ')
			i++;
		if(!ft_strncmp("<<", &new->cmd[i], 2))
		{
			new->cmd = str_pop(new->cmd, i, 2);
			here_doc(new, "eof");
		}
		else
			i++;
	}

}

void	check_cmd(t_token *new, char *cmd, t_envp_node *env)
{
	new->cmd = cmd;
	check_redirection(new);
	new->cmd = check_env(new->cmd, env);
	new->argv = parse_argv(new->cmd);
}

t_token	*add_token(t_token *token, char	*cmd, t_envp_node *env)
{
	t_token	*new;
	t_token	*tmp;

	new = (t_token *)malloc(sizeof(t_token));
	ft_bzero(new, sizeof(t_token));
	if (*cmd == '|')
		new->operator = 1;
	check_cmd(new, cmd, env);
	if (!token)
		return (new);
	tmp = token;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
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
		if (*cmd == '|')
			rtn = add_token(rtn, ft_substr(cmd++, 0, 1), env);
		while (cmd[i] && (!ft_strchr("|", cmd[i]) || flag))
		{
			if (!flag && (cmd[i] == '"' || cmd[i] == '\''))
				flag = cmd[i];
			else if (flag && (flag == cmd[i] || flag == cmd[i]))
				flag = 0;
			i++;
		}
		if (i)
			rtn = add_token(rtn, ft_substr(cmd, 0, i), env);
		cmd += i;
	}
	return (rtn);
}
