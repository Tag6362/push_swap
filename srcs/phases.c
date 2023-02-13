/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phases.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:02:22 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/13 10:18:08 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	phase_1(char **av, int ac, t_push_swap *vars)
{
	

}

int	phase_2(t_stack *stack_a, t_stack *stack_b, t_push_swap *vars)
{
	while (stack_a->len > 3)
	{
		push_elements_in_b(stack_a, stack_b, vars);
	}
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
	int	i;

	i = stack_a->len;
	while (stack_b->len > 0)
	{
		if (shortest_to_ind(stack_b, i, vars))
			return (1);
		if (push(stack_a, stack_b, vars))
			return (1);
		i++;
	}
	return (0);
}
