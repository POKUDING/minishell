/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:26:08 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/14 15:33:09 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ENV_H
# define PARSE_ENV_H

# include "../minishell.h"

char	*find_env(char	*s, t_envp_node *head);
char	*change_env(char *s, size_t *index, t_envp_node *env);
char	*check_env(char	*s, t_envp_node *env);

#endif
