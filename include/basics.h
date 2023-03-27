/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:51:51 by cagonzal          #+#    #+#             */
/*   Updated: 2023/03/27 12:37:12 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASICS_H
# define BASICS_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <memory.h>
# include <fcntl.h>
# include <math.h>
# include "colors.h"
# include "../libft/include/libft.h"

// ------ DEFINES ------
# define MSJ_ERROR "Error de sintaxis\n"

// -------- ENUMS --------
/* Boolean */
enum e_bool
{
	TRUE = 1,
	FALSE = 0
};

#endif
