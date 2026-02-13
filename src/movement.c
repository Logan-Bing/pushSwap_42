/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llugez <llugez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:27:38 by llugez            #+#    #+#             */
/*   Updated: 2026/01/22 14:21:20 by llugez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/header.h"

void	swap(t_stack **head, char *move)
{
	t_stack	*tmp;

	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
	if (move)
		ft_printf("%s\n", move);
}

void	push(t_stack **head_a, t_stack **head_b, char *move)
{
	t_stack	*tmp;

	if (ft_strncmp("pa", move, ft_strlen(move)) == 0)
	{
		tmp = *head_b;
		*head_b = (*head_b)->next;
		ft_lstadd_front(head_a, tmp);
	}
	else
	{
		tmp = *head_a;
		*head_a = (*head_a)->next;
		ft_lstadd_front(head_b, tmp);
	}
	ft_printf("%s\n", move);
}

void	rotate(t_stack **head, char *move)
{
	t_stack	*tmp;

	tmp = *head;
	*head = (*head)->next;
	tmp->next = NULL;
	ft_lstadd_back(head, tmp);
	if (move)
		ft_printf("%s\n", move);
}

void	reverse_rotate(t_stack **head, char *move)
{
	t_stack	*last_node;

	last_node = ft_lstlast(*head);
	ft_lstadd_front(head, last_node);
	if (move)
		ft_printf("%s\n", move);
}

void	combinaison_move(
	t_stack **head_a,
	t_stack **head_b,
	char *move,
	void (*f)(t_stack **head, char *move)
)
{
	f(head_a, NULL);
	f(head_b, NULL);
	ft_printf("%s\n", move);
}
