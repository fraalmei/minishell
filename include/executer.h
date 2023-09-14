/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:08:09 by cagonzal          #+#    #+#             */
/*   Updated: 2023/09/14 11:27:34 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include <minishell.h>
# include <errno.h>

	//executer/child_manager.c
void		launch_pipe_process(t_prompt *prompt, int index);
void		prepare_exec(t_prompt *prompt, int fd[2], int auxfd[2], int node);
void		handle_pipes(t_prompt *prompt, int npip[2], int opip[2], int node);
void		wait_childs(void);

	//executer/call_execve.c
void		call_execve(t_prompt *prompt);

	//executer/exec_utils.c
int			ft_lstpromptsize(t_prompt *lst);
int			is_builtin(char *arg);

	//executer/executer.c
void		open_heredoc(t_prompt *prompt);
void		launch_from_father(t_prompt *prompt);
void		launch_from_child(t_prompt *prompt);
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
void		ft_inredir(t_prompt *prompt);
void		ft_outredir(t_prompt *prompt);
int			openfile(char *filename, int mode);

#endif
