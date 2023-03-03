/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:26:08 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/03 21:19:32 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ENV_H
# define PARSE_ENV_H

# include "../minishell.h"

char	*join_n_free(char *s1, char *s2);
char	*find_env(char	*s, t_envp_node *head);
char	*change_env(char *s, size_t *index, t_envp_node *env);
char	*check_env(char	*s, t_envp_node *env);

#endif
