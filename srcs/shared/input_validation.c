/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:36:27 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/05/07 21:39:08 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * is_sorted - Checks if a stack is sorted in ascending order.
 * @stack: Pointer to the head of the stack.
 *
 * Return: 1 if the stack is sorted, 0 otherwise.
 */
int	is_sorted(t_stack_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0); // Not sorted
		stack = stack->next;
	}
	return (1); // Sorted
}

/**
 * is_sorted_desc - Checks if a stack is sorted in descending order.
 * @stack: Pointer to the head of the stack (linked list).
 *
 * Iterates through the stack and verifies that each element is greater than
 * or equal to the next element.
 *
 * Return: 1 if the stack is sorted in descending order, 0 otherwise.
 */
int	is_sorted_desc(t_stack_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->index < stack->next->index)
			return (0); // Not sorted in descending order
		stack = stack->next;
	}
	return (1); // Sorted in descending order
}
