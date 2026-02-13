/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llugez <llugez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:18:37 by llugez            #+#    #+#             */
/*   Updated: 2026/02/09 12:50:09 by llugez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/header.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	ft_lstclear(&stack);
	return (1);
}

// push tout les elements de la stack_b dans la stack_a
void	setup_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	while (ft_lstsize(*stack_b) != 0)
	{
		update_algo(*stack_a, *stack_b, 'b');
		cheapest = find_cheapest(*stack_b);
		if (cheapest->side == cheapest->target->side)
			setup_with_combinaison(stack_a, stack_b, cheapest, 'b');
		else
			setup_for_single_b(stack_a, stack_b, cheapest);
		push(stack_a, stack_b, "pa");
	}
	end_sorting(stack_a);
}

void	setup_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	while (ft_lstsize(*stack_a) != 3)
	{
		update_algo(*stack_a, *stack_b, 'a');
		cheapest = find_cheapest(*stack_a);
		if (cheapest->side == cheapest->target->side)
			setup_with_combinaison(stack_a, stack_b, cheapest, 'a');
		else
			setup_for_single_a(stack_a, stack_b, cheapest);
		push(stack_a, stack_b, "pb");
	}
	sort_for_three(stack_a);
}

int	need_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	update_stack(*stack_a);
	if (size == 3)
	{
		sort_for_three(stack_a);
		ft_lstclear(stack_a);
		return (0);
	}
	if (size == 2)
	{
		swap(stack_a, "sa");
		ft_lstclear(stack_a);
		return (0);
	}
	if (size == 4)
		push(stack_a, stack_b, "pb");
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit (1);
	stack_a = init_parsing(argc, argv);
	if (!stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (is_sorted(stack_a))
		return (0);
	if (need_stack_b(&stack_a, &stack_b))
	{
		if (ft_lstsize(stack_b) == 0)
		{
			while (ft_lstsize(stack_b) != 2)
				push(&stack_a, &stack_b, "pb");
		}
		setup_stack_b(&stack_a, &stack_b);
		setup_stack_a(&stack_a, &stack_b);
	}
}
