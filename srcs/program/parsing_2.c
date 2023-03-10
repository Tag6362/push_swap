/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:58:44 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/23 13:59:13 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_arg_number(char *sub_arg, int **table, int *current)
{
	int		i;
	int		tmp;

	i = 0;
	if (sub_arg[i] == '-')
		i++;
	while (('0' <= sub_arg[i] && sub_arg[i] <= '9' && sub_arg[i]))
		i++;
	if (sub_arg[i] != '\0')
		return (1);
	if (atoi_def(sub_arg, &tmp))
		return (1);
	(*table)[*current] = tmp;
	(*current)++;
	return (0);
}
