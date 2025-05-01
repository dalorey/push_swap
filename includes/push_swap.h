/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:27:11 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/05/01 21:47:54 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}	t_stack;

// Input validation
int		validate_args(int argc, char **argv);
int		has_duplicates(t_list *stack);
int		is_sorted(t_list *stack);

// Stack operations
void	sa(t_stack *stack, int print);
void	sb(t_stack *stack, int print);
void	ss(t_stack *stack, int print);
void	pa(t_stack *stack, int print);
void	pb(t_stack *stack, int print);
void	ra(t_stack *stack, int print);
void	rb(t_stack *stack, int print);
void	rr(t_stack *stack, int print);
void	rra(t_stack *stack, int print);
void	rrb(t_stack *stack, int print);
void	rrr(t_stack *stack, int print);

// Sorting algorithms
void	sort_stack(t_stack *stack);
void	sort_small(t_stack *stack, int size);
void	sort_medium(t_stack *stack, int size);
void	sort_large(t_stack *stack, int size);

// List utilities
t_list	*create_stack(int argc, char **argv);
void	normalize_stack(t_list *stack);
int		get_stack_value(t_list *node);
void	set_stack_value(t_list *node, int value);

// Utils
void	error_exit(t_stack *stack);
void	free_stack(t_stack *stack);
int		stack_size(t_list *stack);
int		get_min(t_list *stack);
int		get_max(t_list *stack);
int		get_position(t_list *stack, int value);

#endif