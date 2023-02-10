/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:45:37 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/10 15:47:41 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	arguments_checker(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac && av[i])
	{
		j = 0;
		if (av[i][j] == '-')
			j++;
		while (('0' <= av[i][j] && av[i][j] <= '9' && av[i][j]))
			j++;
		if (av[i][j] != '\0')
			return (1);
		i++;
	}
	return (0);
}

static int	fill_table(int ac, char **av, int **table)
{
	int		i;
	long	tmp;

	i = 1;
	while (i < ac)
	{
		tmp = atoi_def(av[i]);
		if (INT_MIN <= tmp && tmp <= INT_MAX)
			(*table)[i - 1] = tmp;
		else
			return (1);
		i++;
	}
	return (0);
}

static int	check_doubles(int ac, int *table)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac - 2)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (table[i] == table[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*parsing(int ac, char **av)
{
	int	*tab;

	if (ac == 1)
		return (NULL);
	if (arguments_checker(ac, av) == 1)
		return (NULL);
	tab = ft_calloc(sizeof(int), ac - 1);
	if (!tab)
		return (NULL);
	if (fill_table(ac, av, &tab))
		return (free(tab), NULL);
	if (check_doubles(ac, tab) == 1)
		return (free(tab), NULL);
	return (tab);
}
