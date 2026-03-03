#include "pushswap.h"


void print_menu()
{
    printf("┌──────────────────────────────┐\n");
    printf("│  sa  sb  ss                  │\n");
    printf("│  pa  pb                      │\n");
    printf("│  ra  rb  rr                  │\n");
    printf("│  rra rrb rrr  |  q=quitter   │\n");
    printf("└──────────────────────────────┘\n");
    printf("Operation : ");
}

void print_stacks(t_node *a, t_node *b)
{
    printf("\033[2J\033[H");  // efface le terminal
    t_node *ca = a;
    t_node *cb = b;
    printf("\n┌─────────────────────────────┐\n");
    printf("│  STACK A           STACK B  │\n");
    printf("├─────────────────────────────┤\n");
    if (!ca && !cb)
        printf("│  (vide)            (vide)   │\n");
    while (ca || cb)
    {
        printf("│  ");
        if (ca) { printf("%-8d", ca->value); ca = ca->next; }
        else printf("        ");
        printf("          ");
        if (cb) { printf("%-8d", cb->value); cb = cb->next; }
        else printf("        ");
        printf(" │\n");
    }
    printf("└─────────────────────────────┘\n\n");
}