/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:27:48 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/11 14:06:58 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LIST_H
# define T_LIST_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	unsigned int	norm_content;
	struct s_list	*next;
}	t_list;

void		ft_lstadd_back(t_list **head, t_list *new);
void		ft_lstadd_front(t_list **head, t_list *new);
void		ft_lstclear(t_list **head);
void		ft_lstdelone(t_list *lst);
int			ft_lstduplicates(t_list *lst);
void		ft_lstiter(t_list *lst, void (*f)(int));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *));
t_list		*ft_lstnew(int content);
int			ft_lstsize(t_list *lst);

#endif
