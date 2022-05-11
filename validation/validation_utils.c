#include <stdlib.h>
#include <stdio.h>
#include "../push_swap.h"

void	fatal()
{
	printf("Error\n");
	exit(1);
}

int		not_numeric(char *s)
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
			continue;
		}
		return (1);
	}
	return (0);
}



int		is_str_equal(char *a, char *b)
{
	int i;

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