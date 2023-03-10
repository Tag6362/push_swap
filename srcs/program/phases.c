/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phases.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:02:22 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/23 11:55:04 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	phase_1(char **av, int ac, t_push_swap *vars)
{
	t_node	*node;
	int		*table;

	if (!av || ac == 1 || !vars)
		return (1);
	table = parsing(ac, av, vars);
	if (!table)
		return (1);
	node = convert(table, vars->stack_a->len, vars);
	if (!node)
		return (free(table), 1);
	vars->stack_a->head = node;
	free(table);
	return (0);
}

int	phase_2(t_stack *stack_a, t_stack *stack_b, t_push_swap *vars)
{
	while (stack_a->len > 3)
		push_elements_in_b(stack_a, stack_b, vars);
	if (stack_a->len == 0 || stack_a->len == 1)
		return (0);
	else if (stack_a->len == 2)
	{
		if (stack_a->head->ind < stack_a->head->next->ind)
		{
			if (rotate(stack_a, vars) == 1)
				return (1);
		}
	}
	else
	{
		if (sort_three(stack_a, vars) == 1)
			return (1);
	}
	return (0);
}

int	phase_3(t_stack *stack_a, t_stack *stack_b, t_push_swap *vars)
{
	int	**tab;

	while (stack_b->len > 0)
	{
		tab = case_test(stack_a, stack_b, vars);
		if (!tab)
			return (1);
		if (best_instruction_executer(stack_a, stack_b, tab, vars))
			return (1);
	}
	if (turn_correctly(stack_a, vars))
		return (1);
	return (0);
}

void	memory_cleaning(t_push_swap *vars)
{
	if (!vars)
		return ;
	ft_free_circular_nodes(vars->stack_a->head);
	ft_free_circular_nodes(vars->stack_b->head);
	ft_free_stack(vars->insts);
}
