/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_protos.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:41:03 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/10 2 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PROTOS_H
# define PUSH_SWAP_PROTOS_H
# include "push_swap.h"
# include "push_swap_structs.h"

/* Tests */
void		test_01();
void		test_02();
void		test_03();
void		test_04();
void		test_05();
void		test_06();
void		test_07();
void		test_08();
void		test_09();
void		test_10();
void		test_11();
void		test_12();
void		test_13();
void		test_14();
void		test_15();
void		test_16();
void		test_17();
void		test_18();
void		test_19();
void		test_20();
void		test_21();
void		test_22();
void		test_23();
void		test_24();
void		test_25();
void		test_26();
void		test_27();
void		test_28();
void		stack_burner_ind(t_node *node);

void		stack_burner(t_node *node);

/*	Parsing	 */
int			*parsing(int ac, char **av);

/* Atoi Def */
long		atoi_def(const char *str);

/* Converting */
t_node		*convert(int *table, size_t len, t_push_swap *vars);

/* Stack Functions */
t_node		*ft_node_new(int val, t_node *next, t_node *prev, int ind);
void		ft_node_endings(t_node *elem, t_node *next, t_node *prev);
void		ft_free_circular_nodes(t_node *node);
void		ft_free_stack(t_instruct *stack);

/* Instructions 1 */
int			swap(t_stack *stack, t_push_swap *vars);
int			push(t_stack *receiver, t_stack *sender, t_push_swap *vars);

/* Instructions 2 */
int			rotate(t_stack *stack, t_push_swap *vars);
int			rev_rotate(t_stack *stack, t_push_swap *vars);
int			push_bottom(t_stack *receiver, t_stack *sender, t_push_swap *vars);

/* Sorting Functions */
int			push_elements_in_b(t_stack *stack_a, t_stack *stack_b,
			t_push_swap *vars);
int			sort_three(t_stack *stack, t_push_swap *vars);
int			shortest_to_ind(t_stack *stack, int ind, t_push_swap *vars);

/* Instruction Functions */
t_instruct	*new_instruct(int val, t_instruct *next);
int			instructions_destacker(t_instruct *first, t_instruct *second,
			char stk);
t_instruct	*instructions_adder(int instruction, int number, t_instruct *stack);
void		stack_association(t_stack *stack_a, t_stack *stack_b,
			t_push_swap *vars);

/* Do Instructions */
int	do_rotate(t_stack *stack, int times, t_push_swap *vars);
int	do_rev_rotate(t_stack *stack, int times, t_push_swap *vars);

/* Phases */
int			phase_1();
int			phase_2(t_stack *stack_a, t_stack *stack_b, t_push_swap *vars);
int			phase_3(t_stack *stack_a, t_stack *stack_b, t_push_swap *vars);


#endif
