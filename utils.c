/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarbone <mcarbone@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:54:45 by mcarbone          #+#    #+#             */
/*   Updated: 2023/03/15 18:37:01 by mcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnbr(int nbr, int *sum)
{
	if (nbr == -2147483648)
		*sum += write(1, "-2147483648", 11);
	if (nbr < 0)
	{
		ft_printchar('-');
		nbr *= -1;
		(*sum)++;
	}
	if (nbr > 9)
		ft_printnbr(nbr / 10, sum);
	ft_printchar((nbr % 10) + '0');
	(*sum)++;
}
