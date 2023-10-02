/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:07:33 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/02 13:39:53 by fraalmei         ###   ########.fr       */
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
///	# include <executer.h>

///	 ----------------------------------------------------------------
# define MSJ_ERROR "Error de sintaxis\n"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define INFILE 0
# define OUTFILE 1
# define APPFILE 2
///	 ----------------------------------------------------------------
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

# define FALSE 0
# define TRUE 1

# define TMP_PATH "./tmp/"

# define BUFF_SIZE 4096
# define EXPANSION -36
# define ERROR 1
# define SUCCESS 0
# define IS_DIRECTORY 126
# define UNKNOWN_COMMAND 127
///	-----------------------------------------------------------------

typedef struct s_sig
{
	int				status_code;
	int				exit_return;
	int				error_status;
	int				lst_stat_cod;
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
	int					b_success;
	char				*sep0;
	char				*command;
	int					n_options;
	int					n_arguments;
	char				**arguments;
	char				**input_redirect;
	char				**output_redirect;
	int					pos_p;
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

	///	main.c
int			prompt(void);

	///	 signals.c
void		signals_in_prompt(void);
void		signals_in_process(void);
int			init_signals(void);
void		init_sig_struct(void);

	///	 actions.c
void		actions(t_prompt *prompt, int type);

	///	 pipe.c#
char		*getpath(char *cmd, char **env);
int			exec(char *cmd, char **env);

	///	 free.c
int			free_prompt(t_prompt *prom);
int			free_env_var(t_env_var *list);
int			free_env(t_env *env);
int			free_signals(t_sig *sig);
int			free_global(void);

	///	 env
		///	 env.c
t_env		*read_env(char **env);

		///	 env/new_env.c
t_env		*read_env(char **env);
char		**copy_env(char **env);
void		set_value_frst(t_env_var **list, t_env_var *node);
t_env_var	*copy_env_list(char **env);

		///	 utils_env.c
int			free_one_env_var(t_env_var *env, char *var);
char		*get_value(t_env_var *env, char *var);
void		set_value(t_env_var *env, char *var);
int			get_name(t_env_var *env, char *var);
t_env_var	*get_env(t_env_var *env, char *var);
int			incr_shll_lvl(t_env_var *env);

		///	 list_util.c
int			list_len(t_env_var *first);
t_env_var	*lst_strct_env(t_env_var *env);
char		**env_to_strstr(t_env *env);
t_env_var	*new_struct_env(char *var);

		/// list_util2.c
t_env		*ignored_env(void);

	///	 builtins
		///	 builtins/env.c
void		print_env(t_env_var *env);

		///	 builtins/export.c
int			export(t_prompt *prompt);

		///	 builtins/exit.c
int			exit_shell(void);

		///	 builtins/cd.c
int			cd(t_prompt *prompt);

		///	 builtins/pwd.c
int			get_wd(void);
char		*get_wd_char(void);

		///	 builtins/unset.c
int			remove_node(t_env_var **env, char *var);
int			unset(t_env_var **env, char **name);

		///	 builtins/echo.c
int			echo(t_prompt *prom);

	///	 utils
		///	 utils/print_things.c
void		print_prompt(t_prompt *prom);
void		print_str_str(char **string);
int			print_error(char *str, int i);

		///	 utils/meta_char.c
char		*return_wild(char *str, int *i);
char		*change_wild(char *str);

		///	utils/ft_split_trim.c
int			ft_str_strlen(char **string);
int			ft_scndchrlen(const char *s, char c);
char		**str_strjoin_freeall(char **s1, char *s2);

		///	utils/parse_prompt_utils.c
t_prompt	*make_prompt_struct(void);
void		ignore_no_p(char *buffer, int *i);
int			is_redirecction(char *str);
int			check_quotes(char *str);

		/// utils/prompt_struct.c
int			is_redirecction(char *str);
int			is_pipe(char *str);
int			is_redir(char *str);
int			check_quotes(char *str);

	///	 parse
		///	 parse_prompt.c
int			num_prom(t_prompt *prom);
t_prompt	*buffer_to_prompt(char *buffer, t_prompt *prom);

		///	 parse.c
int			check_end_prom(char *buffer);
t_prompt	*buffer_to_prom(char **buffer);
char		**soft_split(char *buffer);

		///	 parse_prompt_utils.c
t_prompt	*new_prompt_struct(void);
t_prompt	*last_prom(t_prompt *prom);

		///	 parse_prompt_utils_2.c
int			option_gen(t_prompt *prm, char *st, int *i);

		/// parse_word.c
int			reading_word(char *buffer, char **word, int *i, char c[2]);
char		*read_word(char *string, int *i, char s);

		///	 parse_redirects.c
int			get_redir(char *buffer, int *i, t_prompt *swap);

void		start_executer(void);

		/// parse_opt_args.c
int			check_start_prom(char *buffer, t_prompt *prom);
void		get_option_args(char *buffer, int *i, t_prompt *swap);


#endif
