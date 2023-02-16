#include "../push_swap.h"

void    sa(t_node **heada) {
    t_node *tmp = *heada;
    int tmp_value = tmp->value;
    tmp->value = tmp->next->value;
    tmp->next->value = tmp_value;
    write(1, "sa\n", 3);
}

void    sb(t_node **headb) {
	if (*headb == NULL)
		return ;
    t_node *tmp = *headb;
    int tmp_value = tmp->value;
    tmp->value = tmp->next->value;
    tmp->next->value = tmp_value;
    write(1, "sb\n", 3);
}

void    ss(t_node **heada, t_node **headb) {
    sa(heada);
    sb(headb);
    write(1, "ss\n", 3);
}

void    pa(t_node **heada, t_node **headb) {
	if (*headb == NULL)
		return ;
    t_node *tmp = *headb;
    *headb = tmp->next;
    tmp->next = *heada;
    *heada = tmp;
    write(1, "pa\n", 3);
}

void    pb(t_node **heada, t_node **headb) {
	if (*heada == NULL)
		return ;
    t_node *tmp = *heada;
    *heada = tmp->next;
    tmp->next = *headb;
    *headb = tmp;
    write(1, "pb\n", 3);
}

void    ra(t_node **heada) {
	if (*heada == NULL)
		return ;
    t_node *tmp = *heada;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = *heada;
    *heada = (*heada)->next;
    tmp->next->next = NULL;
    write(1, "ra\n", 3);
}

void    rb(t_node **headb) {
	if (*headb == NULL)
		return ;
    t_node *tmp = *headb;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = *headb;
    *headb = (*headb)->next;
    tmp->next->next = NULL;
    write(1, "rb\n", 3);
}

void    ra2(t_node **heada) {
    if (*heada == NULL)
        return ;
    t_node *tmp = *heada;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = *heada;
    *heada = (*heada)->next;
    tmp->next->next = NULL;
}

void    rb2(t_node **headb) {
    if (*headb == NULL)
        return ;
    t_node *tmp = *headb;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = *headb;
    *headb = (*headb)->next;
    tmp->next->next = NULL;
}

void    rr(t_node **heada, t_node **headb) {
    ra2(heada);
    rb2(headb);
    write(1, "rr\n", 3);
}

void    rra(t_node **heada) {
	if (*heada == NULL)
		return ;
    t_node *tmp = *heada;
    while (tmp->next->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next->next = *heada;
    *heada = tmp->next;
    tmp->next = NULL;
    write(1, "rra\n", 4);
}

void    rrb(t_node **headb) {
	if (*headb == NULL)
		return ;
    t_node *tmp = *headb;
    while (tmp->next->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next->next = *headb;
    *headb = tmp->next;
    tmp->next = NULL;
    write(1, "rrb\n", 4);
}

void    rrb2(t_node **headb) {
	if (*headb == NULL)
		return ;
	t_node *tmp = *headb;
	while (tmp->next->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next->next = *headb;
	*headb = tmp->next;
	tmp->next = NULL;
}

void    rrr(t_node **heada, t_node **headb) {
    rra2(heada);
    rrb2(headb);
    write(1, "rrr\n", 4);
}
