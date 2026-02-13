/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llugez <llugez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:28:22 by llugez            #+#    #+#             */
/*   Updated: 2026/01/18 16:09:09 by llugez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	del(void *content)
// {
// 	free(content);
// }

void	ft_lstclear(t_stack **lst)
{
	t_stack	*current_node;
	t_stack	*tmp;

	current_node = *lst;
	while (current_node != NULL)
	{
		tmp = current_node->next;
		free(current_node);
		current_node = tmp;
	}
	*lst = NULL;
}

// int	main()
// {
// 	char *first_content = strdup("node 1");
// 	char *second_content = strdup("node 1");
// 	char *third_content = strdup("node 1");
// 	t_stack *list = NULL;
// 	t_stack *node_1 = ft_lstnew(first_content);
// 	t_stack *node_2 = ft_lstnew(second_content);
// 	t_stack *node_3 = ft_lstnew(third_content);
// 	ft_lstadd_front(&list, node_3);
// 	ft_lstadd_front(&list, node_2);
// 	ft_lstadd_front(&list, node_1);
// 	print_stack(list);
// 	ft_lstclear(&list, del);
// 	printf("%d", list == NULL);
// }