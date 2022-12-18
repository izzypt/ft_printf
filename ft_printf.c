/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:56:14 by smagalha          #+#    #+#             */
/*   Updated: 2022/12/18 21:04:48 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	handle_specifier(char specifier, va_list argumento)
{
	int	len;

	len = 0;
	if (!argumento)
		return (0);
	if (specifier == 'c')
		ft_putchar_fd(va_arg(argumento, int), 1);
	if (specifier == 's')
		ft_putstr_fd(va_arg(argumento, char *), 1);
	if (specifier == 'i' || specifier == 'd')
		ft_putnbr_fd(va_arg(argumento, int), 1);
	if (specifier == 'x' || specifier == 'X')
		ft_puthex(va_arg(argumento, unsigned int), specifier);
	if (specifier == 'p')
		ft_putaddress(va_arg(argumento, void *));
	if (specifier == '%')
		ft_putchar_fd('%', 1);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	argumentos;
	int 	i;
	int 	len;

	len = 0;
	i = 0;
	va_start(argumentos, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			handle_specifier(s[i], argumentos);
		}
		else
			write(1, &s[i], 1);
		i++;
	}
	va_end(argumentos);

	return (len);
}

int main(void)
{
    int num = 42;
    int *pointer1 = &num;

    ft_printf("Print pointer address: %p\n", (void*)pointer1);

    return 0;
}
/*
//cspdiuxX%


c = character
s = string
p = Pointer address
d = signed decimal integer
i = integer
u = Unsigned decimal integer
x = Unsigned hexadecimal integer
X = Unsigned hexadecimal integer (capital letters)
% = Character

*/