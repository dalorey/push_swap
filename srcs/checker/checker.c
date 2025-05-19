/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:17:20 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/05/19 20:35:57 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

static int  execute_instruction(char *line, t_stack_node **a, t_stack_node **b)
{
	// Implement your instruction execution logic here
	// Return 0 on success, -1 on error
	(void)line;
	(void)a;
	(void)b;
	return (0);
}

static int	init_stack_a(t_stack_node **a, int argc, char **argv)
{
	int				i;
	int				value;
	t_stack_node	*node;

	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		node = new_stack_node(value);
		if (!node)
			return (-1);
		stack_add_back(a, node);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_stack *stack;		// Stack a & b
	char    line[5];	// 4 chars + null terminator
	int     ret;		// Number of bytes read

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (1);
	stack->a = NULL;
	stack->b = NULL;
	if (argc < 2)
		return (0);

	// TODO: Initialize stack a with argv
	if (init_stack_a(&stack->a, argc, argv) == -1)
	{
		write(2, "Error\n", 6);
		free(stack);
		return (1);
	}

	while ((ret = read(0, line, 4)) > 0)
	{
		line[ret] = '\0';
		if (execute_instruction(line, &stack->a, &stack->b) == -1)
		{
			write(2, "Error\n", 6);
			free(stack);
			return (1);
		}
	}

	// TODO: Check if stack a is sorted and b is empty, then print "OK" or "KO"
	if (is_sorted(stack->a) && stack->b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);

	return (0);
}