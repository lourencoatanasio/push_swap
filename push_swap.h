#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<time.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				checked;
	struct s_node	*next;
}	t_node;

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}	t_moves;

typedef struct s_n
{
	int	number;
	int	index;
}	t_n;

void	free_list(t_node **head);
void	exit_free(t_node **heada, t_node **headb);
int		ft_atoi(char *str);
t_node	*create_node(int value);
void	add_node(t_node **head, t_node *node);
int		node_counter(t_node **head);
t_node	*cpy_lst(t_node *node);
void	bubble_sort_lst(t_node *head);
void	assign_index(t_node **head);
void	sort_n_change(t_node **heada);
int		compare_lst(t_node **heada, t_node **headb);
void	push_ev(t_node **heada, t_node **headb);
int		check_index(t_node **headb, int n);
int		total_moves(t_moves moves);
int		next_a(t_node **heada, int n);
void	execute_single_moves(t_node **heada, t_node **headb, t_moves moves);
void	execute_moves(t_node **heada, t_node **headb, t_moves moves);
t_moves	assign_moves(t_node **heada, t_node **headb, t_moves moves, t_n assign);
t_moves	init_moves(void);
t_moves	check_moves(t_node **heada, t_node **headb, int n, t_moves moves);
void	if_e_else(t_node **heada);
void	from_b(t_node **heada, t_node **headb);
int		check_min(t_node **heada);
void	put_min_top(t_node **heada);
void	only_three(t_node **heada);
void	only_four(t_node **heada, t_node **headb);
void	only_five(t_node **heada, t_node **headb);
void	small_sort(t_node **heada, t_node **headb);
void	algorithm(t_node **heada, t_node **headb);
void	repeat_check(t_node **heada, t_node **headb);
int		ft_strcmp(char *s1, char *s2);
void	check_int_cap(char *str, t_node **heada, t_node **headb);
int		ft_isdigit(char *c, t_node **heada, t_node **headb);
void	sa(t_node **heada);
void	sb(t_node **headb);
void	ss(t_node **heada, t_node **headb);
void	pa(t_node **heada, t_node **headb);
void	pb(t_node **heada, t_node **headb);
void	ra(t_node **heada);
void	rb(t_node **headb);
void	ra2(t_node **heada);
void	rb2(t_node **headb);
void	rr(t_node **heada, t_node **headb);
void	rra(t_node **heada);
void	rrb(t_node **headb);
void	rra2(t_node **heada);
void	rrb2(t_node **headb);
void	rrr(t_node **heada, t_node **headb);

#endif