/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:34:53 by ldiogo            #+#    #+#             */
/*   Updated: 2023/02/24 12:34:54 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_max(t_node **heada)
{
	t_node	*tmp;
	int		max;

	tmp = *heada;
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

void	put_min_top(t_node **heada)
{
	int	i;

	i = check_min(heada);
	if (check_index(heada, i) < node_counter(heada) / 2)
		while (check_index(heada, i) != 0)
			ra(heada);
	else
		while (check_index(heada, i) != 0)
			rra(heada);
}

void	put_max_top(t_node **headb)
{
	int	i;

	i = check_max(headb);
	if (check_index(headb, i) < node_counter(headb) / 2)
		while (check_index(headb, i) != 0)
			ra(headb);
	else
		while (check_index(headb, i) != 0)
			rra(headb);
}

void	only_three(t_node **heada)
{
	while (!((*heada)->value < (*heada)->next->value
			&& (*heada)->next->value < (*heada)->next->next->value))
	{
		if ((*heada)->value > (*heada)->next->value
			&& (*heada)->value > (*heada)->next->next->value)
			ra(heada);
		else if ((*heada)->value < (*heada)->next->next->value)
			sa(heada);
		else if ((*heada)->value < (*heada)->next->value
			&& (*heada)->value > (*heada)->next->next->value)
			rra(heada);
	}
}

void	only_four(t_node **heada, t_node **headb)
{
	put_min_top(heada);
	if ((*heada)->value == check_min(heada))
		pb(heada, headb);
	only_three(heada);
	pa(heada, headb);
}

void	print_stacks(t_node *stck_a, t_node *stck_b)
{
	while (stck_a || stck_b)
	{
		if (stck_a)
			printf("%d    ", stck_a->value);
		else
			printf("     ");
		if (stck_b)
			printf("%d\n", stck_b->value);
		else
			printf("\n");
		if (stck_a)
			stck_a = stck_a->next;
		if (stck_b)
			stck_b = stck_b->next;
	}
	printf("################\n");
}

void	only_five(t_node **heada, t_node **headb)
{
	put_max_top(heada);
	pb(heada, headb);
	put_min_top(heada);
	pb(heada, headb);
	only_three(heada);
	pa(heada, headb);
	pa(heada, headb);
	ra(heada);
}

void	small_sort(t_node **heada, t_node **headb)
{
	if (node_counter(heada) == 2)
	{
		if ((*heada)->value > (*heada)->next->value)
			sa(heada);
	}
	else if (node_counter(heada) == 3)
		only_three(heada);
	else if (node_counter(heada) == 4)
		only_four(heada, headb);
	else if (node_counter(heada) == 5)
		only_five(heada, headb);
}
