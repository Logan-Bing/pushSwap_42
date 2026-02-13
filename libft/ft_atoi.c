/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llugez <llugez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:18:31 by llugez            #+#    #+#             */
/*   Updated: 2026/02/06 20:01:18 by llugez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	nb = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (ERROR_VALUE);
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	nb *= sign;
	if (nb < INT_MIN || nb > INT_MAX)
		return (ERROR_VALUE);
	return (nb);
}
// int	main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (1);
// 	int my_res = ft_atoi(argv[1]);
// 	int real_res = atoi(argv[1]);
// 	printf("mine : %d\n", my_res);
// 	printf("real : %d\n", real_res);
// }