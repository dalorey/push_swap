/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:36:27 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/05/03 21:55:51 by dlorenzo         ###   ########.fr       */
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
