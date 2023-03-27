/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:39:50 by cagonzal          #+#    #+#             */
/*   Updated: 2023/02/17 14:47:04 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <t_list.h>

/**
 * @brief Iterates a linked list, running f on each element.
 *
 * @param lst Linked list.
 * @param f Function to run on each element.
 */
void	ft_lstiter(t_list *lst, void (*f)(int))
{
	if (lst == NULL)
		return ;
	f(lst->content);
	if (lst->next != NULL)
		ft_lstiter(lst->next, f);
}
