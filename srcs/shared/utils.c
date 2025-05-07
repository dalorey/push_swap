/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:18:41 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/05/07 22:02:33 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * free_stack - Frees all nodes in both stacks (a and b) and resets the stack.
 * @stack: Pointer to the stack structure.
 */
void	free_stack(t_stack *stack)
{
	t_stack_node	*current;
	t_stack_node	*next;

	if (!stack)
		return ;
	// Free all nodes in stack A
	current = stack->a;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->a = NULL;
	// Free all nodes in stack B
	current = stack->b;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->b = NULL;
}

/**
 * stack_size - Calculates the size of a stack.
 * @stack: Pointer to the head of the stack.
 *
 * Return: The number of nodes in the stack.
 */
int	stack_size(t_stack_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	get_min(t_stack_node *stack)
{
	int	min;
	int	min_pos;
	int	i;

	min = stack->index;
	min_pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->index < min)
		{
			min = stack->index;
			min_pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_pos);
}

int	get_max(t_stack_node *stack)
{
	int	max;
	int	max_pos;
	int	i;

	max = stack->index;
	max_pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->index > max)
		{
			max = stack->index;
			max_pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (max_pos);
}

// Returns the larger of two integers
int ft_max(int a, int b)
{
    return (a > b) ? a : b;
}

int	calculate_moves(t_stack_node *stack, int pos)
{
	int	size;
	int	forward_moves;
	int	reverse_moves;

	size = stack_size(stack);
	forward_moves = pos;
	reverse_moves = size - pos;
	return (forward_moves <= reverse_moves ? forward_moves : -reverse_moves);
}

void	calculate_and_execute_best_move(t_stack *stack)
{
	t_stack_node	*current;
	int				best_score;
	int				current_score;
	int				best_rot_a;
	int				best_rot_b;

	current = stack->b;
	best_score = INT_MAX;
	while (current)
	{
		current_score = calculate_insertion_cost(stack, current->index);
		if (current_score < best_score)
		{
			best_score = current_score;
			best_rot_a = get_rotation_a(stack->a, current->index);
			best_rot_b = get_rotation_b(stack->b, current->index);
		}
		current = current->next;
	}
	execute_rotations(stack, best_rot_a, best_rot_b);
	pa(stack, 1);
}

/*
// Helper function to calculate rotation costs for both stacks
static int calculate_rotation_cost(t_stack *stack, int pos_a, int pos_b)
{
	int cost_a;
	int cost_b;
	int size_a;
	int size_b;

	size_a = stack_size(stack->a);
	size_b = stack_size(stack->b);

	// Calculate cheapest way to rotate stack A
	cost_a = (pos_a <= size_a / 2) ? pos_a : size_a - pos_a;

	// Calculate cheapest way to rotate stack B
	cost_b = (pos_b <= size_b / 2) ? pos_b : size_b - pos_b;

	// Account for possible double rotations (rr/rrr)
	if ((pos_a <= size_a / 2 && pos_b <= size_b / 2) ||
		(pos_a > size_a / 2 && pos_b > size_b / 2))
	{
		return (ft_max(cost_a, cost_b) + 1);  // +1 for the final push (pa)
	}
	return (cost_a + cost_b + 1);  // +1 for the final push (pa)
}
*/

// Function to calculate the cost to insert 'index' into stack A at the correct position
int	calculate_insertion_cost(t_stack *stack, int index)
{
	t_stack_node	*a;
	int				pos_a;
	int				pos_b;
	int				cost;
	int				best_cost;

	a = stack->a;
	pos_a = 0;
	best_cost = INT_MAX;

	// Find the correct position in stack A for the element
	while (a)
	{
		if ((index < a->index && (!a->prev || index > a->prev->index)) ||
			(index > a->index && !a->next))
		{
			pos_b = get_rotation_b(stack->b, index);
			cost = abs(pos_a) + abs(pos_b);
			if (cost < best_cost)
				best_cost = cost;
		}
		a = a->next;
		pos_a++;
	}
	return (best_cost);
}