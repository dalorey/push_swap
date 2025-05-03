/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:28:08 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/05/03 22:11:21 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

void	test_stack_operations(void)
{
	t_stack	stack;
	int		nums_a[] = {3, 1, 4, 2};
	int		nums_b[] = {33, 11, 44, 22};

	// Initialize stack
	stack.a = NULL;
	stack.b = NULL;
	for (int i = 0; i < 4; i++)
		stack_add_back(&stack.a, new_stack_node(nums_a[i]));
	for (int i = 0; i < 4; i++)
		stack_add_back(&stack.b, new_stack_node(nums_b[i]));

	printf("Initial state:\n");
	print_stack(stack.a, "A");
	print_stack(stack.b, "B");

	// Test operations
	printf("\nTesting sa:\n");
	sa(&stack, 1);
	print_stack(stack.a, "A");

	printf("\nTesting sb:\n");
	sb(&stack, 1);
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

void	test_sort_small(void)
{
	t_stack	stack;
	//int		nums[] = {4, 3, 2, 1}; // does not sort with largest at the beginning
	int		nums[] = {3, 1, 4, 2};

	// Initialize stack
	stack.a = NULL;
	stack.b = NULL;
	for (int i = 0; i < 4; i++)
		stack_add_back(&stack.a, new_stack_node(nums[i]));

	printf("Before sort:\n");
	print_stack(stack.a, "A");

	sort_small(&stack, 4);

	printf("After sort:\n");
	print_stack(stack.a, "A");

	free_stack(&stack);
}

// Add more test functions...

int	main(void)
{
	printf("=== Testing stack operations ===\n");
	test_stack_operations();

	printf("\n=== Testing small sort ===\n");
	test_sort_small();

	// Add more test calls...

	return (0);
}
