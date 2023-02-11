/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:55:01 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/11 20:34:49 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_row(char *str)
{
	int		i;
	char	*rt;
	int		len;

	printf("hit\n");
	len = ft_strlen(str) - 1; //len of str without \n
	rt = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	//printf("hit %s, %d \n", str, len);
	while (i < len)
	{
		rt[i] = str[i];
		i++;
		//printf("hit %d\n", i);
	}
	rt[i] = '\0';
	//printf("hit %s %d\n", rt, i);
	return (rt);
}

int	is_pec(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C')
		return (1);
	return (0);
}

void	printmap(char **map, int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			printf("%c",map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

