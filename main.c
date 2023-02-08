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

/*void	push_min_max(t_node **heada, t_node **headb, int min, int max)
{
	if (!heada || !headb)
		return ;
	t_node *tmp = *heada;
    int n = node_counter(heada);
	int i = 1;
	while (i <= n) {
		printf("value = %i\n", tmp->value);
		if (tmp->value != min && tmp->value != max) {
			write(1, "pb\n", 3);
			pb(heada, headb);
            print_stacks(*heada, *headb);
		}
		else {
			write(1, "ra\n", 3);
			ra(heada);
			print_stacks(*heada, *headb);
		}
		tmp = *heada;
		i++;
	}
}*/



/*int	*find_min_max(t_node **heada, t_node **headb)
{
	int *arr = (int *)malloc(sizeof(int) * 2);
	if (!heada || !headb)
		return 0;
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
	arr = (int[]){min, max};
	return (arr);
}*/

t_node *cpy_lst(t_node *node)
{
	t_node *tmp = node;
	t_node *new = NULL;
	while (tmp)
	{
		add_node(&new, create_node(tmp->value));
		tmp = tmp->next;
	}
	return new;
}

void	bubble_sort_lst(t_node *head)
{
	t_node *tmp = head;
	t_node *tmp2 = head;
	int i = 0;
	int n = node_counter(&head);
	while (i < n)
	{
		while (tmp2->next)
		{
			if (tmp2->value > tmp2->next->value)
			{
				int tmp3 = tmp2->value;
				tmp2->value = tmp2->next->value;
				tmp2->next->value = tmp3;
			}
			tmp2 = tmp2->next;
		}
		tmp2 = tmp;
		i++;
	}
}

void    assign_index(t_node **head)
{
    t_node *tmp = *head;
    int i = 0;
    while (tmp)
    {
        tmp->index = i;
        tmp = tmp->next;
        i++;
    }
}

int find_middle_node(t_node **heada)
{
	t_node *tmp;
	int n = node_counter(heada);
	int i = 1;
	t_node *cpy = cpy_lst(*heada);
	print_stacks(cpy, *heada);
	bubble_sort_lst(cpy);
	write(1, "sorted\n", 7);
	tmp = cpy;
	print_stacks(tmp, cpy);
	while (i <= n / 2)
	{
		tmp = tmp->next;
		i++;
	}
	printf("middle = %i\n", tmp->value);
	free_list(&cpy);
	return tmp->value;
}

void    print_index(t_node **head)
{
    t_node *tmp = *head;
    while (tmp)
    {
        printf("index = %i\n", tmp->index);
        tmp = tmp->next;
    }
}

void	sort_n_change(t_node **heada)
{
    t_node *tmp;
    t_node *t;
    t_node *a;
    tmp = cpy_lst(*heada);
    bubble_sort_lst(tmp);
    assign_index(&tmp);
    t = tmp;
    a = *heada;
    while(t)
    {
        while (a)
        {
            if (t->value == a->value)
            {
                a->value = t->index;
                break;
            }
            a = a->next;
        }
        a = *heada;
        t = t->next;
    }
    print_stacks(*heada, tmp);
    free_list(&tmp);
}

int ft_pow(int n, int pow)
{
    int i = 0;
    int res = 1;
    while (i < pow)
    {
        res *= n;
        i++;
    }
    return res;
}

int rtn_binary(int n)
{
    int i = 0;
    int binary = 0;
    while (n != 0)
    {
        binary += (n % 2) * ft_pow(10, i);
        n /= 2;
        i++;
    }
    return binary;
}

int str_num_check(char *str, int i)
{
    if (!str[i])
        return 2;
    if else(str[i] == '1')
        return 1;
    return 0;
}

int int_to_str(int n)
{
    int i = 0;
    int len = 0;
    int *arr = (int *)malloc(sizeof(int) * 10);
    while (n != 0)
    {
        arr[i] = n % 10;
        n /= 10;
        i++;
        len++;
    }
    i = 0;
    while (i < len)
    {
        if (arr[i] == 1)
            return 1;
        i++;
    }
    return 0;
}

int check_binary_unit(int n, int r)
{
    int i = 0;
    int binary = rtn_binary(n);

    if (i == 1)
        return 1;
    return 0;
}

void    algorithm(t_node **heada, t_node **headb)
{

    while (*headb)
    {
        write(1, "pa\n", 3);
        pa(heada, headb);
        print_stacks(*heada, *headb);
    }
}

void	push_swap(t_node **heada, t_node **headb)
{
    sort_n_change(heada);
    algorithm(heada, headb);
    print_stacks(*heada, *headb);
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
    push_swap(&heada, &headb);
    free_list(&heada);
	free_list(&headb);
    return 0;
}
