/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:09:03 by fraalmei          #+#    #+#             */
/*   Updated: 2023/05/11 18:44:14 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../../libft/libft.h"
# include <basics.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <colors.h>

# include <signal.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define INFILE 0
# define OUTFILE 1
# define APPFILE 2

//-----------------------------------------------------------------------------
# define EMPTY 0
# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define INPUT 5
# define PIPE 6
# define END 7

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define SKIP 1
# define NOSKIP 0

# define BUFF_SIZE 4096
# define EXPANSION -36
# define ERROR 1
# define SUCCESS 0
# define IS_DIRECTORY 126
# define UNKNOWN_COMMAND 127
//-----------------------------------------------------------------------------

typedef struct s_sig
{
	int				sigint;
	int				sigquit;
	int				exit_status;
	pid_t			pid;
}					t_sig;

typedef struct s_env_var
{
	char				*var;
	char				*value;
	struct s_env_var	*next;
}				t_env_var;

typedef struct s_env
{
	char			**env;
	t_env_var		*frst;
}					t_env;

typedef struct s_prompt
{
	char				*command;
	char				*options;
	char				*arguments;
	struct s_prompt		*next;
}						t_prompt;

t_sig	g_sig;

	// signals.c
void		signals_do(void);
void		sig_init(void);

	// actions.c
int			get_wd(void);
int			actions(char *buffer, char **env);

	// pipe.c
char		*getpath(char *cmd, char **env);
int			exec(char *cmd, char **env);

	// parse.c
t_prompt	*buffer_to_list(char ***s);
char		***deep_split(char *buffer, char c1, char c2);

	// free.c
int			free_prompt(t_prompt *prom);
int			free_env(t_env *env);

	// env/env.c
void		print_env(t_env	*env, int form);
t_env_var	*new_struct_env(char **var);
char		**copy_env(char **env);
t_env		*read_env(char **env);

#endif
