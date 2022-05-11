#include <stdio.h>
#include "push_swap.h"
#include <stdlib.h>
/*
1. валидация входных данных - дубликаты, число больше инта, вход не инт
2. заполнение стека А
2.1 базовые операции sa sb ra rb rra rrb rrr...

3. сортировка
3.1 в стеке А оставлять максимальную восходящую последовательность


4. заменить printf
*/


void	print_list(t_list *a)
{
	if (!a)
	{
		printf("can not print empy list!\n");
		return ;
	}
	while (a->next != NULL)
	{
		printf("val: %d indx: %d top_steps:%d score: %d\n", a->value, a->indx, a->top_steps, a->score);
		a = a->next;
	}
	printf("val: %d indx: %d top_steps:%d score %d \n", a->value, a->indx, a->top_steps, a->score);

}

int	ft_len(char **c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		**my_args;

	validate_inputs(argc, argv);
	if (argc == 2)
	{
		my_args =  ft_split(argv[1], ' ');
		stacks = new_stacks(my_args);
	}
	else 
		stacks = new_stacks(&argv[1]);

	sort(stacks);
	// print_list(stacks->a);
	// print_list(stacks->b);

	exit(0);
}

