/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:27:11 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/05/07 21:37:57 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					value;	// Original input value
	int					index;	// Normalized index
	struct s_stack_node	*next;	// Required for operations
	struct s_stack_node	*prev;	// Required for reverse ops (rra, rrb)
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*a;		// Stack a
	t_stack_node	*b;		// Stack b
}	t_stack;

// Input validation
int				validate_args(int argc, char **argv);
int				has_duplicates(t_stack_node *stack);
int				is_sorted(t_stack_node *stack);
int				is_sorted_desc(t_stack_node *stack);

// Stack operations
void			sa(t_stack *stack, int print);
void			sb(t_stack *stack, int print);
void			ss(t_stack *stack, int print);
void			pa(t_stack *stack, int print);
void			pb(t_stack *stack, int print);
void			ra(t_stack *stack, int print);
void			rb(t_stack *stack, int print);
void			rr(t_stack *stack, int print);
void			rra(t_stack *stack, int print);
void			rrb(t_stack *stack, int print);
void			rrr(t_stack *stack, int print);

// Sorting algorithms
void			sort_stack(t_stack *stack);
void			sort_small(t_stack *stack, int size);
void			sort_medium(t_stack *stack, int size);
//void			sort_medium(t_stack *stack);
void			sort_large(t_stack *stack, int size);

// Stack utils
t_stack_node	*create_stack(int argc, char **argv);
t_stack_node	*new_stack_node(int value);
void			normalize_stack(t_stack_node *stack);
int				get_stack_value(t_stack_node *node);
int				get_stack_index(t_stack_node *node);
void			set_stack_value(t_stack_node *node, int value);
void			stack_add_back(t_stack_node **stack, t_stack_node *new_node);
int				get_rotation_a(t_stack_node *stack_a, int target_index);
int				get_rotation_b(t_stack_node *stack_b, int target_index);
void			execute_rotations(t_stack *stack, int rot_a, int rot_b);
void			final_rotate(t_stack *stack);

// Utils
void			error_exit(t_stack *stack);
void			free_stack(t_stack *stack);
int				stack_size(t_stack_node *stack);
int				get_min(t_stack_node *stack);
int				get_max(t_stack_node *stack);
int				ft_max(int a, int b);
int				get_position(t_stack_node *stack, int index);
int				calculate_moves(t_stack_node *stack, int pos);
void			calculate_and_execute_best_move(t_stack *stack);
int				calculate_insertion_cost(t_stack *stack, int index);

#endif