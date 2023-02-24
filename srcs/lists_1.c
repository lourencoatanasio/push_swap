/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:34:55 by ldiogo            #+#    #+#             */
/*   Updated: 2023/02/24 12:34:56 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	compare_lst(t_node **heada, t_node **headb)
{
	t_node	*tmpa;
	t_node	*tmpb;

	tmpa = *heada;
	tmpb = *headb;
	while (tmpa && tmpb)
	{
		if (tmpa->value != tmpb->value)
			return (0);
		tmpa = tmpa->next;
		tmpb = tmpb->next;
	}
	return (1);
}

void	exit_free(t_node **heada, t_node **headb)
{
	free_list(heada);
	free_list(headb);
	write(1, "Error\n", 6);
	exit(0);
}

int	node_counter(t_node **head)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = *head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	sort_n_change(t_node **heada)
{
	t_node	*tmp;
	t_node	*t;
	t_node	*a;

	tmp = cpy_lst(*heada);
	bubble_sort_lst(tmp);
	assign_index(&tmp);
	t = tmp;
	a = *heada;
	while (t)
	{
		while (a)
		{
			if (t->value == a->value && a->checked == 0)
			{
				a->value = t->index;
				a->checked = 1;
				break ;
			}
			a = a->next;
		}
		a = *heada;
		t = t->next;
	}
	free_list(&tmp);
}

void	push_ev(t_node **heada, t_node **headb)
{
	int	i;

	i = node_counter(heada);
	while (node_counter(heada) > 2)
	{
		if ((*heada)->value == 0 || (*heada)->value == i - 1)
			ra(heada);
		else
			pb(heada, headb);
	}
	if ((*heada)->value == 0)
		ra(heada);
}
