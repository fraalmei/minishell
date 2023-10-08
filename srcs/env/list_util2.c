/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:22:28 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/08 16:08:28 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	list_len(t_env_var *first)
{
	int			i;
	t_env_var	*swap;

	i = 0;
	swap = first;
	while (swap->next)
	{
		swap = swap->next;
		i++;
	}
	return (i);
}

t_env_var	*lst_strct_env(t_env_var *env)
{
	t_env_var	*swap;

	swap = env;
	while (swap->next)
		swap = swap->next;
	return (swap);
}

t_env	*ignored_env(void)
{
	t_env		*env;
	t_env_var	*first;

	env = (t_env *)ft_calloc(sizeof(*env), 2);
	env->env = NULL;
	set_value(&first, ft_strjoin(ft_strdup("PWD="), get_wd_char()));
	env->frst = first;
	set_value(&first, "SHLVL=1");
	env->dir = new_struct_env("_=/usr/bin/env");
	return (env);
}

/// @brief Compares characters in a string to determine if any
/// forbidden characters are present.
/// This function iterates through the characters in the given string 
/// and checks if each character is an alphanumeric character (letters / digits)
/// or an underscore (ASCII 95). If a forbidden character is encountered,
/// the function returns the position of that character in the string.
/// @param str A pointer to the null-terminated string to be checked.
/// @return The position of the first forbidden character encountered,
/// or the length of the string if no forbidden characters are found.
int	ft_chrcmp_env_forbid(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != 95)
			return (i);
		i++;
	}
	return (i);
}
