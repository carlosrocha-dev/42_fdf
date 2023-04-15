/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:30:48 by caalbert          #+#    #+#             */
/*   Updated: 2022/08/22 02:48:37 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	return_unsigned(unsigned int c)
{
	int	size;

	size = 0;
	if (c >= 10)
	{
		size += return_unsigned(c / 10);
		size += return_unsigned(c % 10);
	}
	if (c < 10)
		size += return_char(c +48);
	return (size);
}
