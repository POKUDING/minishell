/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:46:09 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/05 19:04:06 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_token
{
	char			*cmd;
	char			**argv;
	int				operator;
	int				in_fd;
	int				out_fd;
	struct s_token	*next;
}	t_token;

typedef struct s_envp_node{
	char				*name;
	char				*value;
	struct s_envp_node	*next;
}	t_envp_node;

#endif
