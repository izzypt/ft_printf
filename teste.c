/* CELEBV01                                      

   This example passes a variable number of arguments to a function,            
   stores each argument in an array, and prints each argument.                  

 */      

#include <stdio.h>                                                              
#include <stdarg.h>                                                             
                                                                                
void    vout(int max, ...);                                                        
                                                                                
int main(void)                                                                  
{                                                                               
   vout(3, "Sabado", "Domingo", "Segunda");                                                
   printf("\n");                                                                
   vout(5, "Segunda", "Terca", "Quarta", "Quinta", "Sexta");                               
}                                                                               
                                                                                
void vout(int max, ...)                                                         
{                                                                               
    va_list dias_da_semana;
    va_start(dias_da_semana, max);

    for (int i = 0; i < max; i++) {
        char *str = va_arg(dias_da_semana, char*);
        printf("%s\n", str);
    }

  va_end(dias_da_semana);                                               
}   