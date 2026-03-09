#include "pushswap.h"

int op_count = 0; //    A SUPPRIMER !!!

int main(int ac, char **av)
{
       

    int i = 1;
    int *index_tab;
    t_node *stack_a = NULL;
    t_node *stack_b = NULL;
    
    int args_nbr = 0;
    int chunks_size = 0;
    int chunks_count ;
    int max;

    if (ac == 1)
        return (0);



    while (i < ac)
    {
        if (!is_valid_number(av[i]))
        {
            write(2, "Error\n", 6);
            return (1);
        }
        i++;
    }

    is_number_dup(ac, av);

    i = 1;
    while (i < ac){
        add_back(&stack_a, new_node(ft_atoi(av[i])));
        i++;
    }
    
    if(sorted_verif(stack_a))
        return (0);


    args_nbr = ac - 1;
    
    //print_stacks(stack_a, stack_b, args_nbr);
    
    
    index_tab = indexer(&stack_a);

    set_index (&stack_a, index_tab);
    //print_stacks(stack_a, stack_b, args_nbr);

    if(args_nbr == 2)
        swap_a(&stack_a, 1);

    else if(args_nbr == 3)
        little_sorter(&stack_a);
        
    else if (args_nbr == 4 )
        little_sorter4(&stack_a, &stack_b);

    else if (args_nbr == 5 )
        little_sorter5(&stack_a, &stack_b);

    else if (args_nbr <= 100){
        chunks_size = args_nbr /5;
        chunks_count = args_nbr /chunks_size ;
        push_chunks (&stack_a, &stack_b, chunks_count, chunks_size);
        while (stack_b){
            max = find_max(stack_b);
            push_max(&stack_a, &stack_b, max);
        }
    }
    

    else //if (args_nbr <= 500)
    {
        chunks_size = args_nbr / 8;
        chunks_count = args_nbr /chunks_size ;
        push_chunks (&stack_a, &stack_b, chunks_count, chunks_size);
        while (stack_b){
            max = find_max(stack_b);
            push_max(&stack_a, &stack_b, max);
        }
    }


    //print_stacks(stack_a, stack_b, args_nbr);

    printf("\n - %d values %d operation(s) -\n", args_nbr, op_count);
    free_stack(stack_a);
    free_stack(stack_b);
    
    free(index_tab);


    return 0;


}
