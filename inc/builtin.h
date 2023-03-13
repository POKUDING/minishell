/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisulee <jisulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:03:13 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/06 22:10:24 by jisulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../minishell.h"

int		check_echo_option(char *option);
void	command_echo(char **str);

void	command_pwd(void);

void	command_env(t_envp_node *head);

void	change_value(char *str, t_envp_node *node);
void	add_env(char *str, t_envp_node *env);
void	print_export_env(t_envp_node *env);
void	command_export(char **arr, t_envp_node *env);

void	command_unset(char **arr, t_envp_node *env);
void	del_env(char *str, t_envp_node *env);
void	del_node(t_envp_node *prev_node, t_envp_node *node);
int		check_unset_name(char *str, int name_len);
int		name_cmp(char *str, char *env, int name_len);

void	command_exit(char **arr);

void	command_cd(char **arr, t_envp_node *head);

#endif
