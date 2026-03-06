#include "pushswap.h"


void push_chunks (t_node **stack_a, t_node **stack_b, int chunks_count, int chunks_size){

    int i = 0;
    int j = 0;

    int chunk_min;
    int chunk_max;

    while (i < chunks_count){
        
        chunk_min = chunks_size * i;
        chunk_max = chunks_size * (i + 1) ;
        
        j = 0;
        while (j < chunks_size){
            if ((*stack_a)->value >= chunk_min && (*stack_a)->value < chunk_max){
                push_b(stack_a, stack_b);
                j++;
            }
            else 
                rotate_a(stack_a, 1);
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

void push_max (t_node **stack_a, t_node **stack_b, int max){

    while ((*stack_b)->value != max)
        rotate_b(stack_b, 1);

    push_a (stack_a, stack_b);


}



// void fat_sorter (**stack_a, **stack_b, int args_nbr){

//     int chunk_size = args_nbr / 5;



// }