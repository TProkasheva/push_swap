/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nslughor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:09:26 by nslughor          #+#    #+#             */
/*   Updated: 2019/10/23 13:01:54 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstdelmap(t_list **lst)
{
	t_list *del;

	while (lst)
	{
		del = *lst;
		*lst = (*lst)->next;
		if (del->content)
			free(del->content);
		free(del);
	}
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*begin;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	if (!(result = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	result = (*f)(lst);
	begin = result;
	lst = lst->next;
	while (lst)
	{
		if (!(new = (t_list*)malloc(sizeof(t_list))))
			return (ft_lstdelmap(&begin));
		*new = *(*f)(lst);
		lst = lst->next;
		result->next = new;
		result = result->next;
	}
	return (begin);
}
