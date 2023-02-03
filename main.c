#include "push_swap.h"

int ft_atoi(char *str) {
    int i = 0;
    int sign = 1;
    int result = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r') {
        i++;
    }
    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    else if (str[i] == '+') {
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result * sign;
}

t_node	*create_node(int value) {
    t_node *node = (t_node *)malloc(sizeof(t_node));
    node->value = value;
    node->next = NULL;
    return node;
}

void	add_node(t_node **head, t_node *node) {
    if (*head == NULL) {
        *head = node;
        return ;
    }
    t_node *tmp = *head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = node;
}

void    free_list(t_node **head) {
    t_node *tmp = *head;
    while (tmp != NULL) {
        t_node *tmp2 = tmp->next;
        free(tmp);
        tmp = tmp2;
    }
    *head = NULL;
}

void	print_stacks(t_node *heada, t_node *headb)
{
	while (heada || headb)
	{
		if (heada)
			printf("%d    ", heada->value);
		else
			printf("     ");
		if (headb)
			printf("%d\n", headb->value);
		else
			printf("\n");
		if (heada)
			heada = heada->next;
		if (headb)
			headb = headb->next;
	}
	printf("################\n");
}

int node_counter(t_node **head)
{
	int i = 0;
	t_node *tmp = *head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return i;
}

void	push_min_max(t_node **heada, t_node **headb, int min, int max)
{
	if (!heada || !headb)
		return ;
	t_node *tmp = *heada;
	int i = 0;
	while (i <= node_counter(heada)) {
		printf("value = %i\n", tmp->value);
		if (tmp->value != min && tmp->value != max) {
			write(1, "pb\n", 3);
			pb(heada, headb);
		}
		else {
			write(1, "ra\n", 3);
			ra(heada);
			print_stacks(*heada, *headb);
		}
		tmp = *heada;
		i++;
	}
}

void	find_min_max(t_node **heada, t_node **headb)
{
	if (!heada || !headb)
		return ;
	int min = 2147483647;
	int max = -2147483648;
	struct s_node *tmp = *heada;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	push_min_max(heada, headb, min, max);
	printf("min = %d, max = %d\n", min, max);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        write(1, "error\n", 6);
        return 0;
    }
    t_node *heada = NULL;
    t_node *headb = NULL;
    int i = 1;
    while (i < argc) {
        add_node(&heada, create_node(ft_atoi(argv[i])));
        i++;
    }
	print_stacks(heada, headb);
	find_min_max(&heada, &headb);
		
	print_stacks(heada, headb);
    free_list(&heada);
	free_list(&headb);
    return 0;
}
