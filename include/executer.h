/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:08:09 by cagonzal          #+#    #+#             */
/*   Updated: 2023/08/07 12:32:49 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include <minishell.h>
# include <errno.h>

//	Executer
int		is_builtin(char *arg);
void	launch_single_process(t_prompt prompt);
void	call_execve(t_prompt *prompt);
int		ft_lstpromptsize(t_prompt *lst);

#endif
