/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarbone <mcarbone@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:06:07 by mcarbone          #+#    #+#             */
/*   Updated: 2023/03/15 19:02:00 by mcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//ciao
int	ft_printchar(char s)
{
	return (write(1, &s, 1));
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

int	ft_formats(va_list *args, char c, int *sum)
{
	if (c == 's')
		return (ft_printstr(va_arg(*args, char *)));
	if (c == '%')
		return (ft_printchar('%'));
	if (c == 'd' || c == 'i')
		return (ft_printnbr(va_arg(*args, int), sum));
	return (0);
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
			sum += ft_formats(&args, str[++i], &sum);
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
	char *c = "ciaoooooooooooooooooooo";
	//printf("%i", ft_printf("%s%s", c, c));
	//printf("%i", printf("ciao\n"));
	//printf("%d", ft_printf("ciao\n"));

	ft_printf("%d", printf("%s", c));
	//printf("%d", ft_printf("%%"));
	//ft_printf("%s", NULL);
	//s
	//ft_printf("%d", printf("%d/", a));
	//ft_printf("%d", a);
}

/*
* 
    1.
		ft_printf("ciao")
			res: "ciao"

*/
