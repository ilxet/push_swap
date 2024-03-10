/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:13:24 by aadamik           #+#    #+#             */
/*   Updated: 2024/03/07 18:37:48 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

long long	ft_atoi(const char *str)
{
	long long	nb;
	long long	i;
	long long	sign;

	nb = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = 10 * nb + str[i] - '0';
		i++;
	}
	return (nb * sign);
}

// int main ()
// {
// 	printf("%d\n%d\n", atoi("  --324abs432"), ft_atoi("  --324abs432"));
// 	return (0);
// }