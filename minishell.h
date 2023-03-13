/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:40:13 by junhyupa          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/05 18:47:39 by junhyupa         ###   ########.fr       */
=======
/*   Updated: 2023/03/13 22:01:38 by junhyupa         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <signal.h>
# include <termios.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "./inc/structs.h"

//del del!! del!!
# include "./inc/test_funcs.h"

# include "./inc/error_control.h"
# include "./inc/pipex.h"
# include "./inc/free.h"
# include "./inc/parse_argv.h"
# include "./inc/parse_env.h"
# include "./inc/parse_token.h"
# include "./inc/make_envp_list.h"
# include "./inc/set_signal.h"
# include "./inc/builtin.h"
# include "./inc/signal.h"

#endif
