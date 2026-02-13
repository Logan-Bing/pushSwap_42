/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llugez <llugez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:12:02 by llugez            #+#    #+#             */
/*   Updated: 2026/02/09 12:46:16 by llugez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

// Main.c
int		is_sorted(t_stack *h_stack);

// Parser.c
t_stack	*init_parsing(int argc, char *argv[]);
int		split_arguments(t_stack **stack_a, int argc, char *argv[]);
int		check_for_duplicates(t_stack *stack_a);

// List_utils.c
t_stack	*create_node(char *value);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
int		init_stack_a(t_stack **lst, char **tab);
void	update_stack(t_stack *stack);
// void	print_list(t_stack *lst, char *stack);

// Mouvement.c
void	swap(t_stack **head, char *move);
void	rotate(t_stack **head, char *move);
void	push(t_stack **head_a, t_stack **head_b, char *move);
void	reverse_rotate(t_stack **head, char *move);
void	combinaison_move(t_stack **head_a, t_stack **head_b, char *move,
			void (*f)(t_stack **head, char *move));

// Sort.c
void	sort_for_three(t_stack **stack);
void	rotation(t_stack **stack, t_stack *node);
void	end_sorting(t_stack **stack_a);

//Algo_utils2.c
void	update_target_for_b(t_stack *stack_b, t_stack *stack_a);
void	setup_for_single_b(t_stack **stack_a, t_stack **stack_b,
			t_stack *cheapest);

// Algo_utils.c
void	update_target_for_a(t_stack *src, t_stack *ref);
void	update_algo(t_stack *stack_a, t_stack *stack_b, char which);
t_stack	*find_cheapest(t_stack *stack);
void	setup_for_single_a(t_stack **stack_a, t_stack **stack_b,
			t_stack *cheapest);
void	setup_with_combinaison(t_stack **stack_a, t_stack **stack_b,
			t_stack *cheapest, char src);

#endif