#include "pushswap.h"

int ft_atoi (char *str){
    
    int i = 0;
    long res = 0;
    int sign = 1;

    if (str[i] == '-'){
        sign = -sign;
        i++;
    }

    while (str[i]){
        res = res * 10 + (str[i] - '0');
        if (res * sign > 2147483647 || res * sign < -2147483648){
            write(2, "Error\n", 6);
            exit(1);
        }
        i++;
    }
    return (res * sign);
}