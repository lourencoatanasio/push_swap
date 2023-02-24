/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:35:03 by ldiogo            #+#    #+#             */
/*   Updated: 2023/02/24 12:35:04 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_node **heada)
{
	t_node	*tmp;

	if (*heada == NULL)
		return ;
	tmp = *heada;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *heada;
	*heada = tmp->next;
	tmp->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_node **headb)
{
	t_node	*tmp;

	if (*headb == NULL)
		return ;
	tmp = *headb;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *headb;
	*headb = tmp->next;
	tmp->next = NULL;
	write(1, "rrb\n", 4);
}

void	rra2(t_node **heada)
{
	t_node	*tmp;

	if (*heada == NULL)
		return ;
	tmp = *heada;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *heada;
	*heada = tmp->next;
	tmp->next = NULL;
}

void	rrb2(t_node **headb)
{
	t_node	*tmp;

	if (*headb == NULL)
		return ;
	tmp = *headb;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *headb;
	*headb = tmp->next;
	tmp->next = NULL;
}

void	rrr(t_node **heada, t_node **headb)
{
	rra2(heada);
	rrb2(headb);
	write(1, "rrr\n", 4);
}
