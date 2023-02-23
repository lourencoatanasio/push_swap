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

void	exit_free(t_node **heada, t_node **headb)
{
	free_list(heada);
	free_list(headb);
	write(1, "Error\n", 6);
	exit(0);
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

int	check_index(t_node **headb, int n)
{
	t_node	*tmp;
	int		i;

	tmp = *headb;
	i = 0;
	while (tmp)
	{
		if (tmp->value == n)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

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

void    execute_single_moves(t_node **heada, t_node **headb, t_moves *moves)
{
    while(moves->ra != 0 || moves->rb != 0 || moves->rra != 0 || moves->rrb != 0)
    {
        if(moves->ra != 0)
        {
            ra(heada);
            moves->ra--;
        }
        if(moves->rb != 0)
        {
            rb(headb);
            moves->rb--;
        }
        if(moves->rra != 0)
        {
            rra(heada);
            moves->rra--;
        }
        if(moves->rrb != 0)
        {
            rrb(headb);
            moves->rrb--;
        }
    }
}

void    execute_moves(t_node **heada, t_node **headb, t_moves *moves)
{
    while(moves->ra != 0 && moves->rb != 0) {
        moves->ra--;
        moves->rb--;
        rr(heada, headb);
    }
    while(moves->rra != 0 && moves->rrb != 0) {
        moves->rra--;
        moves->rrb--;
        rrr(heada, headb);
    }
    execute_single_moves(heada, headb, moves);
}

//t_moves	assign_moves_a(t_node **heada, t_moves moves, int index)
//{
//	if (index <= node_counter(heada) / 2)
//		moves.ra = index;
//	else
//		moves.rra = node_counter(heada) - index;
//	return (moves);
//}
//
//t_moves	assign_moves_b(t_node **headb, t_moves moves, int index)
//{
//	if (index < node_counter(headb) / 2 + 1)
//		moves.rb = index;
//	else
//		moves.rrb = node_counter(headb) - index;
//	return (moves);
//}

t_moves assign_moves(t_node **heada, t_node **headb, t_moves moves, int index, int n)
{
	if(n == 0) {
		if (index <= node_counter(heada) / 2) {
			moves.ra = index;
		} else {
			moves.rra = node_counter(heada) - index;
		}
	}
	else {
		if (index < node_counter(headb) / 2 + 1) {
			moves.rb = index;
		} else {
			moves.rrb = node_counter(headb) - index;
		}
	}
	return moves;
}

t_moves *init_moves(t_moves *moves)
{
    moves->ra = 0;
    moves->rb = 0;
    moves->rra = 0;
    moves->rrb = 0;
    moves->total = 0;
    return moves;
}

t_moves	check_moves(t_node **heada, t_node **headb, int n, t_moves moves)
{
	int	indexb;
	int	indexa;

	moves = init_moves();
	indexb = check_index(headb, n);
	indexa = next_a(heada, n);
	moves = assign_moves(heada, headb, moves, indexa, 0);
	moves = assign_moves(heada, headb, moves, indexb, 1);
	return (moves);
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

int check_min(t_node **heada)
{
	t_node *tmp = *heada;
	int min = tmp->value;
	while(tmp)
	{
		if(tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return min;
}

void	put_min_top(t_node **heada)
{
	int i = check_min(heada);
	if(i < node_counter(heada) / 2)
		while(check_index(heada, i) != 0) {
			ra(heada);
		}
	else
		while(check_index(heada, i) != 0)
			rra(heada);
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
	if((*heada)->value == check_min(heada))
		pb(heada, headb);
	only_three(heada);
	pa(heada, headb);
}

void	only_five(t_node **heada, t_node **headb)
{
	put_min_top(heada);
	if((*heada)->value == check_min(heada))
		pb(heada, headb);
	only_four(heada, headb);
	pa(heada, headb);
}

void	small_sort(t_node **heada, t_node **headb)
{
	if(node_counter(heada) == 2)
	{
		if((*heada)->value > (*heada)->next->value)
			sa(heada);
	}
	else if(node_counter(heada) == 3)
		only_three(heada);
	else if(node_counter(heada) == 4)
		only_four(heada, headb);
	else if(node_counter(heada) == 5)
		only_five(heada, headb);
}

void    algorithm(t_node **heada, t_node **headb)
{
    t_node *solve;
    solve = cpy_lst(*heada);
    bubble_sort_lst(solve);
	if(compare_lst(heada, &solve) == 0) {
		if (node_counter(heada) <= 5)
			small_sort(heada, headb);
		while (compare_lst(heada, &solve) == 0) {
			push_ev(heada, headb);
			from_b(heada, headb);
		}
	}
    free_list(&solve);
}

void	push_swap(t_node **heada, t_node **headb)
{
    sort_n_change(heada);
    algorithm(heada, headb);
}

void    repeat_check(t_node **heada, t_node **headb)
{
    t_node *tmp = *heada;
    t_node *tmp2;
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

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i];
}

void    check_int_cap(char *str, t_node **heada, t_node **headb)
{
    int i = 0;
    int len = 0;
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

int ft_isdigit(char *c, t_node **heada, t_node **headb)
{
    int i = 0;
    while (c[i] != '\0')
    {
        if (c[i] == '-' && i == 0 && c[i + 1] != '\0')
        {
            i++;
            continue;
        }
        if (c[i] < '0' || c[i] > '9')
            exit_free(heada, headb);
        i++;
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        write(1, "Error\n", 6);
        return 0;
    }
    t_node *heada = NULL;
    t_node *headb = NULL;
    int i = 1;
    while (i < argc) {
        ft_isdigit(argv[i], &heada, &headb);
        check_int_cap(argv[i], &heada, &headb);
        add_node(&heada, create_node(ft_atoi(argv[i])));
        i++;
    }
    repeat_check(&heada, &headb);
    push_swap(&heada, &headb);
    free_list(&heada);
	free_list(&headb);
    return 0;
}
