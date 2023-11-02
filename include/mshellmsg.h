/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshellmsg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:24:10 by irodrigo          #+#    #+#             */
/*   Updated: 2023/11/02 10:37:03 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSHELLMSG_H
# define MSHELLMSG_H

// general interest msg constants
# define GN_MSG_01  "exit\n"
# define GN_MSG_02	"Minishell: "
# define GN_MSG_03	"minishell: exit: "

// error shell msg constants
# define Q_ERR_01	"unclosed quotes\n"
# define Q_ERR_02	"Scripting commands and functions are not implemented\n"
# define Q_ERR_03	"Or command not implemented or pipe number error\n"
# define Q_ERR_127	"minishell: %s: command not found\n"

# define M_ERR_01	"Couldn't allocate memory for shell implementation\n"

# define T_ERR_01	"syntax error near unexpected token `'\n"
# define T_ERR_02	"found forbiden char `\n"
# define T_ERR_03	"%s: numeric argument required\n"
# define T_ERR_04	"too many arguments\n"
# define T_ERR_05	"No such file or directory\n"
//# define T_ERR_05	"error in dup2\n"
# define T_ERR_06	"error in execve\n"
# define T_ERR_07	"minishell: %s Permission denied\n"
# define T_ERR_08	"$%s: ambiguous redirect\n"
# define T_ERR_258	"syntax error near unexpected token `%s'\n"

// other msg shell constants

#endif
