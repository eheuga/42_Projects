#include "pushswap.h"


int is_valid_number (char *str){
    int i = 0;
    
    if (str[i] == '-')
        i++; 
    
    if (!str[i])
        return (0);
    
    while (str[i]){
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}


int is_number_dup (int ac, char **str){
    int i = 1;
    int j;

    while (i < ac){
        j = i + 1;
        while (str[j]){
            if (ft_atoi(str[i]) == ft_atoi(str[j])){
                write(2, "Error\n",6);
                exit(1);
            }
            j++;
        }
        i++;
    }
    return (1);
}

int count_args (t_node *stack_a){
    int i = 1;
    t_node *current = stack_a;

    while (current->next != NULL){
        i++;
        current = current->next;
    }

    return i;
}