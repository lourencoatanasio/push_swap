/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:34:45 by ldiogo            #+#    #+#             */
/*   Updated: 2023/02/24 12:34:46 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	next_a(t_node **heada, int n)
{
	t_node	*tmp;
	int		i;

	tmp = *heada;
	i = 500;
	while (tmp)
	{
		if (tmp->value > n && tmp->value < i)
			i = tmp->value;
		tmp = tmp->next;
	}
	return (check_index(heada, i));
}

void	assign_index(t_node **head)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = *head;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

void	algorithm(t_node **heada, t_node **headb)
{
	t_node	*solve;

	solve = cpy_lst(*heada);
	bubble_sort_lst(solve);
	if (compare_lst(heada, &solve) == 0)
	{
		if (node_counter(heada) <= 5)
			small_sort(heada, headb);
		while (compare_lst(heada, &solve) == 0)
		{
			push_ev(heada, headb);
			from_b(heada, headb);
		}
	}
	free_list(&solve);
}

void	if_e_else(t_node **heada)
{
	if (check_index(heada, 0) > node_counter(heada) / 2)
		while (check_index(heada, 0) != 0)
			rra(heada);
	else
		while (check_index(heada, 0) != 0)
			ra(heada);
}

void	from_b(t_node **heada, t_node **headb)
{
	t_node	*tmp;
	t_moves	moves;
	t_moves	moves2;

	moves = init_moves();
	moves2 = moves;
	while (*headb)
	{
		tmp = *headb;
		moves = check_moves(heada, headb, tmp->value, moves);
		while (tmp)
		{
			moves2 = check_moves(heada, headb, tmp->value, moves2);
			if (total_moves(moves2) <= total_moves(moves))
				moves = moves2;
			tmp = tmp->next;
		}
		execute_moves(heada, headb, moves);
		pa(heada, headb);
	}
	if_e_else(heada);
}
