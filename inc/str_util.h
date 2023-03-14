/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:31:56 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/14 15:32:59 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_UTIL_H
# define STR_UTIL_H

# include "../minishell.h"

char	*str_pop(char *s, size_t start, size_t len);
char	*join_n_free(char *s1, char *s2);

#endif