/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llugez <llugez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:35:46 by llugez            #+#    #+#             */
/*   Updated: 2026/02/03 20:07:06 by llugez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/header.h"

void	update_target_for_a(t_stack *src, t_stack *ref)
{
	t_stack	*ref_node;

	while (src)
	{
		src->target = NULL;
		ref_node = ref;
		while (ref_node)
		{
			if (src->value > ref_node->value)
			{
				if (!src->target || src->target->value < ref_node->value)
					src->target = ref_node;
			}
			ref_node = ref_node->next;
			if (!ref_node && !src->target)
				src->target = find_max(ref);
		}
		src = src->next;
	}
}

void	setup_with_combinaison(
	t_stack **stack_a,
	t_stack **stack_b,
	t_stack *cheapest,
	char src
)
{
	t_stack	*target;

	target = cheapest->target;
	while (cheapest->index != 0 && target->index != 0)
	{
		if (cheapest->side == 0)
			combinaison_move(stack_a, stack_b, "rr", rotate);
		else
			combinaison_move(stack_a, stack_b, "rrr", reverse_rotate);
		update_algo(*stack_a, *stack_b, src);
	}
	if (src == 'a')
		setup_for_single_a(stack_a, stack_b, cheapest);
	else
		setup_for_single_b(stack_a, stack_b, cheapest);
}

void	setup_for_single_a(
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
			rotate(stack_a, "ra");
		else
			reverse_rotate(stack_a, "rra");
		update_algo(*stack_a, *stack_b, 'a');
	}
	while (target->index != 0)
	{
		if (target->side == 0)
			rotate(stack_b, "rb");
		else
			reverse_rotate(stack_b, "rrb");
		update_algo(*stack_a, *stack_b, 'a');
	}
}

void	update_algo(
	t_stack *stack_a,
	t_stack *stack_b,
	char which
)
{
	update_stack(stack_a);
	update_stack(stack_b);
	if (which == 'a')
		update_target_for_a(stack_a, stack_b);
	else
		update_target_for_b(stack_b, stack_a);
}

// Retourne le noeud de la stack_src 
// qui coute le moins de cout pour etre placer au bon
// endroit dans la stack_ref en fonction de son target
t_stack	*find_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;
	int		cheapest;
	int		current_cost;

	cheapest = 0;
	cheapest_node = stack;
	while (stack)
	{
		if (stack->target)
			current_cost = stack->cost + stack->target->cost;
		if (!cheapest || current_cost < cheapest)
		{
			cheapest = current_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	return (cheapest_node);
}
