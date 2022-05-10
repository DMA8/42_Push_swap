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

int main(int argc, char **argv)
{
	t_stacks	*stacks;

	validate_inputs(argc, argv);
	stacks = new_stacks(argc, &argv[1]);
	sort(stacks);
	exit(0);
}

