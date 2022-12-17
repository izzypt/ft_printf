# ft_printf
You have to recode the printf() function from libc.

| Requirements | Description |
| --- | --- |
| Program name  | libftprintf.a |
| Turn in files  | Makefile, *.h, */*.h, *.c, */*.c |
| Makefile | NAME, all, clean, fclean, re |
| External functs| malloc, free, write, va_start, va_arg, va_copy, va_end |
| Libft authorized | Yes |
| Description | Write a library that contains ft_printf(), a function that will mimic the original printf()|


The prototype of ft_printf() is:
  ###
    int ft_printf(const char *, ...);

Here are the requirements:
 
    • Don’t implement the buffer management of the original printf().
    • Your function has to handle the following conversions: cspdiuxX%
    • Your function will be compared against the original printf().
    • You must use the command ar to create your library.
    Using the libtool command is forbidden.
    • Your libftprintf.a has to be created at the root of your repository.


You have to implement the following conversions:
    
    • %c Prints a single character.
    • %s Prints a string (as defined by the common C convention).
    • %p The void * pointer argument has to be printed in hexadecimal format.
    • %d Prints a decimal (base 10) number.
    • %i Prints an integer in base 10.
    • %u Prints an unsigned decimal (base 10) number.
    • %x Prints a number in hexadecimal (base 16) lowercase format.
    • %X Prints a number in hexadecimal (base 16) uppercase format.
    • %% Prints a percent sign.
    
## Helpful Concepts

### <stdarg.h> : va_list, va_start and va_arg 

va_list, va_arg, and va_start are used to allow a function to accept a variable number of arguments.

In C, it is not possible to define a function with a variable number of arguments in the traditional sense. However, it is possible to define a function that takes a variable number of arguments by using a mechanism called "variable argument lists". This is done using three macros:

va_list: This is a type that is used to hold a list of arguments of a variable number.
va_start: This macro is used to initialize a va_list object and start accessing the arguments in the list.
va_arg: This macro is used to access the next argument in the list.

``` 
        #include <stdarg.h>

        int sum(int num, ...) {
            va_list args;
            va_start(args, num);

            int result = 0;
            for (int i = 0; i < num; i++) {
                result += va_arg(args, int);
            }

            va_end(args);
            return result;
        }

        int main() 
        {
            int s = sum(3, 1, 2, 3);  // s will be 6
            return 0;
        }
```
