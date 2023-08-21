/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:09:03 by fraalmei          #+#    #+#             */
/*   Updated: 2023/08/21 16:05:22 by cagonzal         ###   ########.fr       */
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
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <colors.h>
# include <signal.h>

// ----------------------------------------------------------------------------
# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define INFILE 0
# define OUTFILE 1
# define APPFILE 2

// ----------------------------------------------------------------------------
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
	int				exit_function;
	int				error_status;
	int				exit_return;
}					t_sig;

typedef struct s_env_var
{
	char				*name;
	char				equal;
	char				*value;
	struct s_env_var	*next;
}				t_env_var;

typedef struct s_env
{
	char			**env;
	t_env_var		*frst;
	t_env_var		*dir;
}					t_env;

typedef struct s_prompt
{
	struct s_prompt		*prev;
	pid_t				node_pid;
	int					infile;
	int					outfile;
	char				*sep0;
	char				*command;
	int					n_options;
	char				*options;
	int					n_arguments;
	char				**arguments;
	char				*here_doc; // Entrada por heredoc "<<"
	char				*input_redirect; // Archivo de redirección de entrada "<"
	char				*output_redirect; // Archivo de redirección de salida ">"
	char				*append_redirect; // Archivo de redirección de salida(append) ">>""
	char				*sep1;
	struct s_prompt		*next;
}						t_prompt;

typedef struct s_mini_class
{
	char		*buffer;
	t_env		*envirorment;
	t_prompt	*prompt;
	int			n_prompts;
	pid_t		sh_pid;
	t_sig		*signals;
}				t_mini_class;

t_mini_class	*g_ms;

	//main.c
//int			prompt(void);

	// signals.c
void		signals_do(void);
void		signals_dont(void);
int			init_signals(void);

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
t_prompt	*last_prom(t_prompt *prom);
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

	// env
		//env.c
t_env		*read_env(char **env);

		//utils_env.c
char		*get_value(t_env_var *env, char *var);
void		set_value(t_env_var *env, char *var);
int			get_name(t_env_var *env, char	*var);

		//list_util.c
int			list_len(t_env_var *first);
t_env_var	*lst_strct_env(t_env_var *env);
t_env_var	*new_struct_env(char *var);

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
int			unset(t_env_var **env, char **name);

	// builtins/echo.c
int			echo(t_prompt *prom);

	// utils/print_things.c
void		print_prompt(t_prompt *prom);
void		print_str_str(char **string);

	// utils/meta_char.c
char		*return_wild(char *str, int *i);
char		*change_wild(char *str);

	//utils/ft_split_trim.c
size_t		ft_chrlen(const char *s, char c);
int			ft_scndchrlen(const char *s, char c);
char		**ft_split(const char *s, char c);

	//utils/parse_prompt_utils.c
int			ft_str_strlen(char **string);
t_prompt	*make_prompt_struct(void);
int			is_redirecction(char *str);
int			check_quotes(char *str);
char		**str_strjoin_freeall(char **s1, char *s2);

	//parse_prompt.c
t_prompt	*buffer_to_prompt(char *buffer);
t_prompt	*buffer_to_pro(char *buffer);

	//executer/call_execve.c
int			ft_strichr(char *str, char c);
void		launch_from_father(t_prompt *prompt);
void		call_execve(t_prompt *prompt);

void		start_executer(void);

#endif
