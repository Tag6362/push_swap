/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:17:58 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/19 16:48:38 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int case_1(t_stack *stack_a, t_node *node , int **pos_element, t_push_swap *vars)
// {
// 	int	last_of_a;
// 	int	first_of_a;
// 	int	elem_of_b;

// 	last_of_a = stack_a->head->prev->val;
// 	first_of_a = stack_a->head->val;
// 	elem_of_b = node->val;
// 	if ((first_of_a < elem_of_b && elem_of_b < last_of_a)
// 		|| (last_of_a < elem_of_b && elem_of_b < first_of_a))
// 	{
// 		(*pos_element)[0] = 0;
// 		(*pos_element)[1] = shortest_to_top(vars->stack_b, node->ind);
// 		ft_printf("Node %d is positive at case 1\n", node->val);
// 		return (0);
// 	}
// 	return (1);
// }

static int case_1(t_stack *stack_a, t_node *node , int **pos_elem, t_push_swap *vars)
{
	if (node->ind == 0)
	{
		(*pos_elem)[0] = shortest_to_top(stack_a, minimum_ind_stack(stack_a));
		(*pos_elem)[1] = shortest_to_top(vars->stack_b, node->ind);
		// ft_printf("Node %d matched case 1\n", node->val);
		return (0);
	}
	return (1);
}

static int case_2(t_stack *stack_a, t_node *node, int **pos_elem, t_push_swap *vars)
{
	if (node->ind == (int)(stack_a->len + vars->stack_b->len - 1))
	{
		(*pos_elem)[0] = shortest_to_top(stack_a, maximum_ind_stack(stack_a));
		(*pos_elem)[1] = shortest_to_top(vars->stack_b, node->ind);
		// ft_printf("Node %d matched case 2\n", node->val);
		return (0);
	}
	return (1);	
}

static int case_3(t_stack *stack_a, t_node *node, int **pos_elem, t_push_swap *vars)
{
	size_t	i;
	t_node	*tmp;

	i = 0;
	tmp = stack_a->head;
	if ((tmp->prev->val < node->val && node->val < tmp->val))
	{
		(*pos_elem)[0] = 0;
		(*pos_elem)[1] = shortest_to_top(vars->stack_b, node->ind);
		return (0);
	}
	while (i <= stack_a->len / 2)
	{
		if ((tmp->val < node->val && node->val < tmp->next->val))
		{
			(*pos_elem)[0] = shortest_to_top(stack_a, tmp->next->ind);
			(*pos_elem)[1] = shortest_to_top(vars->stack_b, node->ind);
			// ft_printf("Node %d matched case 3\n", node->val);
			return (0);
		}
		i++;
		tmp = tmp->next;
	}
	return (1);
}

static int case_4(t_stack *stack_a, t_node *node, int **pos_elem, t_push_swap *vars)
{
	size_t	i;
	t_node	*tmp;

	i = stack_a->len -1;
	tmp = stack_a->head;
	// if ((tmp->prev->val < node->val && node->val < tmp->val))
	// {
	// 	(*pos_elem)[0] = 0;
	// 	(*pos_elem)[1] = shortest_to_top(vars->stack_b, node->ind);
	// }
	while (i >= stack_a->len / 2)
	{
		if ((tmp->prev->val < node->val && node->val < tmp->val))
		{
			(*pos_elem)[0] = shortest_to_top(stack_a, tmp->ind);
			(*pos_elem)[1] = shortest_to_top(vars->stack_b, node->ind);
			// ft_printf("Node %d matched case 4\n", node->val);
			return (0);
		}
		i--;
		tmp = tmp->prev;
	}
	return (1);	
}

static int case_5(t_stack *stack_a, t_node *node, int **pos_elem, t_push_swap *vars)
{
	// ft_printf("Shortest: %d\n",  shortest_to_top(stack_a, closest_ind_stack(stack_a, node)));
	(*pos_elem)[0] = shortest_to_top(stack_a, closest_ind_stack(stack_a, node));
	(*pos_elem)[1] = shortest_to_top(vars->stack_b, node->ind);
			// ft_printf("Node %d matched case 5\n", node->val);

	return (0);	
}

int **case_test(t_stack *stack_a, t_stack *stack_b, t_push_swap *vars)
{
	int		**pos;
	int		i;
	t_node	*node;

	if (!stack_a || !stack_b || !vars)
		return (ft_printf("Problem in input\n"), NULL);
	pos = ft_ints(stack_b->len, 2);
	if (!pos)
		return (ft_printf("Problem in pos\n"), NULL);
	i = 0;
	node = stack_b->head;
	while ((size_t)i < stack_b->len)
	{
		// ft_printf("Loop =======================%d\n", node->val);
		if (!case_1(stack_a, node, pos + i, vars))
			;
		else if (!case_2(stack_a, node, pos + i, vars))
			;
		else if (!case_3(stack_a, node, pos + i, vars))
			;
		else if (!case_4(stack_a, node, pos + i, vars))
			;
		else
			case_5(stack_a, node, pos + i, vars);
		node = node->next;
		i++;
	}
	i = 0;
	while ((size_t)i < stack_b->len)
	{
		// ft_printf("Node %d: pos[0] = %d pos[1] = %d\n", node->val, pos[i][0], pos[i][1]);
		node = node->next;
		i++;
	}
	return (pos);
}
		// if (case_1(stack_a, node, pos + i, vars)) case_1(stack_a, node, pos + i, vars) &&
		// 	return (ft_free_ints(pos), NULL);
		// else if (case_2(stack_a, node,  pos + i, vars))
		// 	return (ft_free_ints(pos), NULL);
		// else if (case_3(stack_a, node, pos + i, vars))
		// 	return (ft_free_ints(pos), NULL);
		// else if (case_4(stack_a, node, pos + i, vars))
		// 	return (ft_free_ints(pos), NULL);

//7 3 1 4 10 8 5 9 2 6