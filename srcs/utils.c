/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:35:11 by ldiogo            #+#    #+#             */
/*   Updated: 2023/02/24 12:35:12 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_index(t_node **headb, int n)
{
	t_node	*tmp;
	int		i;

	tmp = *headb;
	i = 0;
	while (tmp)
	{
		if (tmp->value == n)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

t_moves	init_moves(void)
{
	t_moves	moves;

	moves.ra = 0;
	moves.rb = 0;
	moves.rra = 0;
	moves.rrb = 0;
	return (moves);
}

int	check_min(t_node **heada)
{
	t_node	*tmp;
	int		min;

	tmp = *heada;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}
