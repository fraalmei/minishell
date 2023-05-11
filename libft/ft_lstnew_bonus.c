/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:14:41 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/23 13:37:42 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// it creates a new struct list and return a pointer to it
	// allocating memmory with malloc and initializing the content
t_list	*ft_lstnew(void *content)
{
	t_list	*s;

	s = (t_list *)ft_calloc(sizeof(*s), 1);
	if (s == NULL)
		return (NULL);
	s->content = content;
	s->next = NULL;
	return (s);
}
