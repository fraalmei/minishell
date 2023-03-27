/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstduplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:48:15 by cagonzal          #+#    #+#             */
/*   Updated: 2023/02/17 14:47:04 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <t_list.h>

int	ft_lstduplicates(t_list *lst)
{
	t_list	*frst;
	t_list	*dup;

	frst = lst;
	while (frst)
	{
		dup = frst->next;
		while (dup)
		{
			if (frst->content == dup->content)
				return (1);
			dup = dup->next;
		}
		frst = frst->next;
	}
	return (0);
}
