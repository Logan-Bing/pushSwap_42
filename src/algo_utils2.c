/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llugez <llugez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:22:55 by llugez            #+#    #+#             */
/*   Updated: 2026/02/03 20:08:10 by llugez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/header.h"

void	update_target_for_b(t_stack *stack_b, t_stack *stack_a)
{
	t_stack	*current_a;

	while (stack_b)
	{
		stack_b->target = NULL;
		current_a = stack_a;
		while (current_a)
		{
			current_a->target = NULL;
			if (stack_b->value < current_a->value)
			{
				if (
					!stack_b->target
					|| stack_b->target->value > current_a->value
				)
					stack_b->target = current_a;
			}
			current_a = current_a->next;
			if (!current_a && !stack_b->target)
				stack_b->target = find_min(stack_a);
		}
		stack_b = stack_b->next;
	}
}

void	setup_for_single_b(
	t_stack **stack_a,
	t_stack **stack_b,
	t_stack *cheapest
)
{
	t_stack	*target;

	target = cheapest->target;
	while (cheapest->index != 0)
	{
		if (cheapest->side == 0)
			rotate(stack_b, "rb");
		else
			reverse_rotate(stack_b, "rrb");
		update_algo(*stack_a, *stack_b, 'b');
	}
	while (target->index != 0)
	{
		if (target->side == 0)
			rotate(stack_a, "ra");
		else
			reverse_rotate(stack_a, "rra");
		update_algo(*stack_a, *stack_b, 'b');
	}
}
