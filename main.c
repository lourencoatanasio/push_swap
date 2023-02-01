#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node {
	int value;
	void *next;
} t_node;

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
	t_node *tmp = heada;
	while (tmp != NULL) {
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}

	return 0;
}
