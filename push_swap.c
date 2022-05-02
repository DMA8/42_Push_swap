#include <stdio.h>
#include "push_swap.h"
#include <stdlib.h>
/*
1. валидация входных данных - дубликаты, число больше инта, вход не инт
2. заполнение стека А
2.1 базовые операции sa sb ra rb rra rrb rrr...

3. сортировка
4. заменить printf
*/

// void	print_list(t_list *a)
// {
// 	t_list	*ptr;

// 	if (!a)
// 	{
// 		printf("can not print empy list!\n");
// 		return ;
// 	}
// 	ptr = a;
// 	while (ptr->next != NULL)
// 	{
// 		printf("%d\n", ptr->value);
// 		ptr = ptr->next;
// 	}
// 	printf("%d\n", ptr->value);
// }

void	print_list(t_list *a)
{
	if (!a)
	{
		printf("can not print empy list!\n");
		return ;
	}
	while (a->next != NULL)
	{
		printf("val: %d indx: %d top_steps:%d \n", a->value, a->indx, a->top_steps);
		a = a->next;
	}
	printf("val: %d indx: %d top_steps:%d \n", a->value, a->indx, a->top_steps);

}

int main(int argc, char **argv)
{
	t_stacks	*stacks;

	validate_inputs(argc, argv);
	stacks = new_stacks(argc, &argv[1]);
	// printf("before stack a\n");
	// print_list((stacks->a));
	// printf("before stack b\n");
	// print_list((stacks->b));

	sort(stacks);
	// printf("\nstack a is: \n");
	// print_list((stacks->a));
	// printf("\nstack b is: \n");
	// print_list((stacks->b));


	exit(0);
}

