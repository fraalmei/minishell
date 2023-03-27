/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:35:14 by cagonzal          #+#    #+#             */
/*   Updated: 2023/02/17 14:47:04 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <t_list.h>

/**
 * @brief Returns the last element of a linked list.
 *
 * @param lst Linked list.
 * @return t_list* Pointer to the last element.
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next != NULL)
		return (ft_lstlast(lst->next));
	return (lst);
}
