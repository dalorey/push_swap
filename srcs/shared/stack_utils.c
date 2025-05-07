/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:53:01 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/05/07 22:00:50 by dlorenzo         ###   ########.fr       */
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
 * get_stack_index - Retrieves the index of a given stack node.
 * @node: Pointer to the stack node.
 *
 * Return: The index stored in the node, or 0 if the node is NULL.
 */
int	get_stack_index(t_stack_node *node)
{
	if (!node)
		return (0); // Return 0 if the node is NULL
	return (node->index);
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

static t_stack_node	*copy_and_sort_stack(t_stack_node *stack)
{
	t_stack_node	*copy = NULL;
	t_stack_node	*tmp = stack;
	t_stack_node	*new_node;

	// Create a copy of the original stack
	while (tmp)
	{
		new_node = malloc(sizeof(t_stack_node));
		if (!new_node)
			return (NULL);
		new_node->value = tmp->value;
		new_node->next = NULL;
		stack_add_back(&copy, new_node);
		tmp = tmp->next;
	}

	// Bubble sort the copy (simple for small N)
	t_stack_node	*i, *j;
	int				swap;

	i = copy;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
			{
				swap = i->value;
				i->value = j->value;
				j->value = swap;
			}
			j = j->next;
		}
		i = i->next;
	}
	return (copy);
}

void	normalize_stack(t_stack_node *stack)
{
	t_stack_node	*sorted;
	t_stack_node	*current;
	t_stack_node	*tmp;
	int				index;

	if (!stack || !stack)
		return ;

	// Step 1: Create a sorted reference stack
	sorted = copy_and_sort_stack(stack);
	if (!sorted)
		return ; // Handle malloc error

	// Step 2: Assign indices based on the sorted order
	current = stack;
	while (current)
	{
		index = 0;
		tmp = sorted;
		while (tmp)
		{
			if (current->value == tmp->value)
			{
				current->index = index;
				break ;
			}
			index++;
			tmp = tmp->next;
		}
		current = current->next;
	}

	// Free the sorted copy
	while (sorted)
	{
		tmp = sorted->next;
		free(sorted);
		sorted = tmp;
	}
}

// Returns the number and direction of rotations needed for stack A
// Positive = ra count, Negative = rra count
int get_rotation_a(t_stack_node *stack_a, int target_index)
{
	t_stack_node	*current;
	int				position;
	int				size;
	int				forward_cost;
	int				reverse_cost;

	if (!stack_a)
		return (0);

	// Find position of the target index
	current = stack_a;
	position = 0;
	while (current && current->index != target_index)
	{
		current = current->next;
		position++;
	}

	// Calculate rotation costs
	size = stack_size(stack_a);
	forward_cost = position;			// Number of ra needed
	reverse_cost = size - position;		// Number of rra needed

	// Return the cheapest option
	return (forward_cost <= reverse_cost) ? forward_cost : -reverse_cost;
}

// Returns the number and direction of rotations needed for stack B
// Positive = rb count, Negative = rrb count
int	get_rotation_b(t_stack_node *stack_b, int target_index)
{
	int	pos;
	int	size;

	pos = 0;
	size = stack_size(stack_b);
	while (stack_b)
	{
		if (stack_b->index == target_index)
			break;
		stack_b = stack_b->next;
		pos++;
	}
	// Return positive for forward rotations (rb), negative for reverse rotations (rrb)
	return (pos <= size / 2 ? pos : -(size - pos));
}

void	execute_rotations(t_stack *stack, int rot_a, int rot_b)
{
	// Perform simultaneous rotations (rr or rrr)
	while (rot_a > 0 && rot_b > 0)
	{
		rr(stack, 1);
		rot_a--;
		rot_b--;
	}
	while (rot_a < 0 && rot_b < 0)
	{
		rrr(stack, 1);
		rot_a++;
		rot_b++;
	}

	// Perform remaining rotations for stack A
	while (rot_a > 0)
	{
		ra(stack, 1);
		rot_a--;
	}
	while (rot_a < 0)
	{
		rra(stack, 1);
		rot_a++;
	}

	// Perform remaining rotations for stack B
	while (rot_b > 0)
	{
		rb(stack, 1);
		rot_b--;
	}
	while (rot_b < 0)
	{
		rrb(stack, 1);
		rot_b++;
	}
}

void final_rotate(t_stack *stack)
{
	int min_pos;
	int size;
	int rotations;

	if (!stack || !stack->a || is_sorted(stack->a))
		return;

	// Find position of smallest element (should be at top when sorted)
	min_pos = get_min(stack->a);
	size = stack_size(stack->a);

	// Calculate whether ra or rra is more efficient
	if (min_pos <= size / 2)
		rotations = min_pos;       // Use ra
	else
		rotations = min_pos - size; // Use rra (negative value)

	// Execute rotations
	while (rotations > 0)
	{
		ra(stack, 1);
		rotations--;
	}
	while (rotations < 0)
	{
		rra(stack, 1);
		rotations++;
	}
}
