#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>



void	fill_init_stack(t_list **stack_a, int argc, char **argv)
{
	int	i;


	i = 1;
	(*stack_a)->value = ft_atoi(argv[0]);
	while (i < argc - 1)
	{
		add_back(stack_a, new(ft_atoi(argv[i])));
		i++;
	}
}


t_stacks	*new_stacks(int argc, char **argv)
{
	t_stacks	*new;

	new = (t_stacks *)malloc(sizeof(t_stacks));
	if (!new)
		return (NULL);
	new->a = new_list();
	if (!new->a)
		return (NULL);
	fill_init_stack(&new->a, argc, argv);
	// new->b = new_list();
	// if (!new->b)
	// 	return (NULL);
	return (new);
}