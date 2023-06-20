/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:09:03 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/20 13:18:42 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
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
	int				exit_status;
	int				exit_return;
}					t_sig;

typedef struct s_env_var
{
	char				*name;
	char				*value;
	struct s_env_var	*next;
}				t_env_var;

typedef struct s_env
{
	char			**env;
	t_env_var		*frst_en;
	t_env_var		*frst_ex;
	t_env_var		*dir;
}					t_env;

typedef struct s_prompt
{
	struct s_prompt		*prev;
	char				*sep0;
	char				*command;
	int					n_options;
	char				*options;
	char				*arguments;
	char				*sep1;
	struct s_prompt		*next;
}						t_prompt;

typedef struct s_mini_class
{
	char		*buffer;
	t_env		*envirorment;
	t_prompt	*prompt;
	t_sig		*signals;
}				t_mini_class;

t_mini_class	*g_ms;

	//main.c
//int			prompt(void);

	// signals.c
void		signals_do(void);
void		signals_dont(void);
void		sig_init(void);

	// actions.c
int			get_wd(void);
int			actions(t_prompt *prompt);

	// pipe.c
char		*getpath(char *cmd, char **env);
int			exec(char *cmd, char **env);

	// parse.c
t_prompt	*buffer_to_list(char ***s);
char		***deep_split(char *buffer, char c1, char c2);

	// parse1.c
t_prompt	*buffer_to_prom(char **buffer);
char		**soft_split(char *buffer);

	// free.c
int			free_prompt(t_prompt *prom);
int			free_env_var(t_env_var *list);
int			free_env(t_env *env);
int			free_signals(t_sig *sig);
int			free_global(void);

	// env/new_env.c
char		**copy_env(char **env);
t_env		*read_env(char **env);
void		sort_in_list(t_env_var **list, t_env_var *node);

	// env/utils_env.c
t_env_var	*new_struct_env(char **var);
char		*get_value(t_env_var *env, char *var);
void		set_value(t_env_var *env, char **var);
int			get_name(t_env_var *env, char	*var);
t_env_var	*lst_strct_env(t_env_var *env);

	// builtins/env.c
void		print_env(t_env_var *env);

	// builtins/export.c
int			export(t_prompt *prompt);

	// builtins/exit.c
int			exit_shell(void);

	// builtins/cd.c
int			cd(t_prompt *prompt);

	// builtins/unset.c
void		remove_node(t_env_var **prev, t_env_var *node);
int			unset(t_env_var **env, char *name);

	// builtins/echo.c
int			echo(t_prompt *prom);

	// utils/print_things.c
void		print_prompt(t_prompt *prom);
void		print_str_str(char **string);

	// utils/meta_char.c
char		*return_wild(char *str, int *i);
#endif
