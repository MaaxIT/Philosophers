/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:43:23 by mpeharpr          #+#    #+#             */
/*   Updated: 2021/11/17 11:16:37 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*backup;

	if (!lst || !*lst)
		return ;
	head = *lst;
	while (head)
	{
		backup = head->next;
		ft_lstdelone(head, del);
		head = backup;
	}
	*lst = NULL;
}
