/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarbone <mcarbone@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:54:45 by mcarbone          #+#    #+#             */
/*   Updated: 2023/03/20 19:08:36 by mcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int nbr, int j)
{
	if (nbr == -2147483648)
		return (ft_printstr("-2147483648"));
	if (nbr < 0)
	{
		j += ft_printchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
		ft_printnbr(nbr / 10, j);
	j += ft_printchar((nbr % 10) + '0');
	return (j);
}
