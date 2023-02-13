/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:08:12 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/13 16:52:03 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*aux_push(t_stack *receiver, t_stack *sender)
{
	t_node	*node;
	t_node	*tmp;
	t_node	*second;	

	tmp = sender->head;
	second = sender->head->next;
	ft_printf("Len Receiver Before %d /Len Receiver Before\n", receiver->len);
	ft_printf("Len Sender Before %d /Len Sender Before\n", sender->len);
	receiver->len += 1;
	sender->len -= 1;
	ft_printf("Len Receiver After %d /Len Receiver After\n", receiver->len);
	ft_printf("Len Sender After %d /Len Sender After\n", sender->len);
	if (receiver->head)
	{
		node = ft_node_new(tmp->val, receiver->head,
				receiver->head->prev, tmp->ind);
		if (!node)
			return (NULL);
		ft_node_endings(node, receiver->head, receiver->head->prev);
	}
	else
	{
		node = ft_node_new(tmp->val, NULL, NULL, tmp->ind);
		if (!node)
			return (NULL);
		ft_node_endings(node, node, node);
	}
	ft_node_endings(second, second->next, tmp->prev);
	return (node);
}

int	push(t_stack *receiver, t_stack *sender, t_push_swap *vars)
{
	t_node		*node;
	t_node		*tmp;

	ft_printf("In Push %p \n", sender->head);
	if (!sender || !(sender->head) || !vars || sender->len == 0)
		return (ft_printf("Taking first exit\n"), 1);
	
	node = aux_push(receiver, sender);
	tmp = sender->head;
	receiver->head = node;
	sender->head = sender->head->next;
	free(tmp);
	tmp = NULL;
	if (sender->len == 0)
		sender->head = NULL;
	if (vars->stack_a == receiver)
	{
		stack_association(receiver, sender, vars);
		vars->insts = new_instruct(PUSH_A, vars->insts);
	}
	else
	{
		stack_association(sender, receiver, vars);
		vars->insts = new_instruct(PUSH_B, vars->insts);
	}
	return (vars->insts == NULL);
}

static int	swap_aux(t_stack *stack, t_node *first, t_push_swap *vars)
{
	if (stack == vars->stack_a)
	{
		vars->stack_a->head = first;
		vars->insts = new_instruct(SWAP_A, vars->insts);
		return (vars->insts == NULL);
	}
	else
	{
		vars->stack_b->head = first;
		vars->insts = new_instruct(SWAP_B, vars->insts);
		return (vars->insts == NULL);
	}
}

int	swap(t_stack *stack, t_push_swap *vars)
{
	t_node	*third;
	t_node	*first;

	if (!stack || !(stack->head) || !vars || stack->len == 1)
		return (1);
	first = stack->head->next;
	if (stack->len == 2)
		stack->head = stack->head->next;
	else
	{
		third = stack->head->next->next;
		stack->head->prev->next = first;
		first->prev = stack->head->prev;
		first->next = stack->head;
		stack->head->prev = first;
		stack->head->next = third;
		third->prev = stack->head;
		stack->head = first;
	}
	return (swap_aux(stack, first, vars));
}
