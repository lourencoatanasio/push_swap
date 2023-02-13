#include "../push_swap.h"

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

char *fill_str(char *str, int n)
{
    int i = 0;
    n = 9 - n;
    while (i < n)
    {
        str[i] = '0';
        i++;
    }
    return str;
}

char *ft_strrev(char *str)
{
    int i = 0;
    int j = 0;
    char tmp;
    while (str[i] != '\0')
        i++;
    i--;
    while (j < i)
    {
        tmp = str[j];
        str[j] = str[i];
        str[i] = tmp;
        j++;
        i--;
    }
    return str;
}

char *itoa_binary(int n)
{
    int i = 0;
    int j = 8;
    int tmp = n;
    while (tmp != 0)
    {
        tmp /= 2;
        i++;
    }
    char *str = (char *)malloc(sizeof(char) * 10);
    while (n != 0)
    {
        str[j] = (n % 2) + '0';
        n /= 2;
        j--;
    }
    str[9] = '\0';
    str = fill_str(str, i);
    return str;
}

int check_binary(char *str, int n)
{
    if (str[n] == '0')
        return 0;
    else
        return 1;
}

int compare_lst(t_node **heada, t_node **headb)
{
    t_node *tmpa = *heada;
    t_node *tmpb = *headb;
    while (tmpa && tmpb)
    {
        if (tmpa->value != tmpb->value)
            return 0;
        tmpa = tmpa->next;
        tmpb = tmpb->next;
    }
    return 1;
}

void    algorithm(t_node **heada, t_node **headb)
{
    t_node *solve;
    t_node *tmp;
    int c = node_counter(heada);
    int n = 0;
    int i = 8;
    solve = cpy_lst(*heada);
    bubble_sort_lst(solve);
    while(compare_lst(heada, &solve) == 0) {
        tmp = *heada;
        while (n < c) {
            char *str = itoa_binary(tmp->value);
            if (check_binary(str, i) == 0)
                pb(heada, headb);
            else
                ra(heada);
            free(str);
            tmp = *heada;
            n++;
        }
        tmp = *headb;
        while (*headb)
            pa(heada, headb);
        i--;
        n = 0;
    }
    free_list(&solve);
}

void    exit_free(t_node **heada, t_node **headb)
{
    free_list(heada);
    free_list(headb);
    write(1, "Error\n", 6);
    exit(0);
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
        if (c[i] == '-' && i == 0)
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
        write(1, "error\n", 6);
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
    print_stacks(heada, headb);
    free_list(&heada);
	free_list(&headb);
    return 0;
}
