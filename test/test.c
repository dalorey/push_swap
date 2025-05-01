/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:28:08 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/05/01 22:24:30 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_list *stack, const char *name)
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
	int		nums[] = {3, 1, 4, 2};

	// Initialize stack
	stack.a = NULL;
	stack.b = NULL;
	for (int i = 0; i < 4; i++)
		ft_lstadd_back(&stack.a, ft_lstnew(&nums[i]));

	printf("Initial state:\n");
	print_stack(stack.a, "A");
	print_stack(stack.b, "B");

	// Test operations
	printf("\nTesting sa:\n");
	sa(&stack, 1);
	print_stack(stack.a, "A");

	printf("\nTesting pb:\n");
	pb(&stack, 1);
	print_stack(stack.a, "A");
	print_stack(stack.b, "B");

	// Add more test cases...

	free_stack(&stack);
}

void	test_sort_small(void)
{
	t_stack	stack;
	int		nums[] = {3, 1, 4, 2};

	// Initialize stack
	stack.a = NULL;
	stack.b = NULL;
	for (int i = 0; i < 4; i++)
		ft_lstadd_back(&stack.a, ft_lstnew(&nums[i]));

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