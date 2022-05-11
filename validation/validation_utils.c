/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:22:23 by syolando          #+#    #+#             */
/*   Updated: 2022/05/11 22:30:14 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../push_swap.h"
#include <unistd.h>

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

void	fatal(void)
{
	ft_putstr("Error\n");
	exit(1);
}

int	not_numeric(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-')
		i = 1;
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9'))
		{
			i++;
			continue ;
		}
		return (1);
	}
	return (0);
}

int	is_str_equal(char *a, char *b)
{
	int	i;

	i = 0;
	if (ft_strlen(a) != ft_strlen(b))
		return (0);
	while (a[i])
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_len(char **c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}
