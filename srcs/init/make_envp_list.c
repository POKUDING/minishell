/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_envp_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:53:07 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/13 23:05:52 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char **make_envbox(t_envp_node *head)
{
	size_t		i;
	size_t		j;
	t_envp_node	*tmp;
	char		**rtn;

	i = 0;
	j = 0;
	tmp = head;
	while (head)
	{
		i++;
		head = head->next;
	}
	rtn = (char **)malloc(sizeof(char *) * (i + 1));
	rtn[i] = 0;
	while (j < i && tmp)
	{
		rtn[j++] = join_n_free(ft_strjoin(tmp->name,"="),ft_strdup(tmp->value));
		tmp = tmp->next;
	}
	return (rtn);
}

int	find_char(char *str, char ch)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == ch)
			return (idx);
		idx++;
	}
	return (0);
}

t_envp_node	*make_info(t_envp_node *node, char *envp)
{
	int		idx;
	int		name_len;
	char	*str;

	idx = 0;
	name_len = find_char(envp, '=');
	if (!name_len)
		name_len = ft_strlen(envp);
	str = malloc(sizeof(char) * name_len + 1);
	while (idx < name_len)
	{
		str[idx] = envp[idx];
		idx++;
	}
	str[idx] = 0;
	node->name = str;
	node->value = 0;
	if (find_char(envp, '='))
		node->value = ft_strdup(&envp[idx + 1]);
	return (node);
}

t_envp_node *make_node(t_envp_node *head, char *envp)
{
	t_envp_node	*node;
	t_envp_node	*temp;

	node = malloc(sizeof(t_envp_node));
	ft_bzero(node, sizeof(t_envp_node));
	make_info(node, envp);
	if (!head)
		return (node);
	else
	{
		temp = head;
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
	return (head);
}

t_envp_node	*get_envp(char **envp)
{
	int		idx;
	t_envp_node *head;

	idx = 0;
	head = NULL;
	while (envp[idx])
	{
		head = make_node(head, envp[idx]);
		idx++;
	}
	return (head);
}
