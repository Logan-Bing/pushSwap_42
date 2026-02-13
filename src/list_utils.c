/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llugez <llugez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:28:40 by llugez            #+#    #+#             */
/*   Updated: 2026/02/09 12:40:45 by llugez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/header.h"

t_stack	*create_node(char *value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	if (ft_atoi(value) == ERROR_VALUE)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = ft_atoi(value);
	new_node->in_suite = 0;
	new_node->target = NULL;
	new_node->next = NULL;
	return (new_node);
}

int	init_stack_a(t_stack **lst, char **tab)
{
	int		i;
	t_stack	*new_node;

	i = 0;
	while (tab[i])
	{
		new_node = create_node(tab[i]);
		if (!new_node)
			return (0);
		ft_lstadd_back(lst, new_node);
		i++;
	}
	ft_clean_2d_tab(tab);
	return (1);
}

void	update_stack(t_stack *stack)
{
	int	size;
	int	i;

	size = ft_lstsize(stack);
	i = 0;
	while (stack)
	{
		stack->index = i;
		if (stack->index <= size / 2)
		{
			stack->cost = stack->index;
			stack->side = 0;
		}
		else
		{
			stack->cost = size - stack->index;
			stack->side = 1;
		}
		stack = stack->next;
		i++;
	}
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*current;

	while (stack->next)
	{
		current = stack->next;
		while (current)
		{
			if (current->value > stack->value)
				break ;
			current = current->next;
			if (!current)
				return (stack);
		}
		stack = stack->next;
	}
	return (stack);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*current;

	while (stack->next)
	{
		current = stack->next;
		while (current)
		{
			if (current->value < stack->value)
				break ;
			current = current->next;
			if (!current)
				return (stack);
		}
		stack = stack->next;
	}
	return (stack);
}
