/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:07:33 by cagonzal          #+#    #+#             */
/*   Updated: 2023/08/28 13:13:32 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
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
//# include <executer.h>

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
	int					n_arguments;
	char				**arguments;
	char				**here_doc;
	char				**input_redirect;
	char				**output_redirect;
	char				**append_redirect;
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
int			prompt(void);

	// signals.c
void		signals_do(void);
void		signals_dont(void);
int			init_signals(void);

	// actions.c
int			actions(t_prompt *prompt);

	// pipe.c
char		*getpath(char *cmd, char **env);
int			exec(char *cmd, char **env);

	// free.c
int			free_prompt(t_prompt *prom);
int			free_env_var(t_env_var *list);
int			free_env(t_env *env);
int			free_signals(t_sig *sig);
int			free_global(void);

	// env
		// env.c
t_env		*read_env(char **env);

		// env/new_env.c
t_env		*read_env(char **env);
char		**copy_env(char **env);
void		set_value_frst(t_env_var **list, t_env_var *node);
t_env_var	*copy_env_list(char **env);

		// utils_env.c
char		*get_value(t_env_var *env, char *var);
void		set_value(t_env_var *env, char *var);
int			get_name(t_env_var *env, char	*var);

		// list_util.c
int			list_len(t_env_var *first);
t_env_var	*lst_strct_env(t_env_var *env);
t_env_var	*new_struct_env(char *var);

	// builtins
		// builtins/env.c
void		print_env(t_env_var *env);

		// builtins/export.c
int			export(t_prompt *prompt);

		// builtins/exit.c
int			exit_shell(void);

		// builtins/cd.c
int			cd(t_prompt *prompt);

		// builtins/pwd.c
int			get_wd(void);

		// builtins/unset.c
void		remove_node(t_env_var **prev, t_env_var *node);
int			unset(t_env_var **env, char **name);

		// builtins/echo.c
int			echo(t_prompt *prom);

	// utils
		// utils/print_things.c
void		print_prompt(t_prompt *prom);
void		print_str_str(char **string);

		// utils/meta_char.c
char		*return_wild(char *str, int *i);
char		*change_wild(char *str);

		//utils/ft_split_trim.c
int			ft_str_strlen(char **string);
int			ft_scndchrlen(const char *s, char c);
char		**str_strjoin_freeall(char **s1, char *s2);

		//utils/parse_prompt_utils.c
t_prompt	*make_prompt_struct(void);
int			is_redirecction(char *str);
int			check_quotes(char *str);

	// parse
		// parse_prompt.c
int			num_prom(t_prompt *prom);
t_prompt	*buffer_to_prompt(char *buffer, t_prompt *prom);
//t_prompt	*buffer_to_prompt(char *buffer);

		// parse.c
t_prompt	*buffer_to_prom(char **buffer);
char		**soft_split(char *buffer);

		// parse_prompt_utils.c
t_prompt	*make_prompt_struct(void);
int			is_redirecction(char *str);
int			is_pipe(char *str);
int			is_redir(char *str);
int			check_quotes(char *str);
t_prompt	*last_prom(t_prompt *prom);

		// parse_prompt_utils_2.c
int			swap_word(char *string, char **word, char **swap, int *i, char c);
char		*read_word(char *string, int *i);
int			option_gen(t_prompt *prom, char *str, int *i);

void		start_executer(void);

#endif
