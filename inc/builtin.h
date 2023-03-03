/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:03:13 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/03 21:03:44 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../minishell.h"

int		check_echo_option(char *option);
void	command_echo(char **str);
void	command_pwd(void);
void	command_env(t_envp_node *head);
void	add_env(char *envp, t_envp_node *head);
void	print_export_env(t_envp_node *head);
void	command_export(char **arr, t_envp_node *head);

#endif
