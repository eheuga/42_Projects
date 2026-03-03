#include "pushswap.h"

int main(int ac, char **av)
{
    
    int i = 1;
    t_node *stack_a = NULL;
    t_node *stack_b = NULL;
    char input[10];

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

    print_stacks(stack_a, stack_b);
    while (1)
    {
        print_menu();
        if (!fgets(input, sizeof(input), stdin)) break;
        input[strcspn(input, "\n")] = '\0';
        if (input[0] == '\0') continue;
        
        if      (!strcmp(input, "sa"))  swap_a(&stack_a, 1);
        else if (!strcmp(input, "sb"))  swap_b(&stack_b, 1);
        else if (!strcmp(input, "ss"))  sswap(&stack_a, &stack_b);
        else if (!strcmp(input, "pa"))  push_a(&stack_a, &stack_b);
        else if (!strcmp(input, "pb"))  push_b(&stack_a, &stack_b);
        else if (!strcmp(input, "ra"))  reverse_a(&stack_a, 1);
        else if (!strcmp(input, "rb"))  reverse_b(&stack_b, 1);
        else if (!strcmp(input, "rr"))  reverse_ab(&stack_a, &stack_b);
        else if (!strcmp(input, "rra")) rreverse_a(&stack_a, 1);
        else if (!strcmp(input, "rrb")) rreverse_b(&stack_b, 1);
        else if (!strcmp(input, "rrr")) rreverse_ab(&stack_a, &stack_b);
        else if (!strcmp(input, "q"))   { printf("Bye!\n"); break; }
        else { printf("Operation inconnue\n"); continue; }
        
        print_stacks(stack_a, stack_b);
    }
 




    return 0;
}