/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llugez <llugez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:51:47 by llugez            #+#    #+#             */
/*   Updated: 2026/01/18 15:50:44 by llugez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

// void	print_stack(t_list *lst)
// {
// 	t_stack *current_node = lst;
// 	while (current_node != NULL)
// 	{
// 		printf("%s\n", (char *)current_node->content);
// 		current_node = current_node->next;
// 	}
// }

// int	main()
// {
// 	t_stack *list = NULL;

// 	t_stack *node_1 = ft_lstnew("node 1");
// 	t_stack *node_2 = ft_lstnew("node 2");
// 	t_stack *node_3 = ft_lstnew("node 3");
// 	ft_lstadd_front(&list, node_3);
// 	ft_lstadd_front(&list, node_2);
// 	ft_lstadd_front(&list, node_1);
// 	print_stack(list);
// }