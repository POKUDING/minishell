/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:04:52 by junhyupa          #+#    #+#             */
<<<<<<< HEAD:srcs/parse_env.c
/*   Updated: 2023/03/05 18:16:03 by junhyupa         ###   ########.fr       */
=======
/*   Updated: 2023/03/13 21:53:19 by junhyupa         ###   ########.fr       */
>>>>>>> master:srcs/init/parse_env.c
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*find_env(char *s, t_envp_node *head)
{
	while (head)
	{
		if (!ft_strncmp(head->name, s, ft_strlen(s)))
			break ;
		else
			head = head->next;
	}
	free(s);
	if (!head)
		return (0);
	return (head->value);
}

char	*join_n_free(char *s1, char *s2)
{
	char	*rtn;

	rtn = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (rtn);
}

char	*change_env(char *s, size_t *index, t_envp_node *env)
{
	char	*head;
	char	*env_tmp;
	char	*tail;
	char	*rtn;
	size_t	i;

	head = ft_substr(s, 0, *index);
	i = 0;
	while (s[*index + i + 1] && \
		s[*index + i + 1] != ' ' && s[*index + i + 1] != '"')
		i++;
	env_tmp = find_env(ft_substr(s, *index + 1, i), env);
	tail = ft_substr(s, *index + i + 1, ft_strlen(&s[*index + i + 1]));
	*index = ft_strlen(head) + ft_strlen(env_tmp);
	rtn = join_n_free(join_n_free(head, env_tmp), tail);
	free(s);
	return (rtn);
}

char	*check_env(char	*s, t_envp_node *env)
{
	size_t	i;
	char	flag;

	i = 0;
	while (s[i])
	{
		flag = 0;
		if (s[i] == '\'')
			flag = s[i];
		else if (flag == s[i])
			flag = 0;
		if (!flag && s[i] == '$' && (s[i + 1] != ' ' || s[i + 1] != '\0'))
			s = change_env(s, &i, env);
		else
			i++;
	}
	return (s);
}
