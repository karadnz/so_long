/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:48:57 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/18 17:23:22 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *) b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}

static void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

static int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str[13];
	int		is_neg;
	int		len;

	is_neg = (n < 0);
	ft_bzero(str, 13);
	if (n == 0)
		str[0] = '0';
	len = 0;
	while (n != 0)
	{
		str[len++] = '0' + ft_abs(n % 10);
		n = (n / 10);
	}
	if (is_neg)
		str[len] = '-';
	else if (len > 0)
		len--;
	while (len >= 0)
		write(fd, &str[len--], 1);
}
