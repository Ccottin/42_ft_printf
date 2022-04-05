/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:48:50 by ccottin           #+#    #+#             */
/*   Updated: 2021/05/20 14:48:59 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void*(*f)(void*), void (*del)(void*))
{
	t_list	*ret;
	t_list	*temp2;

	if (!lst)
		return (NULL);
	ret = ft_lstnew((*f)(lst->content));
	lst = lst->next;
	temp2 = ret;
	while (lst != NULL)
	{
		temp2->next = ft_lstnew((*f)(lst->content));
		while (temp2->next == NULL)
		{
			(*del)(temp2->next);
			temp2->next = ft_lstnew((*f)(lst->content));
		}
		temp2 = temp2->next;
		lst = lst->next;
	}
	return (ret);
}
