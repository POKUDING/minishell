/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:25:49 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/03 21:03:55 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ARGV_H
# define PARSE_ARGV_H

# include "../minishell.h"

char	**build_argv_box(char **box, char *s);
char	**cpy_argv_box(char **box, char *s);
char	**join_argv(char **argv, char *new);
char	**parse_argv(char *cmd);

#endif
