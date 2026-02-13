/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llugez <llugez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:09:07 by llugez            #+#    #+#             */
/*   Updated: 2026/01/22 14:20:20 by llugez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/header.h"

t_stack	*init_parsing(int argc, char *argv[])
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (
		!split_arguments(&stack_a, argc, argv)
		|| !check_for_duplicates(stack_a))
	{
		ft_lstclear(&stack_a);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	return (stack_a);
}

int	split_arguments(t_stack **stack_a, int argc, char *argv[])
{
	char	**splited_args;
	int		i;

	i = 1;
	while (i < argc)
	{
		splited_args = ft_split(argv[i], " \t\n\r");
		if (!init_stack_a(stack_a, splited_args))
		{
			ft_clean_2d_tab(splited_args);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_for_duplicates(t_stack *stack_a)
{
	t_stack	*current;

	while (stack_a)
	{
		current = stack_a->next;
		while (current)
		{
			if (current->value == stack_a->value)
				return (0);
			current = current->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}
