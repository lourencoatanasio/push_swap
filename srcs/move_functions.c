/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:35:01 by ldiogo            #+#    #+#             */
/*   Updated: 2023/02/24 12:35:02 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	total_moves(t_moves moves)
{
	int	i;

	i = 0;
	if (moves.ra != 0 && moves.rb != 0)
	{
		if (moves.ra > moves.rb)
			i += moves.ra;
		else
			i += moves.rb;
	}
	else
		i += moves.ra + moves.rb;
	if (moves.rra != 0 && moves.rrb != 0)
	{
		if (moves.rra > moves.rrb)
			i += moves.rra;
		else
			i += moves.rrb;
	}
	else
		i += moves.rra + moves.rrb;
	return (i);
}

void	execute_single_moves(t_node **heada, t_node **headb, t_moves moves)
{
	while (moves.ra != 0 || moves.rb != 0 || moves.rra != 0 || moves.rrb != 0)
	{
		if (moves.ra != 0)
		{
			ra(heada);
			moves.ra--;
		}
		if (moves.rb != 0)
		{
			rb(headb);
			moves.rb--;
		}
		if (moves.rra != 0)
		{
			rra(heada);
			moves.rra--;
		}
		if (moves.rrb != 0)
		{
			rrb(headb);
			moves.rrb--;
		}
	}
}

void	execute_moves(t_node **heada, t_node **headb, t_moves moves)
{
	while (moves.ra != 0 && moves.rb != 0)
	{
		moves.ra--;
		moves.rb--;
		rr(heada, headb);
	}
	while (moves.rra != 0 && moves.rrb != 0)
	{
		moves.rra--;
		moves.rrb--;
		rrr(heada, headb);
	}
	execute_single_moves(heada, headb, moves);
}

t_moves	assign_moves(t_node **heada, t_node **headb, t_moves moves, t_n assign)
{
	if (assign.number == 0)
	{
		if (assign.index <= node_counter(heada) / 2)
			moves.ra = assign.index;
		else
			moves.rra = node_counter(heada) - assign.index;
	}
	else
	{
		if (assign.index < node_counter(headb) / 2 + 1)
			moves.rb = assign.index;
		else
			moves.rrb = node_counter(headb) - assign.index;
	}
	return (moves);
}

t_moves	check_moves(t_node **heada, t_node **headb, int n, t_moves moves)
{
	t_n	indexb;
	t_n	indexa;

	moves = init_moves();
	indexb.index = check_index(headb, n);
	indexa.index = next_a(heada, n);
	indexb.number = 1;
	indexa.number = 0;
	moves = assign_moves(heada, headb, moves, indexa);
	moves = assign_moves(heada, headb, moves, indexb);
	return (moves);
}
