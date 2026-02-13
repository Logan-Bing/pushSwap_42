/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llugez <llugez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:31:21 by llugez            #+#    #+#             */
/*   Updated: 2026/01/22 14:21:35 by llugez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/header.h"

void	rotation(t_stack **stack, t_stack *node)
{
	if (node->side == 0)
		rotate(stack, "ra");
	else
		reverse_rotate(stack, "rra");
}

void	sort_for_three(t_stack **stack)
{
	t_stack	*max;

	max = find_max(*stack);
	if (max->index == 1)
		reverse_rotate(stack, "rra");
	update_stack(*stack);
	while (max->index != 2)
	{
		rotation(stack, max);
		update_stack(*stack);
	}
	if ((*stack)->value > (*stack)->next->value)
		swap(stack, "sa");
}

void	end_sorting(t_stack **stack_a)
{
	t_stack	*min;

	min = find_min(*stack_a);
	while (!is_sorted(*stack_a))
	{
		if ((*stack_a)->value != min->value)
			rotate(stack_a, "ra");
		else
			reverse_rotate(stack_a, "rra");
		update_stack(*stack_a);
	}
}
