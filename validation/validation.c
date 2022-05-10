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
	int	i;
	int	duplicate_search;

	if (argc == 1) {
		exit(0);
	}
	i = 1;
	while (argv[i])
	{
		if (!validate_arg(argv[i]))
			fatal();
		duplicate_search = i + 1;
		// printf("%d %d %d\n", i, duplicate_search, argc);
		// printf("%s\n", argv[duplicate_search]);
		while (duplicate_search < argc)
		{
			if (is_str_equal(argv[i], argv[duplicate_search]))
				fatal();
			duplicate_search++;
		}
		i++;
	}
}

