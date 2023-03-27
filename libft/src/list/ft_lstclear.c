/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:38:39 by cagonzal          #+#    #+#             */
/*   Updated: 2022/10/17 16:25:37 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/t_list.h"

/**
 * @brief Destroys the given linked list.
 * 
 * @param lst Linked list.
 */
void	ft_lstclear(t_list **lst)
{
	if (lst == NULL || *lst == NULL)
		return ;
	ft_lstclear(&(*lst)->next);
	ft_lstdelone(*lst);
	*lst = NULL;
}
