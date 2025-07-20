/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:32:48 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/12/11 09:30:15 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	allocate_node(t_list **node)
{
	*node = (t_list *) malloc(sizeof(t_list));
	return (*node != NULL);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	if (!allocate_node(&node))
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
