/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_envp_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:05:48 by jisulee           #+#    #+#             */
/*   Updated: 2023/03/13 23:05:09 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_ENVP_LIST_H
# define MAKE_ENVP_LIST_H

# include "../minishell.h"

char		**make_envbox(t_envp_node *head);
t_envp_node	*get_envp(char **envp);
t_envp_node	*make_node(t_envp_node *head, char *envp);
t_envp_node	*make_info(t_envp_node *node, char *envp);
int			find_char(char *str, char ch);

#endif
