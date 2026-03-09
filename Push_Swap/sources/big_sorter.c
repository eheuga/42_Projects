#include "pushswap.h"



int find_closest_in_chunk (t_node *stack_a, int chunk_min, int chunk_max){

    t_node *current  = stack_a;
    int stack_size =0;

    int pos = 0;
    int best_pos;
    int top_dist;
    int bottom_dist;
    int dist;
    int best_dist;

    while (current != NULL)
    {
        current = current->next;
        stack_size++;
    }

    current = stack_a;
    best_pos = stack_size;
    best_dist = stack_size;

    while (current != NULL){
        
        if (current->value >= chunk_min && current->value < chunk_max)
        {   
            top_dist = pos;
            bottom_dist = stack_size - pos;
            if (top_dist < bottom_dist)
                dist = top_dist;
            else
                dist = bottom_dist;

            if (dist < best_dist){
                best_dist = dist;
                best_pos = pos;
                }
        }
        pos ++;
        current = current->next;
    }
    return best_pos;
}


void push_chunks (t_node **stack_a, t_node **stack_b, int chunks_count, int chunks_size){
    
    int i = 0;
    int j = 0;
    int pos;
    int chunk_min;
    int chunk_max;
    int stack_size = 0;
    t_node *current = *stack_a;
    
    pos = 0;
    while (current != NULL){
        stack_size++;
        current = current->next;
    }
    
    while (i < chunks_count)
    {
        chunk_min = chunks_size * i;
        chunk_max = chunks_size * (i + 1);
        j = 0;
        while (j < chunks_size)
        {
            if ((*stack_a)->value >= chunk_min && (*stack_a)->value < chunk_max)
            {
                push_b(stack_a, stack_b);
                j++;
                stack_size--;
            }
            else
            {
                pos = find_closest_in_chunk(*stack_a, chunk_min, chunk_max);
                if (pos <= stack_size / 2)
                    rotate_a(stack_a, 1);
                else
                    reverse_rotate_a(stack_a, 1);
            }
        }
        i++;
    }  
}




int find_max (t_node *stack_b){
    
    t_node *current = stack_b;
    int max = stack_b->value;
    
    while (current != NULL){
        if (current->value > max)
        max = current->value;
    current = current->next;
    
}
return max;
}

int find_position(t_node *stack, int value)
{
    t_node  *current = stack;
    int     pos = 0;

    while (current->value != value)
    {
        pos++;
        current = current->next;
    }
    return pos;
}

void push_max (t_node **stack_a, t_node **stack_b, int max){
    
    int pos;
    int stack_size = 0;
    t_node *current = *stack_b;

    while (current != NULL){
        stack_size++;
        current = current->next;
    }
    
    pos = find_position(*stack_b, max);

    if (pos < stack_size/2){
    
        while ((*stack_b)->value != max)
            rotate_b(stack_b, 1);

        push_a (stack_a, stack_b);
    }

    else {

        while ((*stack_b)->value != max)
            reverse_rotate_b(stack_b, 1);

        push_a (stack_a, stack_b);
    }

}