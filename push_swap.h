#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#define SA	11
#define SB	12
#define SS	13

#define PA	21
#define PB	22

#define RA	31
#define RB	32
#define RR	33

#define RRA	41
#define RRB	42
#define RRR	43

typedef struct	s_list
{
	struct s_list	*next;
	int				value;
}	t_list;

typedef struct	s_stacks
{
	t_list	*a;
	t_list	*b;
}	t_stacks;


void	command_handler(t_stacks *stacks, int cmd);
void	fill_init_stack(t_list **stack_a, int argc, char **argv);

t_list	*new(int value);
t_list	*last(t_list *list);
void	add_back(t_list **lst, t_list *new);
void	add_front(t_list **lst, t_list *new);
t_list	*new_list();
t_stacks	*new_stacks(int argc, char **argv);

void	fatal();
int		not_numeric(char *s);
int		not_int_limits(char *s);
void	validate_inputs(int argc, char **argv);
int		is_str_equal(char *a, char *b);
int		ft_strlen(char *s);
int		ft_atoi(char *s);

#endif