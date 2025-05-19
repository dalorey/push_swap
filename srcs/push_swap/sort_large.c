/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:18:06 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/05/19 19:32:05 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // For debugging - DELETE LATER!!!


void	sort_large(t_stack *stack, int size)
{
	int	bit;
	int	i;
	int	max_bits;

	if (size <= 20)
		return ;

	// Assume binary_length is set for all nodes (or compute from max index)
	max_bits = stack->a->binary_length;
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((stack->a->index >> bit) & 1) == 1)
				ra(stack, 1);
			else
				pb(stack, 1);
			i++;
		}
		while (stack->b)
			pa(stack, 1);
		bit++;
	}
}

/*
void	sort_large(t_stack *stack, int size)
{
	int	bit;
	int	i;

	bit = 0;
	i = 0;
	if (size > 20)
	{
		printf("Sorting large stack...\n");

		// Phase 1: Push elements from A to B based on their binary representation
		while (i < size)
		{
			if ((stack->a->index) & 1)
				ra(stack, 1);
			else
				pb(stack, 1);
			i++;
		}

		// // Show the state of the stacks after the first sort
		// printf("\n");
		// printf("Stack A after 1st sort (bit 0 = 1 in stack A):\n");
		// print_stack(stack->a, "A");
		// printf("Normalized stack index:\n");
		// print_stack_index(stack->a, "A");		while (i < size)
		// printf("Normalized stack binary index:\n");
		// print_stack_binary_index(stack->a, "A");
		// printf("\n");

		// printf("Stack B after 1st sort (bit 0 = 0 in stack B):\n");
		// print_stack(stack->b, "B");
		// printf("Normalized stack index:\n");
		// print_stack_index(stack->b, "B");
		// printf("Normalized stack binary index:\n");
		// print_stack_binary_index(stack->b, "B");
		// printf("\n");

		while (stack->b)
		{
			pa(stack, 1);
		}

		// // Show the state of the stacks after the first sort
		// printf("\n");
		// printf("Stack A after 1st sort:\n");
		// print_stack(stack->a, "A");
		// printf("Normalized stack index:\n");
		// print_stack_index(stack->a, "A");		while (i < size)
		// printf("Normalized stack binary index:\n");
		// print_stack_binary_index(stack->a, "A");
		// printf("\n");

		// printf("Stack B after 1st sort:\n");
		// print_stack(stack->b, "B");
		// printf("Normalized stack index:\n");
		// print_stack_index(stack->b, "B");
		// printf("Normalized stack binary index:\n");
		// print_stack_binary_index(stack->b, "B");
		// printf("\n");

		i = 0;
		while (i < size)
		{
			if ((stack->a->index) & 2)
				ra(stack, 1);
			else
				pb(stack, 1);
			i++;
		}
		while (stack->b)
		{
			pa(stack, 1);
		}

		i = 0;
		while (i < size)
		{
			if ((stack->a->index) & 4)
				ra(stack, 1);
			else
				pb(stack, 1);
			i++;
		}
		while (stack->b)
		{
			pa(stack, 1);
		}

		i = 0;
		while (i < size)
		{
			if ((stack->a->index) & 8)
				ra(stack, 1);
			else
				pb(stack, 1);
			i++;
		}
		while (stack->b)
		{
			pa(stack, 1);
		}

		i = 0;
		while (i < size)
		{
			if ((stack->a->index) & 16)
				ra(stack, 1);
			else
				pb(stack, 1);
			i++;
		}
		while (stack->b)
		{
			pa(stack, 1);
		}

		// // Show the state of the stacks after pushing back to A
		// printf("\n");
		// printf("Stack A after full sort:\n");
		// print_stack(stack->a, "A");
		// printf("Normalized stack index:\n");
		// print_stack_index(stack->a, "A");
		// printf("Normalized stack binary index:\n");
		// print_stack_binary_index(stack->a, "A");
		// printf("\n");

	}

}
*/