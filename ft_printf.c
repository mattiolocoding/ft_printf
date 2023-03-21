/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarbone <mcarbone@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:06:07 by mcarbone          #+#    #+#             */
/*   Updated: 2023/03/20 19:07:37 by mcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char s)
{
	write(1, &s, 1);
	return (1);
}

int	ft_printstr(char *str)
{	
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		ft_printchar(str[i++]);
	return (i);
}

int	ft_formats(const char *str, int i, va_list *args)
{
	int	sum;

	sum = 0;
	if (str[i]== 's')
		sum += ft_printstr(va_arg(*args, char *));
	else if (str[i] == '%')
		sum += ft_printchar('%');
	else if (str[i] == 'd' || str[i] == 'i')
		sum += ft_printnbr(va_arg(*args, int), 0);
	return (sum);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		sum;

	i = 0;
	sum = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			sum += ft_formats(str, ++i, &args);
			i++;
		}
		else
			sum += ft_printchar(str[i++]);
	}
	va_end(args);
	return (sum);
}

int main()
{
	int a = -210;
//	char *c = "ciaoooooooooooooooooooo";
	//printf("%i", ft_printf("%s%s", c, c));
	//printf("%i", printf("ciao\n"));
	//printf("%d", ft_printf("ciao\n"));

//	ft_printf("%d", printf("%s", c));
	//printf("%d", ft_printf("%%"));
	//ft_printf("%s", NULL);
	//s
	printf("%d", ft_printf("%d", a));
	//ft_printf("%d", a);
}

/*
* 
    1.
		ft_printf("ciao")
			res: "ciao"

*/
