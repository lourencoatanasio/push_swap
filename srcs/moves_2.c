/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:35:06 by ldiogo            #+#    #+#             */
/*   Updated: 2023/02/24 12:35:07 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_node **heada)
{
	t_node	*tmp;

	if (*heada == NULL)
		return ;
	tmp = *heada;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *heada;
	*heada = (*heada)->next;
	tmp->next->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_node **headb)
{
	t_node	*tmp;

	if (*headb == NULL)
		return ;
	tmp = *headb;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *headb;
	*headb = (*headb)->next;
	tmp->next->next = NULL;
	write(1, "rb\n", 3);
}

void	ra2(t_node **heada)
{
	t_node	*tmp;

	if (*heada == NULL)
		return ;
	tmp = *heada;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *heada;
	*heada = (*heada)->next;
	tmp->next->next = NULL;
}

void	rb2(t_node **headb)
{
	t_node	*tmp;

	if (*headb == NULL)
		return ;
	tmp = *headb;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *headb;
	*headb = (*headb)->next;
	tmp->next->next = NULL;
}

void	rr(t_node **heada, t_node **headb)
{
	ra2(heada);
	rb2(headb);
	write(1, "rr\n", 3);
}
