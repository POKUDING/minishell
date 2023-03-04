/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcontrol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:54:48 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/04 19:57:35 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	error_control(char *msg, char *msg2, int n)
{
	char	*output;

	if (msg2)
		output = ft_strjoin(msg, msg2);
	else
		output = ft_strjoin(msg, strerror(n));
	write(2, output, ft_strlen(output));
	write(2, "\n", 1);
	exit(n);
}
