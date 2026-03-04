#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

// utils
t_node  *new_node(int value);
void    add_back(t_node **head, t_node *new);
void    add_front(t_node **head, t_node *new);

// validation
int     is_valid_number(char *str);
int     is_number_dup(int ac, char **str);
int     ft_atoi(char *str);
int     sorted_verif(t_node *stack_a);
int     count_args (t_node *stack_a);

// operations
void    push_a(t_node **stack_a, t_node **stack_b);
void    push_b(t_node **stack_a, t_node **stack_b);

void    swap_a(t_node **stack_a, int printstack_);
void    swap_b(t_node **b, int print);
void    sswap(t_node **stack_a, t_node **stack_b);

void    rotate_a(t_node **stack_a, int printstack_);
void    rotate_b(t_node **b, int print);
void    rotate_ab(t_node **stack_a, t_node **stack_b);

void    reverse_rotate_a(t_node **stack_a, int printstack_);
void    reverse_rotate_b(t_node **b, int print);
void    reverse_rotate_ab(t_node **stack_a, t_node **stack_b);


// sorting
void little_sorter(t_node **stack_a);

int find_min (t_node *stack_a);
void push_min(t_node **stack_a, t_node **stack_b, int min);
void little_sorter5 (t_node **stack_a, t_node **stack_b);



// menu
void    print_stacks(t_node *stack_a, t_node *bstack_, int args_nbr);
void    print_menu(void);

#endif