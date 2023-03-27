/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:33:49 by cagonzal          #+#    #+#             */
/*   Updated: 2023/02/17 14:47:04 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <t_list.h>

/**
 * @brief Creates a new element of a linked list and returns a pointer to it.
 *
 * @param content Pointer to the content of the new element.
 * @return t_list* Pointer to the new element.
 */
t_list	*ft_lstnew(int content)
{
	t_list	*e;

	e = malloc(sizeof(t_list));
	if (e == NULL)
		return (NULL);
	e->content = content;
	e->norm_content = 0;
	e->next = NULL;
	return (e);
}
