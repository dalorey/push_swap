/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:17:48 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/05/04 20:59:14 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * sort_small - Sorts a small stack (3 to 5 elements) using minimal operations.
 * @stack: Pointer to the stack structure.
 * @size: The size of stack A.
 */
void	sort_small(t_stack *stack, int size)
{
	int	first;
	int	second;
	int	third;

	if (size == 2)
	{
		if (stack->a->value > stack->a->next->value)
			sa(stack, 1); // Swap if the two elements are out of order
	}
	else if (size == 3)
	{
		first = stack->a->value;
		second = stack->a->next->value;
		third = stack->a->next->next->value;
		if (first > second && second < third && first < third)
			sa(stack, 1); // Case: 2 1 3 -> 1 2 3
		else if (first > second && second < third && first > third)
			ra(stack, 1); // Case: 3 1 2 -> 1 2 3
		else if (first < second && second > third && first > third)
			rra(stack, 1); // Case: 2 3 1 -> 1 2 3
		else if (first < second && second > third && first < third)
		{
			sa(stack, 1); // Case: 1 3 2 -> 3 1 2
			ra(stack, 1); // -> 1 2 3
		}
		else if (first > second && second > third)
		{
			ra(stack, 1); // Case: 3 2 1 -> 2 1 3
			sa(stack, 1); // -> 1 2 3
		}
	}
	else if (size > 3 && size <= 5)
	{
		// Push elements from A to B until only 3 remain in A
		while (stack_size(stack->a) > 3)
		{
			if (stack->a->value > stack->a->next->value)
				rra(stack, 1); /// CHECK IF THIS IS CORRECT?????
			else
				pb(stack, 1);
		}
			// Sort the remaining 3 elements in A
		sort_small(stack, 3);
		// Sort stack B (if it contains 2 elements, sort them)
		if (stack_size(stack->b) == 2 && stack->b->value > stack->b->next->value)
			sb(stack, 1);
		// Push elements back from B to A in sorted order
		while (stack->b)
		{
			if (stack->b->value < stack->a->value)
				pa(stack, 1); // Push from B to A if B's top is smaller
			else
				ra(stack, 1); // Rotate A to find the correct position
		}
		// Rotate A back to the correct position if necessary
		while (!is_sorted(stack->a))
			rra(stack, 1);
	}
}
