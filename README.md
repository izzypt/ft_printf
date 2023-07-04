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

### Variadic functions

- Variadic functions are functions that can take a variable number of arguments. 
- It takes one fixed argument and then any number of arguments can be passed.
- The variadic function consists of at least one fixed variable and then an ellipsis(…) as the last parameter.

va_list, va_arg, and va_start are used to help us achieve this goal: to accept a variable number of arguments.

### Introduction to va_list and Variable Argument Functions in C:

In C programming, there are situations where we need to handle functions with a variable number of arguments. To achieve this flexibility, C provides a set of macros and types in the ```stdarg.h``` header, including va_list, va_start, and va_arg. These components allow us to work with a varying number of arguments passed to a function.

1. va_list:
  - The va_list type is used to declare a variable that holds the information about the variable arguments. It serves as a handle or pointer to access each argument passed to a function.

2. va_start:
  - The va_start macro initializes the va_list object, associating it with the last known fixed argument. It allows us to start accessing the variable arguments.

3. va_arg:
  - The va_arg macro extracts the next argument from the va_list. It takes the va_list object and the type of the expected argument as parameters, returning the value of the argument in the specified type.

Usage of va_list, va_start, and va_arg:

Let's consider an example to understand how to use va_list, va_start, and va_arg in C:

```c
#include <stdio.h>
#include <stdarg.h>

double average(int count, ...) {
    va_list args;
    double sum = 0;

    // Initialize va_list
    va_start(args, count);

    // Access variable arguments
    for (int i = 0; i < count; ++i) {
        double num = va_arg(args, double);
        sum += num;
    }

    // Clean up va_list
    va_end(args);

    return sum / count;
}

int main() {
    double avg1 = average(3, 2.5, 3.7, 4.2);
    double avg2 = average(4, 1.0, 2.0, 3.0, 4.0);

    printf("Average 1: %f\n", avg1);
    printf("Average 2: %f\n", avg2);

    return 0;
}
```

In this example, we define a function named `average` that calculates the average of a variable number of arguments. The function takes the count of arguments and then uses a va_list object `args` to handle the variable arguments.

Within the `average` function, we start by initializing the va_list object using `va_start(args, count)`, where `args` is the va_list object and `count` is the last known fixed argument.

Next, we use a loop to access each variable argument by calling `va_arg(args, double)`, where `args` is the va_list object and `double` is the expected type of the argument. The `va_arg` macro retrieves the next argument from the va_list and casts it to the specified type.

After accessing all the variable arguments, we clean up the va_list using `va_end(args)` to release any resources associated with it.

In the `main` function, we demonstrate the usage of the `average` function with different numbers of arguments, and then print the calculated averages using printf.

By utilizing va_list, va_start, and va_arg, we can create functions that accept a variable number of arguments and perform operations on them effectively.

I hope this introduction provides a good starting point for understanding va_list and its associated macros in C programming.
