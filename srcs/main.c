/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:34:59 by ldiogo            #+#    #+#             */
/*   Updated: 2023/02/24 12:35:00 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*heada;
	t_node	*headb;
	int		i;

	i = 1;
	heada = NULL;
	headb = NULL;
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	while (i < argc)
	{
		ft_isdigit(argv[i], &heada, &headb);
		check_int_cap(argv[i], &heada, &headb);
		add_node(&heada, create_node(ft_atoi(argv[i])));
		i++;
	}
	repeat_check(&heada, &headb);
	sort_n_change(&heada);
	algorithm(&heada, &headb);
	free_list(&heada);
	free_list(&headb);
	return (0);
}
