/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:18:41 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/05/03 21:11:13 by dlorenzo         ###   ########.fr       */
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
	int	size = 0;

	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
