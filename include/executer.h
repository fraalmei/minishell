/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:08:09 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/02 11:10:35 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include <minishell.h>
# include <errno.h>

	//executer/child_manager.c
void		launch_pipe_process(t_prompt *prompt, int node);
void		prepare_exec(t_prompt *prompt, int pipefd[2], int auxfd[2]);
void		handle_pipes(t_prompt *prompt, int pipefd[2], int auxfd[2]);
void		copy_pipe(int *pipe_in, int *pipe_out);
void		wait_childs(void);

	//executer/call_execve.c
void		call_execve(t_prompt *prompt);

	//executer/exec_utils.c
int			ft_lstpromptsize(t_prompt *lst);
int			is_builtin(char *arg);

	//executer/executer.c
void		ft_redir(void);
void		launch_from_child(t_prompt *prompt);
void		launch_from_father(t_prompt *prompt);
void		launch_single_process(t_prompt *prompt);
void		start_executer(void);

	//executer/fd_utils.c
void		assing_fd(int *prompt_fd, int new_fd, int fd);
void		dup_to_stdin_stdout(int fd_in, int fd_out);
void		close_all_fds(t_prompt *prompt);
void		add_flag(size_t *pos, int *flg, int t);

	//executer/heredoc.c
void		ft_heredoc(void);
char		*ft_expand_vars(char *line);
char		*writeheredoc(char *limiter);

	//executer/get_paths.c
char		*get_pathname(char *cmd, char **env);

	//executer/open_fd.c
int			ft_create_directory(void);
int			ft_remove_directory(void);
void		ft_inredir(t_prompt *prompt);
void		ft_outredir(t_prompt *prompt);
int			openfile(char *filename, int mode);

#endif
