#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_list
{
	struct s_list	*next;
	int				value;
}	t_list;

typedef struct	s_stacks
{
	t_list	**a;
	t_list	**b;
}	t_stacks;


int		ft_atoi(char *s);
t_list	*new(int value);
t_list	*last(t_list *list);
void	add_back(t_list **lst, t_list *new);
t_list	**new_list();
void	fatal();
int		not_numeric(char *s);
int		not_int_limits(char *s);
void	validate_inputs(int argc, char **argv);
int		is_str_equal(char *a, char *b);

#endif