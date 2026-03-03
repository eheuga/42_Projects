#include "pushswap.h"

int sorted_verif(t_node *stack_a)
{
    t_node *current = stack_a;

    while (current->next != NULL)
    {
        if (current->value > current->next->value){
            return (0);
        }
        current = current->next;
    }
    return (1);
}
