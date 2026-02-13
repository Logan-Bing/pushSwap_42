/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llugez <llugez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:16:35 by llugez            #+#    #+#             */
/*   Updated: 2026/01/18 19:02:35 by llugez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*tmp;

	while (lst)
	{
		if (!lst->next->next)
		{
			tmp = lst->next;
			lst->next = NULL;
			return (tmp);
		}
		lst = lst->next;
	}
	return (NULL);
}

// int	main()
// {
// 	t_list *list = NULL;
// 	t_list *node_1 = ft_lstnew("node 1");
// 	t_list *node_2 = ft_lstnew("node 2");
// 	t_list *node_3 = ft_lstnew("node 3");
// 	ft_lstadd_front(&list, node_3);
// 	ft_lstadd_front(&list, node_2);
// 	ft_lstadd_front(&list, node_1);
// 	t_list *last_node = ft_lstlast(list);
// 	printf("%s", (char *)last_node->content);
// }