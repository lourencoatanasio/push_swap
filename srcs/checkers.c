/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:34:51 by ldiogo            #+#    #+#             */
/*   Updated: 2023/02/24 12:34:52 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(char *c, t_node **heada, t_node **headb)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		if (c[i] == '-' && i == 0 && c[i + 1] != '\0')
			i++;
		if (c[i] < '0' || c[i] > '9')
			exit_free(heada, headb);
		i++;
	}
	return (0);
}

void	check_int_cap(char *str, t_node **heada, t_node **headb)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			i++;
		len++;
		i++;
	}
	if (len > 10)
		exit_free(heada, headb);
	if (len == 10)
	{
		if (str[0] == '-')
		{
			if (ft_strcmp(str, "-2147483648") > 0)
				exit_free(heada, headb);
		}
		else
			if (ft_strcmp(str, "2147483647") > 0)
				exit_free(heada, headb);
	}
}

void	repeat_check(t_node **heada, t_node **headb)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = *heada;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
				exit_free(heada, headb);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
