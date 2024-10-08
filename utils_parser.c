/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:09:17 by sidiallo          #+#    #+#             */
/*   Updated: 2024/10/08 12:19:53 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static long long	atol_sign(const char **nptr)
{
	long long	sign;
	long long	i;

	sign = 1;
	i = 0;
	while ((*nptr)[i] == ' ' || ((*nptr)[i] >= 9 && (*nptr)[i] <= 13))
		i++;
	if ((*nptr)[i] == '+')
		i++;
	if ((*nptr)[i] == '-')
	{
		sign = -1;
		i++;
	}
	*nptr += i;
	return (sign);
}

static long long	atol_convert(const char *nptr, long long sign)
{
	long long	res;
	long long	i;

	res = 0;
	i = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10 + nptr[i] - '0');
		if (res > 2147483648)
			return (2147483650);
		i++;
	}
	res = res * sign;
	if (res > 2147483647 || res < -2147483648)
		return (2147483650);
	return (res);
}

long long	ft_atol(const char *nptr)
{
	long long	sign;

	sign = atol_sign(&nptr);
	return (atol_convert(nptr, sign));
}
