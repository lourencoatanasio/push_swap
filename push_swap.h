#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<stdbool.h>
# include<time.h>

typedef struct s_node
{
	int		value;
    int    index;
	struct s_node	*next;
}	t_node;

typedef struct s_moves
{
    int     ra;
    int     rb;
    int     rra;
    int     rrb;
    int     total;
}   t_moves;

void	sa(t_node **heada);
void	sb(t_node **headb);
void	ss(t_node **heada, t_node **headb);
void	pa(t_node **heada, t_node **headb);
void	pb(t_node **heada, t_node **headb);
void	ra(t_node **heada);
void	rb(t_node **headb);
void	rr(t_node **heada, t_node **headb);
void	rra(t_node **heada);
void	rrb(t_node **headb);
void	rrr(t_node **heada, t_node **headb);
void	print_stacks(t_node *heada, t_node *headb);
void	free_list(t_node **head);
void	add_node(t_node **head, t_node *node);
t_node	*create_node(int value);
int		ft_atoi(char *str);

#endif