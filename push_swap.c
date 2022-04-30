#include <stdio.h>
#include "push_swap.h"
/*
1. валидация входных данных - дубликаты, число больше инта, вход не инт

2. заполнение стека А
3. сортировка
4. заменить printf
*/

int main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = new_stacks(argc, &argv[1]);
	while ((*(stacks->a)) != NULL)
	{
		printf("%d\n", (*(stacks->a))->value);
		(*(stacks->a)) = (*(stacks->a))->next;
	}
	printf("%p", stacks);
	validate_inputs(argc, argv);
}

