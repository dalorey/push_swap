/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:53:01 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/05/04 19:38:53 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * get_stack_value - Retrieves the value of a given stack node.
 * @node: Pointer to the stack node.
 *
 * Return: The value stored in the node, or 0 if the node is NULL.
 */
int	get_stack_value(t_stack_node *node)
{
	if (!node)
		return (0); // Return 0 if the node is NULL
	return (node->value);
}

/**
 * new_stack_node - Creates a new stack node with a given value.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the newly created node, or NULL if mem allocation fails.
 */
t_stack_node	*new_stack_node(int value)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1; // Default index
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/**
 * stack_add_back - Adds a new node to the end of a stack.
 * @stack: Double pointer to the head of the stack.
 * @new_node: Pointer to the new node to add.
 *
 * Return: None.
 */
void	stack_add_back(t_stack_node **stack, t_stack_node *new_node)
{
	t_stack_node	*current;

	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
}
