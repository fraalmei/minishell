/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:35:38 by cagonzal          #+#    #+#             */
/*   Updated: 2023/02/17 14:47:04 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <t_list.h>

/**
 * @brief Returns the number of elements in a linked list.
 *
 * @param lst Linked list.
 * @return int Number of elements.
 */
int	ft_lstsize(t_list *lst)
{
	if (lst == NULL)
		return (0);
	if (lst->next == NULL)
		return (1);
	return (1 + ft_lstsize(lst->next));
}
