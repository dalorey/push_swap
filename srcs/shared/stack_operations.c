/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:18:23 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/05/04 18:58:21 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/**
 * sa - Swaps the top two elements of stack A.
 * @stack: Pointer to the stack structure.
 * @print: If non-zero, prints the operation name.
 */
void	sa(t_stack *stack, int print)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!stack || !stack->a || !stack->a->next)
		return ;
	first = stack->a;
	second = stack->a->next;
	// Swap the first two nodes
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	// Update the head of stack A
	stack->a = second;

	if (print)
		printf("sa\n");
}

/**
 * sb - Swaps the top two elements of stack B.
 * @stack: Pointer to the stack structure.
 * @print: If non-zero, prints the operation name.
 */
void	sb(t_stack *stack, int print)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!stack || !stack->b || !stack->b->next)
		return ;
	first = stack->b;
	second = stack->b->next;
	// Swap the first two nodes
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	// Update the head of stack B
	stack->b = second;

	if (print)
		printf("sb\n");
}

/**
 * pa - Pushes the top element from stack B to stack A.
 * @stack: Pointer to the stack structure.
 * @print: If non-zero, prints the operation name.
 */
void	pa(t_stack *stack, int print)
{
	t_stack_node	*top_b;

	if (!stack || !stack->b)
		return ;
	top_b = stack->b;
	// Update stack B
	stack->b = top_b->next;
	if (stack->b)
		stack->b->prev = NULL;
	// Push the node to stack A
	top_b->next = stack->a;
	if (stack->a)
		stack->a->prev = top_b;
	stack->a = top_b;

	if (print)
		printf("pa\n");
}

/**
 * pb - Pushes the top element from stack A to stack B.
 * @stack: Pointer to the stack structure.
 * @print: If non-zero, prints the operation name.
 */
void	pb(t_stack *stack, int print)
{
	t_stack_node	*top_a;

	if (!stack || !stack->a)
		return ;
	top_a = stack->a;
	// Update stack A
	stack->a = top_a->next;
	if (stack->a)
		stack->a->prev = NULL;
	// Push the node to stack B
	top_a->next = stack->b;
	if (stack->b)
		stack->b->prev = top_a;
	stack->b = top_a;

	if (print)
		printf("pb\n");
}

/**
 * ra - Rotates stack A upwards (first element becomes the last).
 * @stack: Pointer to the stack structure.
 * @print: If non-zero, prints the operation name.
 */
void	ra(t_stack *stack, int print)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!stack || !stack->a || !stack->a->next)
		return ;
	first = stack->a;
	// Find the last node
	last = stack->a;
	while (last->next)
		last = last->next;
	// Update pointers to rotate
	stack->a = first->next;
	stack->a->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;

	if (print)
		printf("ra\n");
}

/**
 * rb - Rotates stack B upwards (first element becomes the last).
 * @stack: Pointer to the stack structure.
 * @print: If non-zero, prints the operation name.
 */
void	rb(t_stack *stack, int print)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!stack || !stack->b || !stack->b->next)
		return ;
	first = stack->b;
	// Find the last node
	last = stack->b;
	while (last->next)
		last = last->next;
	// Update pointers to rotate
	stack->b = first->next;
	stack->b->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;

	if (print)
		printf("rb\n");
}

/**
 * rra - Rotates stack A downwards (last element becomes the first).
 * @stack: Pointer to the stack structure.
 * @print: If non-zero, prints the operation name.
 */
void	rra(t_stack *stack, int print)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (!stack || !stack->a || !stack->a->next)
		return ;
	// Find the last and second-to-last nodes
	last = stack->a;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	// Update pointers to rotate
	second_last->next = NULL;
	last->prev = NULL;
	last->next = stack->a;
	stack->a->prev = last;
	stack->a = last;

	if (print)
		printf("rra\n");
}

/**
 * rrb - Rotates stack B downwards (last element becomes the first).
 * @stack: Pointer to the stack structure.
 * @print: If non-zero, prints the operation name.
 */
void	rrb(t_stack *stack, int print)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (!stack || !stack->b || !stack->b->next)
		return ;
	// Find the last and second-to-last nodes
	last = stack->b;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	// Update pointers to rotate
	second_last->next = NULL;
	last->prev = NULL;
	last->next = stack->b;
	stack->b->prev = last;
	stack->b = last;

	if (print)
		printf("rrb\n");
}
