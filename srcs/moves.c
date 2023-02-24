/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:35:08 by ldiogo            #+#    #+#             */
/*   Updated: 2023/02/24 12:35:09 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_node **heada)
{
	t_node	*tmp;
	int		tmp_value;

	tmp = *heada;
	tmp_value = tmp->value;
	tmp->value = tmp->next->value;
	tmp->next->value = tmp_value;
	write(1, "sa\n", 3);
}

void	sb(t_node **headb)
{
	int		tmp_value;
	t_node	*tmp;

	if (*headb == NULL)
		return ;
	tmp = *headb;
	tmp_value = tmp->value;
	tmp->value = tmp->next->value;
	tmp->next->value = tmp_value;
	write(1, "sb\n", 3);
}

void	ss(t_node **heada, t_node **headb)
{
	sa(heada);
	sb(headb);
	write(1, "ss\n", 3);
}

void	pa(t_node **heada, t_node **headb)
{
	t_node	*tmp;

	if (*headb == NULL)
		return ;
	tmp = *headb;
	*headb = tmp->next;
	tmp->next = *heada;
	*heada = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_node **heada, t_node **headb)
{
	t_node	*tmp;

	if (*heada == NULL)
		return ;
	tmp = *heada;
	*heada = tmp->next;
	tmp->next = *headb;
	*headb = tmp;
	write(1, "pb\n", 3);
}
