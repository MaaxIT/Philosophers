/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:54:15 by mpeharpr          #+#    #+#             */
/*   Updated: 2021/11/17 11:16:39 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*loop_element;
	void	*res;

	new = NULL;
	if (!lst || !f)
		return (new);
	while (lst)
	{
		res = (*f)(lst->content);
		loop_element = ft_lstnew(res);
		if (!loop_element)
			return (NULL);
		ft_lstadd_back(&new, loop_element);
		lst = lst->next;
	}
	ft_lstclear(&lst, del);
	return (new);
}
