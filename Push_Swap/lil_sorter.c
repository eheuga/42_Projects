#include "pushswap.h"

void little_sorter(t_node **stack_a)
{       
    int a = (*stack_a)->value;
    int b = (*stack_a)->next->value;
    int c = (*stack_a)->next->next->value;

    if (a > b && c > a)   // 2 1 3
        swap_a(stack_a, 1);

    else if (a > c && c > b) // 3 1 2 
        rotate_a(stack_a, 1);   

    else if (b > a && b > c && c > a) // 1 3 2
    {
        reverse_rotate_a(stack_a, 1);
        swap_a(stack_a, 1);
    }
    else if (b > a && a > c && b > c) // 2 3 1
        reverse_rotate_a(stack_a, 1);

    else if (a > b && a > c) // 3 2 1
    {
        rotate_a(stack_a, 1);
        swap_a(stack_a, 1);
    }


}


int find_min (t_node *stack_a){
    int min = stack_a->value;
    t_node *current = stack_a;

    while (current->next != NULL)
    {
        if (min > current->next->value)
            min = current->next->value;

        current = current->next;
    }
    return min;
}

void push_min(t_node **stack_a, t_node **stack_b, int min)
{
    while ((*stack_a)->value != min)
        rotate_a(stack_a, 1);

    push_b(stack_a, stack_b);
}

void little_sorter4(t_node **stack_a, t_node **stack_b){
    
    int min = 0;
    
    min = find_min(*stack_a);
    push_min(stack_a, stack_b, min);

    little_sorter(stack_a);

    push_a(stack_a, stack_b);

}


void little_sorter5 (t_node **stack_a, t_node **stack_b){
    
    int min = 0;
    
    min = find_min(*stack_a);
    push_min(stack_a, stack_b, min);
    
    min = find_min(*stack_a);
    push_min(stack_a, stack_b, min);

    if ((*stack_b)->value < (*stack_b)->next->value)
        swap_b(stack_b, 1);

    little_sorter(stack_a);
    
    push_a(stack_a, stack_b);
    push_a(stack_a, stack_b);

}