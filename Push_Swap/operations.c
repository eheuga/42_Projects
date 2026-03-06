#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"

t_node *new_node (int value)
{
    t_node *node;
    node = malloc(sizeof (t_node));

    if (!node)
        return (NULL);

    node->value = value;
    node->next = NULL;
    return (node);
}


void add_back (t_node **head, t_node *new){
    
    t_node *current;

    if (!*head){
        *head = new;
        return;
    }

    current = *head;

    while (current->next != NULL)
        current = current->next;

    current->next = new;
}

void add_front (t_node **head, t_node *new){

    new->next = *head;
    *head = new;
}

void push_a (t_node **stack_a, t_node **stack_b){

    t_node *tmp;
    
    if (!*stack_b)
        return;

    
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;

    add_front(stack_a, tmp);

    op_count++; // A SUPPRIMER !!!
    printf("pa\n");
}

void push_b (t_node **stack_a, t_node **stack_b){

    t_node *tmp;
    
    if (!*stack_a)
        return;

    
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;

    add_front(stack_b, tmp);

        op_count++; // A SUPPRIMER !!!

    printf("pb\n");

}

void swap_a (t_node **stack_a, int print){

    t_node *tmp1;
    t_node *tmp2;
    t_node *tmp3;

    tmp1 = *stack_a;
    tmp2 = (*stack_a)->next;
    tmp3 = tmp2->next;

    tmp2->next = tmp1;
    tmp1->next = tmp3;
    *stack_a= tmp2;

    if (print)
        printf("sa\n");
    
}

void swap_b (t_node **stack_b, int print){

    t_node *tmp1;
    t_node *tmp2;
    t_node *tmp3;

    tmp1 = *stack_b;
    tmp2 = (*stack_b)->next;
    tmp3 = tmp2->next;

    tmp2->next = tmp1;
    tmp1->next = tmp3;
    *stack_b= tmp2;
    if (print){
        printf("sb\n");
    op_count++; // A SUPPRIMER !!!

    }

}

void sswap (t_node **stack_a, t_node **stack_b){
    swap_a(stack_a, 0); // 0 pour ne pas print sa
    swap_b(stack_b, 0);

    op_count++; // A SUPPRIMER !!!
    op_count++; // A SUPPRIMER !!!

    printf("ss\n");
}


void rotate_a (t_node **stack_a, int print){  // tout monte -> premier = dernier
    t_node *tmp;
    t_node *last;

    if (!*stack_a || !(*stack_a)->next)
        return;

    tmp = *stack_a; // sauvegarder premier noeud
    last = *stack_a;

    while (last->next != NULL) // trouve dernier noeud
        last = last->next;
    
    last->next = tmp; // lie le dernier noeud a premier
    (*stack_a) = (*stack_a)->next; // avance la tete au deuxieme noeud
    tmp->next = NULL; // tmp devient la fin de la liste
    if (print){
        printf("ra\n");
        
        op_count++; // A SUPPRIMER !!!
    }
}

void rotate_b (t_node **stack_b, int print){  // tout monte -> premier = dernier
    t_node *tmp;
    t_node *last;

    if (!*stack_b || !(*stack_b)->next)
        return;

    tmp = *stack_b; // sauvegarder premier noeud
    last = *stack_b;

    while (last->next != NULL) // trouve dernier noeud
        last = last->next;
    
    last->next = tmp; // lie le dernier noeud a premier
    (*stack_b) = (*stack_b)->next; // avance la tete au deuxieme noeud
    tmp->next = NULL; // tmp devient la fin de la liste
    
    if (print){
        printf("rb\n");

            op_count++; // A SUPPRIMER !!!

    }
}

void rotate_ab (t_node **stack_a, t_node **stack_b){
    rotate_a(stack_a, 0);
    rotate_b(stack_b, 0);
    
    op_count++; // A SUPPRIMER !!!
    op_count++; // A SUPPRIMER !!!

    
    printf("rr\n");
}


void reverse_rotate_a (t_node **stack_a, int print){ // tout baisse -> dernier = premier
    t_node *tmp;
    t_node *before_last;

    if (!*stack_a || !(*stack_a)->next)
        return;

    tmp = *stack_a;
    while (tmp->next->next != NULL) // trouve avant dernier noeud 
        tmp = tmp->next;
    
    
    before_last = tmp; // sauvegarde avant dernier noeud
    tmp = tmp->next; // tmp devient le dernier noeud
    before_last->next = NULL; // avant dernier noeud devient dernier 
    tmp->next = *stack_a; // tmp (dernier) point vers la tete
    *stack_a = tmp; // tmp devient premier (head)
    if (print){
        printf("rra\n");

            op_count++; // A SUPPRIMER !!!
    }
}

void reverse_rotate_b (t_node **stack_b, int print){ // tout baisse -> dernier = premier
    t_node *tmp;
    t_node *before_last;

    if (!*stack_b || !(*stack_b)->next)
        return;

    tmp = *stack_b;
    while (tmp->next->next != NULL) // trouve avant dernier noeud 
        tmp = tmp->next;
    
    
    before_last = tmp; // sauvegarde avant dernier noeud
    tmp = tmp->next; // tmp devient le dernier noeud
    before_last->next = NULL; // avant dernier noeud devient dernier 
    tmp->next = *stack_b; // tmp (dernier) point vers la tete
    *stack_b = tmp; // tmp devient premier (head)
    if (print)
        printf("rrb\n");
}

void reverse_rotate_ab (t_node **stack_a, t_node **stack_b){
    reverse_rotate_a(stack_a, 0);
    reverse_rotate_b(stack_b, 0);

        op_count++; // A SUPPRIMER !!!
    op_count++; // A SUPPRIMER !!!

        printf("rrr\n");
}

void free_stack(t_node *stack)
{
    t_node *tmp;

    if (!stack)
        return ;
    
    while (stack)
    {
        tmp = stack->next;
        free(stack);
        stack = tmp;
    }
}