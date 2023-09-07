/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:43:02 by cagonzal          #+#    #+#             */
/*   Updated: 2023/09/07 15:31:13 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <executer.h>

void	ft_inredir(t_prompt *prompt)
{
	int	i;

	i = -1;
	while (prompt->input_redirect[++i])
		prompt->infile = openfile(prompt->input_redirect[i], INFILE);
}

void	ft_outredir(t_prompt *prompt)
{
	int	i;

	i = -1;
	while (prompt->output_redirect[++i])
	{
		if (prompt->output_redirect[i][1] != '>')
		{
			prompt->output_redirect[i] = ft_strtrim_frst_onefree(\
				prompt->output_redirect[i], ">");
			prompt->outfile = openfile(prompt->output_redirect[i] \
					, OUTFILE);
		}
		else
		{
			prompt->output_redirect[i] = ft_strtrim_frst_onefree(\
				prompt->output_redirect[i], ">>");
			prompt->outfile = openfile(prompt->output_redirect[i] \
					, APPFILE);
		}
	}

}

int	openfile(char *filename, int mode)
{
	if (mode == INFILE)
	{
		if (open (filename, O_RDONLY) < 0)
			ft_error(errno, filename);
		return (open (filename, O_RDONLY));
	}
	else if (mode == OUTFILE)
	{
		if (open (filename, O_CREAT | O_WRONLY | O_TRUNC, 0644) < 0)
			ft_error(errno, filename);
		return (open (filename, O_CREAT | O_WRONLY | O_TRUNC, 0644));
	}
	else if (mode == APPFILE)
	{
		if (open (filename, O_CREAT | O_WRONLY | O_APPEND, 0644) < 0)
			ft_error(errno, filename);
		return (open (filename, O_CREAT | O_WRONLY | O_APPEND, 0644));
	}
	return (0);
}
