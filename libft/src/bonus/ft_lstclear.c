/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:52:47 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/12/11 15:22:12 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;

	if (lst == NULL)
		return ;
	current = NULL;
	while (*lst)
	{
		if (current != NULL)
			ft_lstdelone(current, del);
		current = *lst;
		*lst = current->next;
	}
	if (current != NULL)
		ft_lstdelone(current, del);
}
