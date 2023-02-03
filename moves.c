#include "push_swap.h"

void    sa(t_node **heada) {
    t_node *tmp = *heada;
    int tmp_value = tmp->value;
    tmp->value = tmp->next->value;
    tmp->next->value = tmp_value;
}

void    sb(t_node **headb) {
	if (*headb == NULL)
		return ;
    t_node *tmp = *headb;
    int tmp_value = tmp->value;
    tmp->value = tmp->next->value;
    tmp->next->value = tmp_value;
}

void    ss(t_node **heada, t_node **headb) {
    sa(heada);
    sb(headb);
}

void    pa(t_node **heada, t_node **headb) {
	if (*headb == NULL)
		return ;
    t_node *tmp = *headb;
    *headb = tmp->next;
    tmp->next = *heada;
    *heada = tmp;
}

void    pb(t_node **heada, t_node **headb) {
	if (*heada == NULL)
		return ;
    t_node *tmp = *heada;
    *heada = tmp->next;
    tmp->next = *headb;
    *headb = tmp;
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
}

void    rr(t_node **heada, t_node **headb) {
    ra(heada);
    rb(headb);
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
}

void    rrr(t_node **heada, t_node **headb) {
    rra(heada);
    rrb(headb);
}
