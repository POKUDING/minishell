/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_envp_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:05:48 by jisulee           #+#    #+#             */
/*   Updated: 2023/03/03 21:16:37 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_ENVP_LIST_H
# define MAKE_ENVP_LIST_H

# include "../minishell.h"

t_envp_node	*get_envp(char **envp);
t_envp_node	*make_node(t_envp_node *head, char *envp);
void		make_info(t_envp_node *node, char *envp);

#endif
