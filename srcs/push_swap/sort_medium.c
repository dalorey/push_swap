/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:17:57 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/05/07 22:08:20 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // For debugging - DELETE LATER!!!

// print_stack --> For debugging - DELETE LATER!!!
/**
 * print_stack - Prints the contents of a stack.
 * @stack: Pointer to the head of the stack (linked list).
 * @name: Name of the stack to be printed (e.g., "A" or "B").
 *
 * Iterates through stack & prints each element's value, followed by a newline.
 */
// static void	print_stack_temp(t_stack_node *stack, const char *name)
// {
// 	printf("%s: ", name);
// 	while (stack)
// 	{
// 		printf("%d ", get_stack_value(stack));
// 		stack = stack->next;
// 	}
// 	printf("\n");
// }

/**
 * print_stack_index - Prints the index of a stack.
 * @stack: Pointer to the head of the stack (linked list).
 * @name: Name of the stack to be printed (e.g., "A" or "B").
 *
 * Iterates through stack & prints each element's index, followed by a newline.
 */
// void	print_stack_index_temp(t_stack_node *stack, const char *name)
// {
// 	printf("%s: ", name);
// 	while (stack)
// 	{
// 		printf("%d ", get_stack_index(stack));
// 		stack = stack->next;
// 	}
// 	printf("\n");
// }

static void	insert_min_to_b(t_stack *stack, int size)
{
	int	min_pos;
	int	moves;

	while (size > 3)
	{
		min_pos = get_min(stack->a);
		moves = calculate_moves(stack->a, min_pos);
		while (moves > 0)
		{
			ra(stack, 1);
			moves--;
		}
		while (moves < 0)
		{
			rra(stack, 1);
			moves++;
		}
		pb(stack, 1);
		size--;
	}
}

void	sort_medium(t_stack *stack, int size)
{
	if (size > 5 && size <= 20)
	{
		// Phase 1: Push smallest elements to B until 3 remain in A
		insert_min_to_b(stack, size);

				// printf("After phase 1:\n");
				// // Print stack A and B for debugging
				// printf("Stack A ---:\n");
				// print_stack_temp(stack->a, "A");
				// printf("Normalized stack index:\n");
				// print_stack_index_temp(stack->a, "A");
				// printf("Stack B:\n");
				// print_stack_temp(stack->b, "B");
				// printf("Normalized stack index:\n");
				// print_stack_index_temp(stack->b, "B");
				// // press a key to continue
				// getchar();

		// Phase 2: Sort the remaining 3 elements in A
		sort_small(stack, 3);

				// printf("After phase 2:\n");
				// // Print stack A and B for debugging
				// printf("Stack A ---:\n");
				// print_stack_temp(stack->a, "A");
				// printf("Normalized stack index:\n");
				// print_stack_index_temp(stack->a, "A");
				// printf("Stack B:\n");
				// print_stack_temp(stack->b, "B");
				// printf("Normalized stack index:\n");
				// print_stack_index_temp(stack->b, "B");
				// // press a key to continue
				// getchar();

		// Phase 3: Sort stack B in descending order (if necessary)
		if (stack_size(stack->b) > 1)
		{
			int rotations = 0;
			while (!is_sorted_desc(stack->b) && rotations < stack_size(stack->b))
			{
				if (stack->b->index < stack->b->next->index)
					sb(stack, 1); // Swap top two elements if out of order
				else
					rrb(stack, 1); // Reverse rotate stack B
				rotations++;
			}
		}

				// // Print stack A and B for debugging
				// printf("After phase 3:\n");
				// printf("Stack A ---:\n");
				// print_stack_temp(stack->a, "A");
				// printf("Normalized stack index:\n");
				// print_stack_index_temp(stack->a, "A");
				// printf("Stack B:\n");
				// print_stack_temp(stack->b, "B");
				// printf("Normalized stack index:\n");
				// print_stack_index_temp(stack->b, "B");
				// // press a key to continue
				// getchar();

		// Phase 4: Reinsert elements from B to A in sorted order
		while (stack->b)
		{
			calculate_and_execute_best_move(stack);
		}

				// // Print stack A and B for debugging
				// printf("After phase 4:\n");
				// printf("Stack A ---:\n");
				// print_stack_temp(stack->a, "A");
				// printf("Normalized stack index:\n");
				// print_stack_index_temp(stack->a, "A");
				// printf("Stack B:\n");
				// print_stack_temp(stack->b, "B");
				// printf("Normalized stack index:\n");
				// print_stack_index_temp(stack->b, "B");
				// // press a key to continue
				// getchar();

		// Phase 5: Final rotation to ensure A is fully sorted
		final_rotate(stack);
	}
}

/**
 * sort_medium - Sorts a medium-sized stack (6 elements) using minimal operations.
 * @stack: Pointer to the stack structure.
 * @size: The size of stack A.
 */
/*
void	sort_medium(t_stack *stack)
{
	// Push elements from A to B until only 3 remain in A
	while (stack_size(stack->a) > 3)
	{
		// Push the smallest element to B
		if (stack->a->index == get_min(stack->a))
			pb(stack, 1);
		else
			ra(stack, 1); // Rotate A to bring the smallest element to the top
	}

	// Sort the remaining 3 elements in A
	sort_small(stack, 3);

	// Push elements back from B to A in sorted order
	while (stack->b)
		pa(stack, 1);

	// Rotate A back to the correct position if necessary
	while (!is_sorted(stack->a))
		ra(stack, 1);
}
*/