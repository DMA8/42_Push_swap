#include <stdlib.h>
#include <stdio.h>
#include "../push_swap.h"

int		validate_arg(char *arg)
{
	if (not_numeric(arg) || not_int_limits(arg))
		return 0;
	return 1;
}

void	validate_inputs(int argc, char **argv)
{
	int		i;
	int		duplicate_search;
	char	**my_args;

	i = 1;
	my_args = argv;
	if (argc == 1)
		exit(0);
	else if (argc == 2)
	{
		my_args = ft_split(argv[1], ' ');
		i = 0;
	}
	while (my_args[i])
	{
		if (!validate_arg(my_args[i]))
			fatal();
		duplicate_search = i + 1;
		while (duplicate_search < argc)
		{
			if (is_str_equal(argv[i], argv[duplicate_search]))
				fatal();
			duplicate_search++;
		}
		i++;
	}
}

