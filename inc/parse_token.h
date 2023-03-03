/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:25:35 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/03 21:20:31 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_TOKEN_H
# define PARSE_TOKEN_H

# include "../minishell.h"

t_token	*parse_token(char *cmd, t_envp_node *env);
t_token	*add_token(t_token *token, char	*cmd, t_envp_node *env);

#endif
