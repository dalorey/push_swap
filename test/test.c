/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:28:08 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/05/07 22:16:48 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/**
 * print_stack - Prints the contents of a stack.
 * @stack: Pointer to the head of the stack (linked list).
 * @name: Name of the stack to be printed (e.g., "A" or "B").
 *
 * Iterates through stack & prints each element's value, followed by a newline.
 */
void	print_stack(t_stack_node *stack, const char *name)
{
	printf("%s: ", name);
	while (stack)
	{
		printf("%d ", get_stack_value(stack));
		stack = stack->next;
	}
	printf("\n");
}

/**
 * print_stack_index - Prints the index of a stack.
 * @stack: Pointer to the head of the stack (linked list).
 * @name: Name of the stack to be printed (e.g., "A" or "B").
 *
 * Iterates through stack & prints each element's index, followed by a newline.
 */
void	print_stack_index(t_stack_node *stack, const char *name)
{
	printf("%s: ", name);
	while (stack)
	{
		printf("%d ", get_stack_index(stack));
		stack = stack->next;
	}
	printf("\n");
}

/**
 * array_length - Calculates the number of elements in an integer array.
 * @array: Pointer to the array.
 * @size: Total size of the array in bytes.
 *
 * Returns the number of elements in the array by dividing the total size
 * by the size of one element.
 *
 * Return: The length of the array as an integer.
 */
int	array_length(int *array, size_t size)
{
	return (size / sizeof(array[0]));
}

/**
 * test_stack_operations - Tests various stack operations.
 *
 * Initializes two stacks (A and B) with predefined integer arrays and performs
 * a series of operations (sa, sb, pa, pb, ra, rb, rra, rrb). Prints the state
 * of the stacks before and after each operation. Frees the memory allocated
 * for the stacks at the end.
 */
void	test_stack_operations(void)
{
	t_stack	stack;
	int		nums_a[] = {3, 1, 4, 2, 5};
	int		nums_b[] = {33, 11, 44, 22, 55};

	// Initialize stack
	stack.a = NULL;
	stack.b = NULL;
	for (int i = 0; i < array_length(nums_a, sizeof(nums_a)); i++)
		stack_add_back(&stack.a, new_stack_node(nums_a[i]));
	for (int i = 0; i < array_length(nums_b, sizeof(nums_b)); i++)
		stack_add_back(&stack.b, new_stack_node(nums_b[i]));

	printf("Initial state:\n");
	print_stack(stack.a, "A");
	print_stack(stack.b, "B");

	// Test operations
	printf("\nTesting sa:\n");
	sa(&stack, 1);
	print_stack(stack.a, "A");
	print_stack(stack.b, "B");

	printf("\nTesting sb:\n");
	sb(&stack, 1);
	print_stack(stack.a, "A");
	print_stack(stack.b, "B");

	printf("\nTesting pa:\n");
	pa(&stack, 1);
	print_stack(stack.a, "A");
	print_stack(stack.b, "B");

	printf("\nTesting pb:\n");
	pb(&stack, 1);
	print_stack(stack.a, "A");
	print_stack(stack.b, "B");

	printf("\nTesting ra:\n");
	ra(&stack, 1);
	print_stack(stack.a, "A");
	print_stack(stack.b, "B");

	printf("\nTesting rb:\n");
	rb(&stack, 1);
	print_stack(stack.a, "A");
	print_stack(stack.b, "B");

	printf("\nTesting rra:\n");
	rra(&stack, 1);
	print_stack(stack.a, "A");
	print_stack(stack.b, "B");

	printf("\nTesting rrb:\n");
	rrb(&stack, 1);
	print_stack(stack.a, "A");
	print_stack(stack.b, "B");

	free_stack(&stack);
}

/**
 * test_sort_small - Tests the sorting of a small stack.
 *
 * Initializes a stack (A) with a predefined integer array, prints the stack
 * before sorting, sorts it using the sort_small function, and prints the stack
 * after sorting. Frees the memory allocated for the stack at the end.
 */
void	test_sort_small(void)
{
	t_stack	stack;
//	int		nums_a[] = {2, 3, 1, 5, 4};
	int		nums_a[] = {-22, 33, 11, 55, 44};

	// Initialize stack
	stack.a = NULL;
	stack.b = NULL;
	for (int i = 0; i < array_length(nums_a, sizeof(nums_a)); i++)
		stack_add_back(&stack.a, new_stack_node(nums_a[i]));

	printf("Before sort:\n");
	print_stack(stack.a, "A");

	// Normalize stack
	normalize_stack(stack.a);
	printf("Normalized stack index:\n");
	print_stack_index(stack.a, "A");

	sort_small(&stack, array_length(nums_a, sizeof(nums_a)));

	printf("After sort:\n");
	print_stack(stack.a, "A");
	printf("Normalized stack index:\n");
	print_stack_index(stack.a, "A");

	free_stack(&stack);
}

void	test_sort_medium(void)
{
	t_stack	stack;
//	int		nums_a[] = {2, 3, 1, 5, 4, 7};
//	int		nums_a[] = {-22, 33, 11, 55, 44, 77};
//	int		nums_a[] = {-22, 33, 11, 55, 44, 77, 99, 88, 66, 22, 0, -11, -33, -55, -44, -77};
	int		nums_a[] = {-22, 33, 11, 55, 44, 77, 99, 88, 66, 22, 0, -11, -33, -55, -44, -77, -99, -88, -66, -42};

	// Initialize stack
	stack.a = NULL;
	stack.b = NULL;
	for (int i = 0; i < array_length(nums_a, sizeof(nums_a)); i++)
		stack_add_back(&stack.a, new_stack_node(nums_a[i]));

	printf("Before sort:\n");
	print_stack(stack.a, "A");

	// Normalize stack
	normalize_stack(stack.a);
	printf("Normalized stack index:\n");
	print_stack_index(stack.a, "A");

	sort_medium(&stack, array_length(nums_a, sizeof(nums_a)));

	printf("After sort:\n");
	print_stack(stack.a, "A");
	printf("Normalized stack index:\n");
	print_stack_index(stack.a, "A");

	free_stack(&stack);
}

// Add more test functions...

int	main(void)
{
	printf("=== Testing stack operations ===\n");
	test_stack_operations();

	printf("\n=== Testing small sort ===\n");
	test_sort_small();

	printf("\n=== Testing medium sort ===\n");
	test_sort_medium();

	// Add more test calls...

	return (0);
}
