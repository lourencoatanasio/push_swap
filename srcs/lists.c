/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:34:57 by ldiogo            #+#    #+#             */
/*   Updated: 2023/02/24 12:34:58 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_list(t_node **head)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = *head;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*head = NULL;
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->value = value;
	node->checked = 0;
	node->next = NULL;
	return (node);
}

void	add_node(t_node **head, t_node *node)
{
	t_node	*tmp;

	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
}

t_node	*cpy_lst(t_node *node)
{
	t_node	*tmp;
	t_node	*new;

	tmp = node;
	new = NULL;
	while (tmp)
	{
		add_node(&new, create_node(tmp->value));
		tmp = tmp->next;
	}
	return (new);
}

void	bubble_sort_lst(t_node *head)
{
	t_node	*tmp;
	t_node	*tmp2;
	int		i;
	int		n;
	int		tmp3;

	tmp = head;
	tmp2 = head;
	i = 0;
	n = node_counter(&head);
	while (i < n)
	{
		while (tmp2->next)
		{
			if (tmp2->value > tmp2->next->value)
			{
				tmp3 = tmp2->value;
				tmp2->value = tmp2->next->value;
				tmp2->next->value = tmp3;
			}
			tmp2 = tmp2->next;
		}
		tmp2 = tmp;
		i++;
	}
}
