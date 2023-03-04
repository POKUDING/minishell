/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:46:59 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/04 19:53:06 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../minishell.h"

char	*find_path(char *cmd, char **paths);
void	executer(t_token token, t_envp_node *env);
void	run_process(t_token *token, t_envp_node *env);
void	pipex(t_token *head, t_envp_node *env);

#endif
